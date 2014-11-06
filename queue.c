#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "queue.h"

Queue *queue_init(void)
{
    Queue *q = malloc(sizeof(Queue));
    if(!q)
        return NULL;
    pthread_mutex_init(&(q->mutex), NULL);
    
    q->first = NULL;
    q->last = NULL;

    return q;
}

void enqueue(Queue *queue, QueueItem *item)
{
    pthread_mutex_lock(&(queue->mutex));
    if(0 == queue->size)
    {
        queue->first = item;
        queue->last = item;
        item->next = NULL;
        queue->size++;
    }
    else
    {
        queue->last->next = item;
        item->next = NULL;
        queue->last = item;
        queue->size++;
    }
    pthread_mutex_unlock(&(queue->mutex));  

    return;
}

QueueItem *dequeue(Queue *queue)
{
    QueueItem *tmp;

    pthread_mutex_lock(&(queue->mutex));

    tmp = queue->first;
    if(NULL == queue->first){
        pthread_mutex_unlock(&(queue->mutex));  
        return NULL;
    }
    else {
        queue->first = queue->first->next;
        queue->size--;
        pthread_mutex_unlock(&(queue->mutex));  
        return tmp;
    }
}
