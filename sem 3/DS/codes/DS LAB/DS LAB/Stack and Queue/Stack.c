#include<stdio.h>
#include<stdlib.h>

#define size 5

void push(int stack[],int* top,int data) {
    if(*(top) > size ) {
        printf("Stack OverFlow \n ");
    }
    else {
        *(top)++;
        stack[*(top)]=data;
    }
}

int pop(int stack[],int* top) {
    if(*(top) == -1 ) {
        printf("Stack Under flow \n");
        return -1;
    }
    else {
        int temp=stack[*(top)];
        *(top)--;
        return temp;
    }
}

void peek(int stack[],int* top) {
    if(*(top) != -1 ) {
        printf("%d ",stack[*(top)]);
    }
    else {
        printf("Stack is Empty \n");
    }
}

void isEmpty(int stack[],int* top) {

    if(*top == -1 ) {
        printf("Stack is Empty ");
    }
    else {
        printf("Stack is Not Empty \n");
    }

}

void Display(int stack[]) {
    for(int i=0;i<size;i++) {
        printf("%d  ",stack[i]);
    }
    printf("\n\n");
}

int main() {

    int top=1;
    int* stack=malloc(size*sizeof(int));
  
    int ans;

    isEmpty(stack,&top);


    push(stack,&top,10);
    
    
    push(stack,&top,20);
    push(stack,&top,30);
    push(stack,&top,40);
  
    
    push(stack,&top,50);
    push(stack,&top,60);
    
    isEmpty(stack,&top);

    return 0;
}