// --------------------------------- SYB22 Avdhut Pailwan -----------------------------------
// TODO: implement binary serch tree    i)insert  ii)serch

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
}typedef node;

node* insert(node*, int);
node* serch(node*, int);


int main()
{
    node* root = malloc(sizeof(node)), *travel;
    root->left =root->right =NULL;
    
    int flag = 1, data;
    char loop_signal = 1;
    while(loop_signal){
        printf("\nWhich operation would you like to perform?\n1. Insert\n2. Serch\n3. stop\n    :    ");
        char in, temp;
        scanf("%c",&in);
        switch (in)
        {
        case '1':
            printf("\nEnter data to insert :    ");
            scanf("%d",&data);
            if(flag){
                root->data = data;
                travel = root;
                flag = 0;
            }else{
                travel = insert(root, data);
            }
            if(travel!= NULL)printf("\nInsertion Successful\n%d inserted at %p\n",data,travel);
            else printf("\ninsertion failed\n");
            scanf("%c",&temp);
            break;
        case '2':
            printf("\nenter the data to serch : ");
            scanf("%d",&data);
            travel = serch(root,data);
            if(travel!=NULL)printf("\nThe data is present at %p location.\n",travel);
            else printf("\ndata not found in tree\n");
            scanf("%c",&temp);
            break;
        default:
            loop_signal = 0;
            break;
        }
       
    }
    return 0;
}

node* insert(node* root, int data){
    node* temp = malloc(sizeof(node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    while(1){
        if(root->data >= data){
            if(root->left == NULL){
                root->left  = temp;
                printf("\nleft link  %d\n",(root->left)->data);
                return temp;
            }
            else{
                root= root->left;
                printf("\nIn left branch\n");
            }
        }
        else{
            if(root->right == NULL){
                root->right  = temp;
                printf("\nright link  %d\n",(root->right)->data);
                return temp;
            }
            else{
                root= root->right;
                printf("\nIn right branch\n");
            }
        }
    }
    return NULL;
}

node* serch(node* root, int data){
    if(root->data == data)return root;
    if(root->data>data && root->left!=NULL)return serch(root->left,data);
    if(root->data<data && root->right!=NULL)return serch(root->right,data);
    return NULL;
}
