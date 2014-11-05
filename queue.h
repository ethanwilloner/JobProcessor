typedef struct _queue_item
{
    int id;
    int data;
    struct _queue_item *next;
}QUEUE_ITEM;

typedef struct
{
    QUEUE_ITEM *first;
    QUEUE_ITEM *last;
    pthread_mutex_t mutex; 
    int size;
}QUEUE;

QUEUE *queue_init(void);
void enqueue(QUEUE *queue, QUEUE_ITEM *item);
QUEUE_ITEM *dequeue(QUEUE *queue);
