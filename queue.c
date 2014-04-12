#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

QUEUE *queue_init(void)
{
    QUEUE *q = malloc(sizeof(QUEUE));
    if(!q)
        return NULL;
    pthread_mutex_init(&(q->mutex_read), NULL);
    pthread_mutex_init(&(q->mutex_write), NULL);
    
    q->first = NULL;
    q->last = NULL;

    return q;
}

void enqueue(QUEUE *queue, QUEUE_ITEM *item)
{
    if(0 == isEmpty(queue))
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
}

QUEUE_ITEM *dequeue(QUEUE *queue)
{
    QUEUE_ITEM *tmp;
    tmp = queue->first;
    queue->first = queue->first->next;

    return tmp;
}

int queue_size(QUEUE *queue)
{
    return 0;
}

int isEmpty(QUEUE *queue)
{
    if((NULL == queue->last) && (NULL == queue->first))
        return 0;
    else
        return 1;
}
