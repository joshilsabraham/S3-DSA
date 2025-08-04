#include <stdio.h>
#define max 10

int queue[max];
int front=-1;
int rear=-1;

void enqueue() {
    if (rear == max - 1) {
        printf("Overflow\n");
        return;
    }

    int value;
    printf("Enter the number: ");
    scanf("%d", &value);

    if (front == -1) { // Queue was empty
        front = 0;
    }
    rear++;
    queue[rear] = value;
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Underflow\n");
    }
    else {
        printf("Deleted element is %d\n", queue[front]);
        
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front++; 
        }
    }
}

void display(){
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
    }
    else{
        printf("Queue elements: ");
    	for(int i=front;i<=rear;i++){
    		printf("%d\t",queue[i]);
    	}
    	printf("\n");
    }
}	

int main(){
	int choice;
	
	do {
        printf("\n1. Insertion\n2. Deletion\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break; 
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}
