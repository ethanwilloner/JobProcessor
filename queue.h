typedef struct _queue_item
{
    int id;
    int data;
    struct _queue_item *next;
}QueueItem;

typedef struct
{
    QueueItem *first;
    QueueItem *last;
    pthread_mutex_t mutex; 
    int size;
}Queue;

Queue *queue_init(void);
void enqueue(Queue *queue, QueueItem *item);
QueueItem *dequeue(Queue *queue);
