// ------------------------ Avdhut Pailwan SYB22 -------------------
// NOTE : one based indexing

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} typedef Node;
void create_list(Node *travel);
void display_list(Node *travel);
void insert_end(Node *travel, int val);
Node *insert_beg(Node *travel, int val);
Node *insert_at(Node *travel, int index, int val);
int insert_before(Node *travel, int valb, int val);
int insert_after(Node *travel, int valb, int val);
void pop(Node *travel);
Node *remove_beg(Node *travel);
Node *remove_from(Node *travel, int index);
int remove_val(Node *travel, int val);
int main()
{
    printf("Note : The indexing is 1-based\n");
    Node *head = (Node *)malloc(sizeof(Node));
    create_list(head);
    int fun, append, idx;
    char tem, keep_going = 'y';
    while (keep_going == 'Y' || keep_going == 'y')
    {
        printf("Enter the function you want to perform:\n1. insert at beginning\n2. insert at end\n3. insert at certain index\n4. remove from beginning\n5. remove from end\n6. remove from certain index\n7. insert before value\n8. insert after value\n9. remove value\n : ");
        scanf("%d", &fun);
        switch (fun)
        {
        case 1:
            printf("\nEnter the value to append : ");
            scanf("%d", &append);
            head = insert_beg(head, append);
            printf("\nThe list is :\n");
            display_list(head);
            break;
        case 2:
            printf("\nEnter the value to append : ");
            scanf("%d", &append);
            insert_end(head, append);
            printf("\nThe list is :\n");
            display_list(head);
            break;
        case 3:
            printf("\nEnter the index and value to append : ");
            scanf("%d%d", &idx, &append);
            head = insert_at(head, idx, append);
            printf("\nThe list is :\n");
            display_list(head);
            break;
        case 4:
            head = remove_beg(head);
            printf("\nThe list is :\n");
            display_list(head);
            break;
        case 5:
            pop(head);
            printf("\nThe list is :\n");
            display_list(head);
            break;
        case 6:
            printf("\nEnter the index to remove : ");
            scanf("%d", &idx);
            head = remove_from(head, idx);
            printf("\nThe list is :\n");
            display_list(head);
            break;
        case 7:
            printf("\nEnter the data and the value before to insert : ");
            scanf("%d%d", &append, &idx);
            int flag = insert_before(head, idx, append);
            if (!flag)
                printf("\ninvalid operation\n");
            else
                display_list(head);
            break;
        case 8:
            printf("\nEnter the data and the value after to insert : ");
            scanf("%d%d", &append, &idx);
            flag = insert_after(head, idx, append);
            if (!flag)
                printf("\ninvalid operation\n");
            else
                display_list(head);
            break;
        case 9:
            printf("\nEnter the value to remove : ");
            scanf("%d", &append);
            (remove_val(head, append)) ? display_list(head) : printf("invalid operation!\n");

            break;
        default:
            break;
        }
        printf("Perform another operation? [Y/n]:   ");
        scanf("%c%c", &tem, &keep_going);
    }
    return 0;
}
void create_list(Node *travel)
{
    if (travel->next != NULL)
    {
        printf("\nEnter the data in head :    ");
        scanf("%d", &(travel->data));
        travel->next = NULL;
    }
    else
    {
        Node *temp = malloc(sizeof(Node));
        printf("\nEnter the data in Next Node :    ");
        scanf("%d", &(temp->data));
        temp->next = NULL;
        travel->next = temp;
    }

    char a, tem;
    printf("\nCreate another Node? [Y/n] :    ");
    scanf("%c%c", &tem, &a); // tem is used cause compiler was not taking char input for a
    if (a == 'Y' || a == 'y')
    {
        if (travel->next == NULL)
            create_list(travel);
        else
            create_list(travel->next);
    }
    else
        return; // termination
}
void display_list(Node *travel)
{
    printf("%-11d\n", travel->data);
    if (travel->next == NULL) // recursion termination condition
        return;
    display_list(travel->next); // recursion
}
void insert_end(Node *travel, int val)
{
    if (travel->next == NULL)
    {
        Node *temp = malloc(sizeof(Node));
        temp->data = val;
        temp->next = NULL;
        travel->next = temp;
        return;
    }
    insert_end(travel->next, val);
}
Node *insert_beg(Node *travel, int val)
{
    Node *temp = malloc(sizeof(Node));
    temp->data = val;
    temp->next = travel;
    return temp;
}
Node *insert_at(Node *travel, int index, int val)
{
    if (index == 1)
        travel = insert_beg(travel, val);
    else
    {
        int count = 1;
        Node *te = travel;
        while ((count != index - 1) && (te->next != NULL))
        {
            te = te->next;
            count++;
        }
        Node *temp = malloc(sizeof(Node));
        temp->data = val;
        temp->next = te->next;
        te->next = temp;
    }
    return travel;
}
void pop(Node *travel)
{
    Node *temp;
    while (travel->next != NULL)
    {
        temp = travel;
        travel = travel->next;
    }
    temp->next = NULL;
    free(travel);
}
Node *remove_beg(Node *travel)
{
    Node *temp = travel;
    travel = travel->next;
    free(temp);
    return travel;
}
Node *remove_from(Node *travel, int index)
{
    if (index == 1)
        travel = remove_beg(travel);
    else
    {
        int count = 1;
        Node *te = travel;
        while ((count != index - 1) && (te->next != NULL))
        {
            te = te->next;
            count++;
        }
        Node *temp;
        temp = te->next;
        te->next = temp->next;
        free(temp);
    }
    return travel;
}

int insert_before(Node *travel, int valb, int val)
{
    Node *temp1 = travel;
    if (temp1->data == valb)
    {
        printf("\nplease choose 1. insert at beginning");
        return 0;
    }
    while (temp1->next->data != valb)
    {
        temp1 = temp1->next;
        if (temp1->next == NULL)
            return 0;
    }
    Node *insert = malloc(sizeof(Node));
    insert->data = val;
    insert->next = temp1->next;
    temp1->next = insert;
    return 1;
}
int insert_after(Node *travel, int valb, int val)
{
    Node *temp1 = travel;
    while (temp1->data != valb)
    {
        if (temp1->next == NULL)
            return 0;
        temp1 = temp1->next;
    }
    Node *insert = malloc(sizeof(Node));
    insert->data = val;
    insert->next = temp1->next;
    temp1->next = insert;
    return 1;
}
int remove_val(Node *travel, int val)
{
    if (travel->data == val)
    {
        printf("\nplease choose 4. remove from beginning\n");
        return 0;
    }
    while (travel->next->data != val)
    {
        travel = travel->next;
        if (travel->next == NULL)
            return 0;
    }
    Node *temp = travel;
    Node *free1 = travel->next;
    temp->next = free1->next;
    free(free1);
    return 1;
}