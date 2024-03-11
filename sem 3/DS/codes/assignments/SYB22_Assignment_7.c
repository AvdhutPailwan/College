// TODO : convert infix to postfix

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push(char stack[], int *top, char data)
{
    (*top)++;
    stack[*top] = data;
}

void pop(char stack[], int *top)
{
    printf("%c", stack[*top]);
    (*top)--;
}

int precedance(char a)
{
    if (a == '^')
        return 3;
    if (a == '*' || a == '/')
        return 2;
    if (a == '+' || a == '-')
        return 1;
    return -1;
}

int main()
{

    printf("\n\nEnter the Infix Expression : ");
    char *exp = malloc(sizeof(char) * 50); // * 'exp' means expression
    scanf("%s", exp);
    int l = strlen(exp);                  // * length of expression
    exp = realloc(exp, l * sizeof(char)); // * free unused memory
    char *operators = malloc(sizeof(char)*l);
    int top = -1; // * created a stack to store operators
    int i;        // * iterator for the loop
    printf("\n\nThe Postfix expression :    ");
    for (i = 0; i < l; i++)
    {
        if ((exp[i] > 65 && exp[i] < 91) || (exp[i] > 96 && exp[i] < 123))
        {
            printf("%c", exp[i]);
        }
        else if (exp[i] == '(')
        {
            push(operators, &top, exp[i]);
        }
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^')
        {
            while (top != -1 && precedance(exp[i]) <= precedance(operators[top]))
            {
                pop(operators, &top);
            }
            push(operators, &top, exp[i]);
        }
        else if (exp[i] == ')')
        {
            while (operators[top] != '(')
            {
                pop(operators, &top);
            }
            top--;
        }
    }
    free(exp);
    while (top != -1)
        pop(operators, &top);
    printf("\n\n");
    free(operators);
    return 0;
}
