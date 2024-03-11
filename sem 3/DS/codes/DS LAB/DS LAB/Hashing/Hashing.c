// @author Ritesh Bakare

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void insert(int hash[],int value,int size) {

    int key=value%size;

    if(hash[key]==-1) {
        hash[key]=value;
        printf("Elemented %d Inserted in HashTable with key %d \n",value,key);
    }
    else {
        printf("Collision Occure already exsists an element-> %d \n",hash[key]);
        printf("Unable to insert %d \n",value);
    }
}

void print(int hash[],int size) {
    for(int i=0;i<size;i++) 
        printf(" [(key:%d)(value:%d)]   ",i,hash[i]);

    printf("\n");
}

void delete(int hash[],int value,int size) {
    int key=value%size;

    if(hash[key] == -1 ) {
        printf("Element Not exsists \n");
    }
    if(hash[key] == value ) {
        hash[key]=-1;
        printf("Element deleted \n");
    }
}

void search(int hash[],int value,int size) {

    int key=value%size;

    if(hash[value] != -1 ) {
        printf("Element Found at key: %d \n",key);
    }
    else {
        printf("Element Not Found !!! \n");
    }

}

int main() {

    int size;
    printf("Enter Size of HashTable: ");
    scanf("%d",&size);

    int *hash=malloc(size*sizeof(int));

    // initilize the hashtable with -1
    for(int i=0;i<size;i++) {
        hash[i]=-1;
    }

    bool keeyGoing = true;

    while(keeyGoing) {

        printf("Please Select the Operation \n ");
        printf("1) Insert \n");
        printf("2) Deletion \n");
        printf("3) Search \n");
        printf("4) Print \n");

        int choice;
        scanf("%d",&choice);

        switch(choice) {

            case 1 : {
                int value;
                printf("Enter Element To Insert: ");
                scanf("%d",&value);
                insert(hash,value,size);
                break;
            }
            case 2 : {
                int value;
                printf("Enter Elemnet To Delete: ");
                scanf("%d",&value);
                delete(hash,value,size);
                break;
            }
            case 3 : {
                int value;
                printf("Enter Elemnet To Search: ");
                scanf("%d",&value);
                search(hash,value,size);
                break;
            }
            case 4: {
                printf("Hash Table is \n");
                print(hash,size);
                break;
            }
            default : {
                keeyGoing=false;
                break;
            }
        }

    }


    return 0;
}