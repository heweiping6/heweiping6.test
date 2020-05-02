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
#define MAX_MSG_SIZE 1024

//Posix msg queue name definition
#define MSG_Q_NAME    "/test1111"


typedef struct {
  int mtype;
  int seq;
  char d[200];
} msg_test;


int main(void) {
  struct mq_attr attr;
  mqd_t msgid;

  /* initialize the queue attributes */
  attr.mq_flags = 0;
  attr.mq_maxmsg = 10;
  attr.mq_msgsize = MAX_MSG_SIZE;
  attr.mq_curmsgs = 0;

  /* create the message queue */
  msgid = mq_open(MSG_Q_NAME, O_CREAT | O_RDWR, 0644, &attr);
  if ((mqd_t) -1 == msgid) {
    printf("Failed to create send msg queue.\n");
    printf("Errno: %s\n", strerror(errno));
    return (1);
  }

  while (1) {
    int reval;
    msg_test msgS;
    char buf[1024];

    memset(&buf, 0x00, sizeof(buf));
    memset(&msgS, 0x00, sizeof(msg_test));
    msgS.mtype = 1;
    msgS.seq = 1;

    reval = mq_send(msgid, (char*) &msgS, sizeof(msg_test), 0);
    if (reval == -1) {
      printf("Message send error.\n");
      if (errno == EAGAIN) {
        printf("Message queue is full.\n");
      }
      return (2);
    }
    printf("Message send ok. \n");
    sleep(1);
#if 0
    reval = mq_receive(msgid, buf, MAX_MSG_SIZE, 0);
    if (reval == -1) {
      printf("Read msg error %d %s.\n", errno, strerror(errno));
    } else {
      printf("Read from msg queue %d bytes.\n", reval);
      break;
    }
#endif
  }
  return (0);
}

