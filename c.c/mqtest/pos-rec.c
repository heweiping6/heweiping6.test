/*
 * Copyright (C) 2020 Weiping He
 * Author(s): Weiping He
 *
 * License: GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
 * Please take look heweiping6.test/LICENSE for whole information.
 *
 * */


#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <mqueue.h>
#include <unistd.h>
#include <poll.h>

#define MAX_MSG_SIZE 1024
#define MSG_Q_NAME    "/test1111"

typedef struct {
  int mtype;
  int seq;
  char d[200];
} msg_test;


int main(void) {
  mqd_t msgid;
  struct pollfd fds[1];
  int reval;
  char buff[MAX_MSG_SIZE];

  memset(&buff, 0x00, sizeof(msg_test));
  msgid = mq_open(MSG_Q_NAME, O_RDONLY, 0644);
  if ((mqd_t) -1 == msgid) {
    printf("Failed to create receive msg queue.\n");
    printf("Errno: %s\n", strerror(errno));
    return (1);
  }
  printf("Rec- msgid: %d.\n", msgid);

  fds[0].fd = msgid;
  fds[0].events = POLLIN;

  do {
    int res = poll(fds, 1, -1);
    if (res == -1) {
      if (errno == EINTR) {
        continue;
      }
      else {
        printf("Failed to poll, %s.", strerror(errno));
        break;
      }
    }

    if (fds[0].revents & POLLIN) {
      reval = mq_receive(msgid, buff, MAX_MSG_SIZE, 0);
      if (reval == -1) {
        printf("Read msg error %d %s\r\n", errno, strerror(errno));
      } else {
        printf("Read from msg queue %d bytes\r\n", reval);
      }
    }
  } while (1);

  return (0);
}

