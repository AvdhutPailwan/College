// --------------------------------- Avdhut Pailwan SYB22 -----------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    struct Node *pre;
    struct Node *next;
    char data[20];
} typedef Node;
Node *url(Node *);
Node *backward(Node *);
Node *Forward(Node *);
int serch_url(Node *, char *);
void display_current(Node *);
void main()
{
    Node *head = malloc(sizeof(Node));
    head->next = NULL;
    head->pre = NULL;
    Node *travel;
    travel = head;
    printf("Enter the Url : ");
    char temp;
    scanf("%s", head->data);
    int keep_going = 1;
    while (keep_going)
    {
        printf("\nEnter the operation to perform :\n1. Enter an url\n2. Display current url\n3. back\n4. forward\n5. serch URL\n6.exit\n  :   ");
        char op;
        scanf("%c%c", &temp, &op);
        switch (op)
        {
        case '1':
            head = url(head);
            break;
        case '2':
            display_current(head);
            break;
        case '3':
            if (head->pre == NULL)
            {
                printf("No backward url.");
                break;
            }
            head = backward(head);
            printf("\n%s\n", head->data);
            break;
        case '4':
            if (head->next == NULL)
            {
                printf("No forward url.");
                break;
            }
            head = Forward(head);
            printf("\n%s\n", head->data);
            break;
        case '5':
            char serch[20];
            scanf("%s", serch);
            (serch_url(travel, serch) == 1) ? printf("\npresent\n") : printf("\nnot present\n");
            break;

        default:
            keep_going = 0;
            break;
        }
    }
}
Node *url(Node *travel)
{
    Node *temp = malloc(sizeof(Node));
    scanf("%s", temp->data);
    temp->pre = travel;
    travel->next = temp;
    temp->next = NULL;
    return temp;
}
Node *backward(Node *travel)
{
    return travel->pre;
}
Node *Forward(Node *travel)
{
    return travel->next;
}
int serch_url(Node *travel, char *serch)
{
    int i;
    for (i = 0; i < strlen(serch); i++)
    {
        if (serch[i] != travel->data[i])
            break;
    }
    if (i == strlen(serch))
        return 1;
    if (travel->next != NULL)
        serch_url(travel->next, serch);
    else
        return 0;
}
void display_current(Node *travel)
{
    printf("\n%s\n", travel->data);
}