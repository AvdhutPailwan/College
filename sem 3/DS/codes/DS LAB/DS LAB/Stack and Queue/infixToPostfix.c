#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack {
    int size;
    char *arr;
    int top;
};

int stackTop(struct stack* sp);
int isEmpty(struct stack* sp);
void push(struct stack* sp,char ch);
char pop(struct stack* sp);

int precendance(char ch) {
    if( ch=='*' || ch=='/')
        return 3;
    else if (ch=='+' || ch=='-')
        return 2;
    else
        return 1;
}

int isOperator(char ch) {
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
        return 1;
    else
        return 0;
}

char* infixToPostfix(char* infix) {

    struct stack* sp = (struct stack*) malloc(sizeof(struct stack));
    sp->size=100;
    sp->top=-1;
    sp->arr = (char*) malloc(sizeof((strlen(infix)+1) * sizeof(char*)));
    
    char * postfix = (char *) malloc((strlen(infix)+1) * sizeof(char));
    
    int i=0;
    int j=0;

    while(infix[i] != '\0') {

        if( !isOperator(infix[i]) ) {
            postfix[j]=infix[i];
            j++;
            i++;
        }
        else {

            if(precendance(infix[i]) > precendance(stackTop(sp))) {
                push(sp,infix[i]);
                i++;
            }
            else {
                postfix[j]=pop(sp);
                j++;
            }

        }

    }

    while(!isEmpty(sp)) {
        postfix[j]=pop(sp);
        j++;
    }
    postfix[j]='\0';

    return postfix;

}

int main() {

    char* infix="a+b*c/d";

    printf("Post expression: %s \n",infixToPostfix(infix));

    return 0;
}


int stackTop(struct stack* sp){
    return sp->arr[sp->top];
}

int isEmpty(struct stack* sp){
    if(sp->top == -1 )
        return 1;
    else
        return 0;
}

void push(struct stack* sp,char ch) {
    if(sp->top == sp->size -1) {
        printf("Stack Overrflow");
    }
    else {
        sp->top++;
        sp->arr[sp->top]=ch;
    }
}

char pop(struct stack* sp) {
    if(isEmpty(sp)){
        printf("Stack UnderFlow");
        return -1;
    }
    else {
        char ans=sp->arr[sp->top];
        sp->top--;
        return ans;
    }
}
