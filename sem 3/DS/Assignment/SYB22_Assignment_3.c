// --------------- Avdhut Pailwan SYB22 -------------------------
#include <stdio.h>
#include <stdlib.h>
// abstract data type
struct Node
{
    int data;
    struct Node *next;
};
void create_list(struct Node *travel);
void display_list(struct Node *travel);
int main()
{
    char in;
    printf("Want to implement abstract data type? [Y/n] :      ");
    scanf("%c", &in);
    if (in == 'Y' || in == 'y')
    {
        struct Node *head = (struct Node *)malloc(sizeof(struct Node));
        create_list(head);
        printf("\nThe list is :\n");
        display_list(head);
    }


//--------------------------------------------------------------------------------------------------


    // store int in char array
    char ch[12];
    int* i = ch;
    i[0]=15;
    i[1]=54;
    printf("\nIntegers :\n%d\n%d\n",i[0],i[1]);


//---------------------------------------------------------------------------------------------------


    // store char in int array
    int arr[3];
    char* c = arr;
    int k,j=65;
    for(k = 0; k<12; k++){
        c[k] = j++;
    }
    printf("\ncharacters :\n");
    for(k = 0; k<12; k++){
        printf("%c\n",c[k]);
    }

    return 0;
}
void create_list(struct Node *travel)
{
    if (travel->next != NULL)
    {
        printf("\nEnter the data in head :    ");
        scanf("%d", &(travel->data));
        travel->next = NULL;
    }
    struct Node *temp = malloc(sizeof(struct Node));
    printf("\nEnter the data in Next Node :    ");
    scanf("%d", &(temp->data));
    temp->next = NULL;
    travel->next = temp;
    char a, tem;
    printf("\nCreate another Node? [Y/n] :    ");
    scanf("%c%c", &tem, &a);
    if (a == 'Y' || a == 'y')
        create_list(travel->next);
    else
        return;
}
void display_list(struct Node *travel)
{
    printf("%-11d\n", travel->data);
    if (travel->next == NULL)
        return;
    display_list(travel->next);
}