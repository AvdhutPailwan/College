// --------------------------------- SYB22 Avdhut Pailwan -----------------------------------
// TODO: implement binary serch tree    i)insert  ii)serch

#include <stdio.h>
#include <stdlib.h>
#include<time.h>
void* dummy_pointer;

struct node
{
    int data;
    struct node *left;
    struct node *right;
} typedef node;

node *insert_and_serch(node *, int);
void delay(int milli_seconds){
    clock_t start = clock();
    while(clock()<start+milli_seconds);
}

int main()
{
    node *root = malloc(sizeof(node)), *travel;
    root->left = root->right = NULL;

    int flag = 1, data;
    char loop_signal = 1;
    while (loop_signal)
    {
        delay(1000);
        char choice;
        printf("\nEnter data :    ");
        scanf("%d", &data);
        delay(500);
        getchar();
        if (flag)
        {
            while(1){
                printf("\nThe tree has no node\nWould you like to insert data?   [Y/n]:     ");
                scanf("%c", &choice);
                if (choice == 'y' || choice == 'Y')
                {
                    root->data = data;
                    travel = root;
                    flag = 0;
                    printf("\nInsertion Successful\n%d inserted at %p\n", data, travel);
                    break;
                }else if(choice!='n' && choice!='N'){
                    getchar();
                    printf("\nInvalid choice\n");
                }
                if(choice=='n' || choice=='N')break;
            }
        }
        else
        {
            travel = insert_and_serch(root, data);
            delay(1000);
            if (travel != NULL && travel!=dummy_pointer)
                printf("\nOperation Successful\n");
            else if(travel!=dummy_pointer)
                printf("\nOperation failed\n");
        }
        while(1){
            getchar();
            printf("\nAdd another data?   [Y/n]:     ");
            scanf("%c", &choice);
            if (choice == 'n' || choice == 'N')
            {
                loop_signal = 0;
                break;
            }
            else if(choice != 'y' && choice != 'Y')
            {
                printf("\nInvalid input\n");
            }
            else break;
        }
    }
    return 0;
}

node *insert_and_serch(node *root, int data)
{
    if (root->data == data)
    {
        printf("\nThe data is already present here.\n",root);
        return root;
    }   
    if (root->data > data)
    {
        if( root->left != NULL)
        {
            printf("\nleft branch\n");
            delay(500);
            return insert_and_serch(root->left, data);
        }else{
            char choice;
            printf("\nThe data is not present in tree.\nDo you want to insert data in tree?   [Y/n]:     ");
            scanf("%c", &choice);
            delay(1000);
            if (choice == 'y' || choice == 'Y')
            {
                node *temp = malloc(sizeof(node));
                temp->data = data;
                temp->left = NULL;
                temp->right = NULL;        
                root->left = temp;
                printf("\nleft link  %d\n", (root->left)->data);
                return temp;
            }else if(choice == 'n' || choice == 'N'){
                return dummy_pointer;
            }else{
                printf("\ninvalid operation\n");
                return NULL;
            }
            
        }
    }
    
    if (root->data < data ){
        if(root->right != NULL)
        {
            printf("\nright branch\n");
            delay(500);
            return insert_and_serch(root->right, data);
        }else{
            char choice;
            printf("\nThe data is not present in tree.\nDo you want to insert data in tree?   [Y/n]:     ");
            scanf("%c", &choice);
            delay(1000);
            if (choice == 'y' || choice == 'Y')
            {
                node *temp = malloc(sizeof(node));
                temp->data = data;
                temp->left = NULL;
                temp->right = NULL;        
                root->right = temp;
                printf("\nright link  %d\n", (root->right)->data);
                return temp;
            }else if(choice == 'n' || choice == 'N'){
                return dummy_pointer;
            }else{
                printf("\ninvalid operation\n");
                return NULL;
            }         
        }
    }     
    return NULL;
}

