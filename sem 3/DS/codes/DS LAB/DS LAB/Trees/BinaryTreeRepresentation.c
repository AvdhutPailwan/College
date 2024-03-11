// TODO: LinkList Representation of Tree Data Structure

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int data) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;

    return newNode;
}

int main() {

    // Creating Nodes

    Node* root=createNode(10);
    Node* A=createNode(20);
    Node* B=createNode(20);
    Node* C=createNode(20);
    Node* D=createNode(20);

    // tree representation 
    //    root
    //    /  \
    //   A    B
    //  /  \
    // C    D


    // Joining Nodes

    root->left=A;
    root->right=B;
    A->left=C;
    A->right=D;


    return 0;
}