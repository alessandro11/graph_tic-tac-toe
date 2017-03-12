
#include <stdlib.h>
#include <string.h>
#include "queue.h"

queue *create_queue(void)
{
	queue *q;

	q = (queue*)malloc(sizeof(queue));
	memset(q, 0, sizeof(queue));

	return q;
}

void push_queue(queue *q, const char *elem)
{
	queue *newq, *last, *before_last;

	newq = (queue*)malloc(sizeof(queue));
	strcpy(newq->element, elem);
	newq->next = NULL;

	last = q;
	while( last ) {
		before_last = last;
		last = last->next;
	}
	before_last->next = newq;
}

queue pop_queue(queue *q)
{
	queue *tmp;
	queue head = {0};

	if( !q->next )
		return head;

	head = *(q->next);
	head.next = NULL;
	tmp = q->next;
	q->next = q->next->next;
	free(tmp);

	return head;
}
