
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
	queue *newq, *last;

	newq = (queue*)malloc(sizeof(queue));
	strcpy(newq->element, elem);
	newq->next = NULL;

	last = q;
	while( last )
		last = last->next;
	last->next = newq;
}

queue pop_queue(queue **q)
{
	queue head = **q;
	head.next = NULL;
	free(*q);
	*q = (*q)->next;

	return head;
}
