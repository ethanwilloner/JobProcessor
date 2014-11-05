#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "queue.h"

void add_to_list(void *args);

struct thread_args {
    QUEUE *queue;
    QUEUE_ITEM *item;
};

int main()
{
    QUEUE *queue = queue_init();

    if(!queue)
        printf("queue is null\n");
    /*
    int i = 0;
    for(i = 0;i<5;i++)
    {
        QUEUE_ITEM *tmp = malloc(sizeof(QUEUE_ITEM));
        tmp->id = i;
        tmp->data = (i*i);

        enqueue(queue, tmp);
    }
    
    printf("Queue Size: %d\n", queue->size);
    
    for(i = 0;i<5;i++)
    {
        QUEUE_ITEM *tmp;
        tmp = dequeue(queue);
        if(NULL == tmp)
            printf("end of queue\n");
        else
            printf("Item id: %d, Item data: %d\n", tmp->id, tmp->data);
    }
    */
    int params[10] = {1,2,3,4,5,6,7,8,9,10};
    int i = 0;
    pthread_t threads[10];
    for(i=0;i<10;i++){
        struct thread_args *args = malloc(sizeof(struct thread_args));
        QUEUE_ITEM *item = malloc(sizeof(QUEUE_ITEM));
        item->data = params[i];
        
        args->queue = queue;
        args->item = item;

        pthread_create(&threads[i],
                        NULL,
                        (void *)add_to_list,
                        (void *)args);
    }

    for(i=0;i<10;i++){
        pthread_join(threads[i], NULL);
    }
    return 0;
}

void add_to_list(void *args){
    struct thread_args *args2 = args;
    pthread_mutex_lock(&(args2->queue->mutex));
    printf("Value received: %d\n", args2->item->data);
    pthread_mutex_unlock(&(args2->queue->mutex));
    return;
}
