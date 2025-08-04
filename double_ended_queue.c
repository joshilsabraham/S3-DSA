#include <stdio.h>
#include <stdlib.h>
#define max 10

int dequeue[max];
int front=-1;
int rear=-1;

void appendFront(){
    if (rear == max - 1) {
        printf("Overflow\n");
    }
    else {
        int value;
	printf("Enter the number: ");
	scanf("%d", &value);
        if (front == -1) { // Queue was empty
	    front = 0;
	} else{
		front--;
	}
	dequeue[front] = value;
    }
}

void deleteFront() {
    if (front == -1 || front > rear) {
        printf("Underflow\n");
    }
    else {
        printf("Deleted element is %d\n", dequeue[front]);
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front++; 
        }
    }
}

void appendRear(){
	if (rear == max - 1) {
		printf("Overflow\n");
	    }
	    else {
		int value;
		printf("Enter the number: ");
		scanf("%d", &value);
		if (front == -1) { // Queue was empty
		    front = 0;
		}
		rear++;
		dequeue[rear] = value;
	    }
}

void deleteRear(){
	if (front == -1 || front > rear) {
        printf("Underflow\n");
    }
    else {
        printf("Deleted element is %d\n", dequeue[rear]);
        if (front == rear) {
            front = rear = -1;
        }
        else {
            rear--; 
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
    		printf("%d\t",dequeue[i]);
    	}
    	printf("\n");
    }
}	

void menu(){
	int choice;
	printf("\n1. Insertion\n2. Deletion\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
	if(choice==1) {
		int insert;
		printf("\n1.Front\n2.Rear\n");
            	scanf("%d",&insert);
                if(insert==1){
                	appendFront();
                }
            	if(insert==2){
            		appendRear();
            	}
        }
        else if(choice==2) {
		int delete;
		printf("\n1.Front\n2.Rear\n");
            	scanf("%d",&delete);
                if(delete==1){
                	deleteFront();
                }
            	if(delete==2){
            		deleteRear();
            	} 
        }
        else if(choice==3){
                display();
        }
        else if(choice==4){
        	printf("Exiting...\n");
                exit(0);
        }
        else{
        	printf("Invalid choice\n");
        }
}
int main(){
	int n=0;
	while (n==0){
		menu();
	}
	return 0;
}
