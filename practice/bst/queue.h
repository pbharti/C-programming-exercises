#include <stdbool.h>
#include <stdio.h>
#define MAX_QUEUE_SIZE 100

typedef struct {
    void* data[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue_t;

void InitQueue(Queue_t* queue)
{
    // deque
    queue->front = -1;
    // enqueue
    queue->rear = 0;
}

bool IsQueueEmpty(Queue_t* queue)
{
    if (queue->front == queue->rear - 1)
        return true;
    return false;
}

bool IsQueueFull(Queue_t* queue)
{
    if (queue->rear == MAX_QUEUE_SIZE)
        return true;
    return false;
}

void Enqueue(Queue_t* queue, void* data)
{
    if (IsQueueFull(queue)) {
        printf("Queue is Full\n");
        return;
    }
    queue->data[queue->rear++] = data;
}

void* Dequeue(Queue_t* queue)
{
    if (IsQueueEmpty(queue)) {
        printf("Queue is empty\n");
        return NULL;
    }
    return queue->data[queue->front--];
}

void* PeekQueue(Queue_t* queue)
{
    if (IsQueueEmpty(queue)) {
        printf("Queue is empty\n");
        return NULL;
    }
    return queue->data[queue->rear];
}
