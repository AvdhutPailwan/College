#include<stdio.h>
#include<stdlib.h>

#define size 10

void insert(int hash[],int data) {

    int key=data%size;

    while(hash[key] != -1 ) {
        key=(key+1)%size;
    }
    hash[key]=data;
}

void Display(int hash[]) {
    for(int i=0;i<size;i++) {
        printf("key=>%d | value=> %d \n",i,hash[i]);
    }
}

int main() {

    int* hash=malloc(size*(sizeof(int)));

    // initilize Hash Table 
    for(int i=0;i<size;i++) {
        hash[i]=-1;
    }

    insert(hash,12);
    insert(hash,21);
    insert(hash,13);
    insert(hash,44);
    insert(hash,22);
    insert(hash,11);
    insert(hash,9);
    insert(hash,8);
    insert(hash,2);
    insert(hash,3);

    Display(hash);

    return 0;
}