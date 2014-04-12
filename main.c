#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "queue.h"

int main()
{
    QUEUE *queue = queue_init();

    if(!queue)
        printf("queue is null\n");
    
    int i = 0;
    for(i = 0;i<5;i++)
    {
        QUEUE_ITEM *tmp = malloc(sizeof(QUEUE_ITEM));
        tmp->id = i;
        tmp->data = (i*i);

        enqueue(queue, tmp);
    }
    
    for(i = 0;i<5;i++)
    {
        QUEUE_ITEM *tmp;
        tmp = dequeue(queue);
        printf("Item id: %d, Item data: %d\n", tmp->id, tmp->data);
    }

    QUEUE_ITEM *item = malloc(sizeof(QUEUE_ITEM));
    
    return 0;
}
