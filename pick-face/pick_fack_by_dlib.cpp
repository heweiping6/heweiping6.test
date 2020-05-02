/*
 * Copyright (C) 2020 Weiping He
 * Author(s): Weiping He
 *
 * License: GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
 * Please take look heweiping6.test/LICENSE for whole information.
 *
 * */


#include <iostream>
#include <stdio.h>

#include <dlib/image_processing.h>
#include <dlib/image_io.h>
#include <dlib/data_io.h>
#include <dlib/opencv.h>
#include <opencv2/opencv.hpp>


using namespace dlib;
using namespace std;
static long gImageIndex = 0;


void saveImage(cv::Mat &myMat, rectangle &r) {
  cv::Rect myRect(r.left(), r.top(), r.width(), r.height());
  cv::Mat roiMat = myMat(myRect);
  char name[256];
  sprintf(name, "myDataSet_%ld.jpg", gImageIndex);
  cv::imwrite(name, roiMat);
  std::cout << "image index <" << gImageIndex << "> !" << std::endl;
  gImageIndex++;
}


bool validRect(cv::Mat &img, rectangle &r) {
  if (r.top() < 0) {
    return false;
  }
  if (r.left() < 0) {
    return false;
  }

  if (r.width() <= 0) {
    return false;
  }

  if (r.height() <= 0) {
    return false;
  }

  if (r.left() + r.width() > img.cols) {
    return false;
  }

  if (r.top() + r.height() > img.rows) {
    return false;
  }
  return true;
}


template<typename image_type>
void pickImage(image_type &imageType,
               std::vector<full_object_detection> &fullObjects) {
  int iRet = 0;
  if (imageType.size() <= 0) {
    return;
  }

  if (fullObjects.size() <= 0) {
    return;
  }
  cv::Mat myMat = toMat(imageType);

  for (int i = 0; i < fullObjects.size(); i++) {
    rectangle &rect1 = fullObjects[i].get_rect();
    iRet = validRect(myMat, rect1);
    if (iRet == true) {
      saveImage(myMat, rect1);
      break;
    }
  }
}


template<typename array_type>
std::vector<std::vector<rectangle> > me_load_image_dataset(
    array_type &images,
    std::vector<std::vector<full_object_detection> > &object_locations,
    const image_dataset_file &source, std::vector<std::string> &parts_list) {
  typedef typename array_type::value_type image_type;
  parts_list.clear();
  images.clear();
  object_locations.clear();

  using namespace dlib::image_dataset_metadata;
  dataset data;
  load_image_dataset_metadata(data, source.get_filename());

  // Set the current directory to be the one that contains the
  // metadata file. We do this because the file might contain
  // file paths which are relative to this folder.
  locally_change_current_dir chdir(
      get_parent_directory(file(source.get_filename())));

  std::set<std::string> all_parts;

  // find out what parts are being used in the dataset.  Store results in all_parts.
  for (unsigned long i = 0; i < data.images.size(); ++i) {
    for (unsigned long j = 0; j < data.images[i].boxes.size(); ++j) {
      if (source.should_load_box(data.images[i].boxes[j])) {
        const std::map<std::string, point> &parts = data.images[i].boxes[j]
            .parts;
        std::map<std::string, point>::const_iterator itr;

        for (itr = parts.begin(); itr != parts.end(); ++itr) {
          all_parts.insert(itr->first);
        }
      }
    }
  }

  // make a mapping between part names and the integers [0, all_parts.size())
  std::map<std::string, int> parts_idx;
  for (std::set<std::string>::iterator i = all_parts.begin();
      i != all_parts.end(); ++i) {
    parts_idx[*i] = parts_list.size();
    parts_list.push_back(*i);
  }

  ///std::vector<std::vector<rectangle> > ignored_rects;
  ///std::vector<rectangle> ignored;
  //    image_type img;
  std::vector < full_object_detection > object_dets;

  for (unsigned long i = 0; i < data.images.size(); ++i) {
    double min_rect_size = std::numeric_limits<double>::infinity();
    object_dets.clear();
    ///ignored.clear();
    for (unsigned long j = 0; j < data.images[i].boxes.size(); ++j) {
      if (source.should_load_box(data.images[i].boxes[j])) {
        if (data.images[i].boxes[j].ignore) {
          //  ignored.push_back(data.images[i].boxes[j].rect);
        } else {
          std::vector < point
              > partlist(parts_idx.size(), OBJECT_PART_NOT_PRESENT);

          // populate partlist with all the parts present in this box.
          const std::map<std::string, point> &parts = data.images[i].boxes[j]
              .parts;
          std::map<std::string, point>::const_iterator itr;
          for (itr = parts.begin(); itr != parts.end(); ++itr) {
            partlist[parts_idx[itr->first]] = itr->second;
          }

          object_dets.push_back(
              full_object_detection(data.images[i].boxes[j].rect, partlist));
          min_rect_size = std::min<double>(
              min_rect_size, object_dets.back().get_rect().area());
        }
      }
    }

    if (!source.should_skip_empty_images() || object_dets.size() != 0) {
      image_type img;
      load_image(img, data.images[i].filename);
      if (object_dets.size() != 0) {
        // if shrinking the image would still result in the smallest box being
        // bigger than the box area threshold then shrink the image.
        while (min_rect_size / 2 / 2 > source.box_area_thresh()) {
          pyramid_down < 2 > pyr;
          pyr(img);
          min_rect_size *= (1.0 / 2.0) * (1.0 / 2.0);
          for (auto &&r : object_dets) {
            r.get_rect() = pyr.rect_down(r.get_rect());
            for (unsigned long k = 0; k < r.num_parts(); ++k)
              r.part(k) = pyr.point_down(r.part(k));
          }
          ///                    for (auto&& r : ignored)
          ///                    {
          ///                        r = pyr.rect_down(r);
          ///                    }
        }
        while (min_rect_size * (2.0 / 3.0) * (2.0 / 3.0)
            > source.box_area_thresh()) {
          pyramid_down < 3 > pyr;
          pyr(img);
          min_rect_size *= (2.0 / 3.0) * (2.0 / 3.0);
          for (auto &&r : object_dets) {
            r.get_rect() = pyr.rect_down(r.get_rect());
            for (unsigned long k = 0; k < r.num_parts(); ++k)
              r.part(k) = pyr.point_down(r.part(k));
          }
          ///for (auto&& r : ignored)
          ///{
          ///   r = pyr.rect_down(r);
          ///}
        }
      }
      //images.push_back(img);
      //object_locations.push_back(object_dets);
      pickImage(img, object_dets);
      //ignored_rects.push_back(ignored);
    }
  }

  std::vector < std::vector<rectangle> > ignored_rects;
  return ignored_rects;
}


int main(int argc, char **argv) {
  if (argc <= 2) {
    std::cout << "u xml" << std::endl;
    return 0;
  }

  if (argc == 3) {
    gImageIndex = atol(argv[2]);
  }
  dlib::array < array2d<bgr_pixel> > images;
  std::vector < std::vector<full_object_detection> > faces;
  dlib::image_dataset_file imgsets = image_dataset_file(argv[1]);
  std::vector<std::string> parts_list;

  me_load_image_dataset(images, faces, imgsets, parts_list);
  return 0;
}
