/*
 * Copyright (C) 2020 Weiping He
 * Author(s): Weiping He
 *
 * License: GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
 * Please take look heweiping6.test/LICENSE for whole information.
 *
 * */


#include<iostream>

using namespace std;


int main(void) {
  string s1 = "Abc";
  string s2 = "ABC";

  if (s1 != s2) {
    cout << "s1[" << s1 << "] != s2[" << s2 << "]" << endl;
  } else {
    cout << "s1[" << s1 << "] == s2[" << s2 << "]" << endl;
  }

  if (s1.compare(s2) == 0) {
    cout << "s1[" << s1 << "], compare s2[" << s2 << "]" << endl;
  } else {
    cout << "s1[" << s1 << "], !!!compare s2[" << s2 << "]" << endl;
  }
  cout << "s1 size: " << s1.size() << endl;
  cout << "s1 length: " << s1.length() << endl;
  cout << "s1 capacity: " << s1.capacity() << endl;
  cout << "s1 max_size: " << s1.max_size() << endl;
  cout << "s1 at:[" << 1 << "]" << s1.at(1) << endl;
  cout << "s1 before push_back()" << s1;
  s1.push_back('D');
  cout << "; s1 after push_back()" << s1 << endl;
  return (0);
}

