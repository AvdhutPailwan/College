// *-------------- SYA80 Radhika Kumbhar ---------------*
//  TODO :  Min Heap using array | 1. Insert node in the heap | 2. Display heap
#include <stdio.h>
#include <stdlib.h>
typedef enum boolean
{
    false,
    true
} b;

void insert_node(int *, int, int*);
void display_heap(int *, int );
int main()
{
    b flag = true;
    printf("\nEnter the number of nodes in the heap :   ");
    int s;
    while (!(scanf("%d", &s)))
    {
        getchar();
        printf("\nenter again : ");
    }
    int *heap = malloc(sizeof(s * sizeof(int)));
    int *root = NULL;
    int *hindex;
    *hindex = -1;
    while (flag)
    {
        getchar();
        printf("\nWhich operation would you like to perform :\n1. Insert node\n2. Display Heap\n3.stop\n    : ");
        char op;
        while (!(scanf("%c", &op)))
        {
            getchar();
            printf("\nenter again : ");
        }
        switch (op)
        {
        case '1':
            if(*hindex >= s-1){
                printf("\nHeap limit reached.\n");
            }else{
                int data;
                printf("\nEnter the data : ");
                while (!(scanf("%d", &data)))
                {
                    getchar();
                    printf("\nenter again : ");
                }
                insert_node(heap, data, hindex);
            }
            break;
        case '2':
            if(*hindex == -1)printf("\nNo elements in heap.\n");
            else display_heap(heap,*hindex);
            break;
        case '3':
            flag = false;
            break;
        default :
            break;
        }
    }
    return 0;
}

void insert_node(int *root, int data, int *hindex)
{
    root[++(*hindex)]=data;
    int index = *hindex;
    while(index>0){
        int parent = ((index)-1)/2;
        if(root[parent]>root[index]){
            root[parent] = root[parent]+root[index];
            root[index]= root[parent]-root[index];
            root[parent]=root[parent]-root[index];
        }
        index = parent;
    }
}
void display_heap(int heap[], int hindex)
{
    int i;
    for(i=0;i<=hindex;i++){
        printf("%d   ",heap[i]);
    }
    printf("\n");   
}
// *-------------- SYA80 Radhika Kumbhar ---------------*