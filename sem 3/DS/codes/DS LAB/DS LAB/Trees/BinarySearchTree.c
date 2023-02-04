// TODO: Binary Search tree 

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int data);
void InOrderTraversal(Node* root);


void InsertInBST(Node* root,int data) {

    // Create an new Node and previous Node
    Node* previous=malloc(sizeof(Node));
    Node* newNode=malloc(sizeof(Node));
    
    // Asssign it's Value
    previous=NULL;
    newNode=createNode(data);

    // perform traversal like Binary Search
    while(root != NULL) {

        previous=root; // Assign Previous Node as root node

        if(root->data == data) {
            printf("Element Cannot be Inserted \n");
            return;
        }
        else if (root->data > data) {
            root=root->left;
        }
        else {
            root=root->right;
        }

    }

    // we traverse till the correct Node now check where to go left or right
    if(data < previous->data) 
        previous->left=newNode;
    else 
        previous->right=newNode;
    
}

void SearchingInBST(Node* root,int data) {
    
    if(root == NULL) {
        printf("Element Not Found ! \n");
        return;
    }

    if(root->data == data) {
        printf("Element Found !!! \n");
    }
    else if (data < root->data){
        SearchingInBST(root->left,data);
    }
    else {
        SearchingInBST(root->right,data);
    }
}


Node* minValueNode(Node* root) {

    Node* current = root;

    while(current && current->left != NULL ) {
        current=current->left;
    }
    return current;
}

Node* Deletion(Node* root,int data) {

    if(root == NULL) {
        return root;
    }

    if(data < root->data) {
        Deletion(root->left,data);
    }
    else if (data > root->data) {
        Deletion(root->right,data);
    }
    else {

        // Deletion of Node with only one child 
        if(root->left == NULL) {
            Node* temp=root->left;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp=root->right;
            free(root);
            return temp;
        }

        Node* temp=minValueNode(root->right);
        
        root->data=temp->data;
        root->right=Deletion(root->right,temp->data);

    }

    return root;

}


int main() {

    Node* root=malloc(sizeof(Node));

    Node* A=malloc(sizeof(Node));
    Node* B=malloc(sizeof(Node));
    Node* C=malloc(sizeof(Node));
    Node* D=malloc(sizeof(Node));
    Node* E=malloc(sizeof(Node));

    root=createNode(100);
    A=createNode(20);
    B=createNode(40);
    C=createNode(130);
    D=createNode(120);
    E=createNode(0);
    //        100
    //      /     \
    //     20     130 
    //    /  \    /
    //   0   40  120

    root->left=A;
    root->right=C;

    A->left=E;
    A->right=B;

    C->left=D;

    InsertInBST(root,150);
    InsertInBST(root,10);

    //SearchingInBST(root,20);
    //SearchingInBST(root,150);
    //SearchingInBST(root,200);

    InOrderTraversal(root);

    root=Deletion(root,20);

    printf("\n");
    InOrderTraversal(root);

    return 0;
}

Node* createNode(int data) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;

    return newNode;
}

void InOrderTraversal(Node* root) {
    if(root != NULL) {
        InOrderTraversal(root->left);
        printf("%d ",root->data);
        InOrderTraversal(root->right);
    }
}