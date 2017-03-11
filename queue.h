#ifndef __QUEUE_H__
#define __QUEUE_H__		1

typedef struct __queue { 
	char element[16];
	struct __queue *next;
}queue;

queue *create_queue(void);
void push_queue(queue *q, const char *elem);
queue pop_queue(queue **q);

#endif
