#include <stdio.h>
#define MAX 5

struct Queue {
    int arr[MAX];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return (q->front == -1);
}

int isFull(struct Queue* q) {
    return ((q->rear + 1) % MAX == q->front);
}

void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue %d\n", value);
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % MAX;
        q->arr[q->rear] = value;
        printf("Enqueued %d\n", value);
    }
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue\n");
        return -1;
    } else {
        int value = q->arr[q->front];
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front = (q->front + 1) % MAX;
        }
        printf("Dequeued %d\n", value);
        return value;
    }
}

int peek(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        return q->arr[q->front];
    }
}

void displayQueue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    int i = q->front;
    printf("Queue elements: ");
    while (i != q->rear) {
        printf("%d ", q->arr[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", q->arr[q->rear]);
}

int main() {
    struct Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    displayQueue(&q);

    enqueue(&q, 60);

    dequeue(&q);
    displayQueue(&q);

    enqueue(&q, 60);
    displayQueue(&q);

    return 0;
}

