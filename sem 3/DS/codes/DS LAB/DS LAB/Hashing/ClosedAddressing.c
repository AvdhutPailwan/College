#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node {
    int data;
    struct node* next;
};

void Insert(struct node* hash[],int size,int value) {

    struct node* newNode = malloc(sizeof(struct node));
    newNode->data=value;
    newNode->next=NULL;

    int key=value%size;

    if(hash[key] == NULL ) {
        hash[key] = newNode;
    }
    else {
        struct node* temp = hash[key];

        while(temp->next != NULL ) {
            temp=temp->next;
        }
        temp->next=newNode;
    }
}

void Deletion(struct node* hash[],int size,int value) {

    struct node* deleteNode = malloc(sizeof(struct node));

    int key=value%size;

    if(hash[key]->data == value) {
        if(hash[key]->next == NULL ) {
            hash[key] == NULL;
        }
        else {
            struct node* nextNode=hash[key]->next;
            deleteNode=hash[key];
            hash[key]=nextNode;
        }
        printf("if block \n");
    }
    else {
        struct node* travel=hash[key];

        while(travel->next != NULL ) {
            travel=travel->next;
        } 
        if(travel->data == value) {
            //deleteNode=travel[key];
        }
        printf("else bolck");
    }
    free(deleteNode);
}

void Display(struct node* hash[],int size) {
    for(int i=0;i<size;i++) {
        printf("hash[%d] ",i);
        struct node* temp = malloc(sizeof(struct node));
        temp=hash[i];
        while(temp != NULL ) {
            printf("=> %d ",temp->data);
            temp=temp->next;
        }
        printf("=> NULL \n");
    }
}

int main() {

    int size;
    printf("Enter Size of Hash map ");
    scanf("%d",&size);

    struct node* hash[size];

    for(int i=0;i<size;i++) {
        hash[i]=NULL;
    }



    Insert(hash,size,12);
    Insert(hash,size,27);
    Insert(hash,size,34);
    Insert(hash,size,11);
    Insert(hash,size,9);
    Insert(hash,size,121);
    Insert(hash,size,22);

    
    Insert(hash,size,111);
    Insert(hash,size,222);

    Deletion(hash,size,12);

    Display(hash,size);


    return 0;
}