// TODO: Binary Tree Traversal Methods InOrder , PreOrder & PostOrder

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int data);

void preOrderTraversal(Node* root) {
    if(root != NULL) {
        printf("%d ",root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(Node* root) {
    if(root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ",root->data);
    }
}

void InOrderTraversal(Node* root) {
    if(root != NULL) {
        InOrderTraversal(root->left);
        printf("%d ",root->data);
        InOrderTraversal(root->right);
    }
}

int main() {

    // Creating Nodes

    Node* root=createNode(10);
    Node* A=createNode(20);
    Node* B=createNode(30);
    Node* C=createNode(40);
    Node* D=createNode(50);

    // tree representation 
    //     root(10)
    //     /    \
    //    A(20)  B(30)
    //   /    \
    // C(40)   D(50)


    // Joining Nodes

    root->left=A;
    root->right=B;
    A->left=C;
    A->right=D;

    printf("Pre-Order-Traversal-> ");
    preOrderTraversal(root);
    printf("\n");

    printf("Post-Order-Traversal-> ");
    postOrderTraversal(root);
    printf("\n");

    printf("In-Order-Traversal-> ");
    InOrderTraversal(root);
    printf("\n");


    return 0;
}

Node* createNode(int data) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;

    return newNode;
}