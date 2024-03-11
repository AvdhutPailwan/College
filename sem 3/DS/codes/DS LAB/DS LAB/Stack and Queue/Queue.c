#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define size 5

int front=-1;
int rear=-1;
int queue[size];

void enQueue(int data) {
    if(front == -1 && rear == -1 ) {
        front=rear=0;
        queue[rear]=data;
    }
    else if (front == (rear+1)%size ) {
        printf("Queue is FULL \n");
    }
    else {
        rear=(rear+1)%size;
        queue[rear]=data;
    }
}

void deQueue() {

    if(front == -1 && rear == -1 ) {
        printf("Queue is Empty \n");
    }
    else if (front == rear) {
        front=rear=-1;
    }
    else {
        printf("Removed Element is %d ",queue[front]);
        front=(front+1)%size;
    }

}

void display() {
    int i=front;
    if(front== -1 && rear == -1) {
        printf("Queue is Empty \n");
    }
    else {
        printf("Queue is: ");
        while( i != rear ) {
            printf("%d ",queue[i]);
            i=(i+1)%size;
        }
        printf("%d \n",queue[rear]);
    }
}

int main() {

    int choice;

    bool keepGoing=true;

    while(keepGoing){
        printf("Please Select the following \n");
        printf("1) enQueue \n");
        printf("2) deQueue \n");
        printf("3) Display \n");
        scanf("%d",&choice);

        switch (choice) {
            case 1:
                int data;
                printf("Enter Data: ");
                scanf("%d",&data);
                enQueue(data);
                break;
            case 2:
                deQueue();
                break;
            case 3:
                display();
                break;
            default :
                keepGoing=false;
                break;
        }
    }



    return 0;
}