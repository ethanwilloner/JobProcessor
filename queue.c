#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

QUEUE *queue_init(void)
{
    QUEUE *q = malloc(sizeof(QUEUE));
    if(!q)
        return NULL;
    pthread_mutex_init(&(q->mutex), NULL);
    
    q->first = NULL;
    q->last = NULL;

    return q;
}

void enqueue(QUEUE *queue, QUEUE_ITEM *item)
{
    if(0 == queue->size)
    {
        queue->first = item;
        queue->last = item;
        item->next = NULL;
    }
    else
    {
        queue->last->next = item;
        item->next = NULL;
        queue->last = item;
    }
    queue->size++;    
}

QUEUE_ITEM *dequeue(QUEUE *queue)
{
    QUEUE_ITEM *tmp;
    tmp = queue->first;
    if(NULL == queue->first)
        return NULL;
    else
    {
        queue->first = queue->first->next;
        queue->size--;
        return tmp;
    }
}
