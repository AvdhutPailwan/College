// *------------- SYB22 Avdhut Pailwan -------------*
// TODO : implement closed addressing

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} n; // typedef Node as n. n will access the struct Node.

int serch_and_insert(n a[], int data)
{
    int ind = data % 10, count = 1;
    char option;
    if (a[ind].next == NULL && a[ind].data == -1)
    {
        printf("\nThe data is not present in array list.\nWould  you like to insert data in array list? [Y/n]: ");
        getchar();
        while (!scanf("%c", &option))
        {
            printf("\nEnter again : ");
        }
        if (option == 'y' || option == 'Y')
            a[ind].data = data;
        return 1;
    }
    else
    {
        n *travel = &a[ind];
        if (travel->data == data)
        {
            printf("\nThe given data is already present at row %d node %d in array list.", ind, count);
            return 1;
        }
        while (travel->next != NULL)
        {
            if (travel->data == data)
            {
                printf("\nThe given data is already present at row %d  node %d in array list.", ind, count);
                return 1;
            }
            travel = travel->next;
            count++;
        }
        if (travel->data == data)
        {
            printf("\nThe given data is already present at row %d node %d in array list.", ind, count);
            return 1;
        }
        if (travel->next == NULL)
        {
            printf("\nThe data is not present in array list.\nWould  you like to insert data in array list? [Y/n]: ");
            getchar();
            while (!scanf("%c", &option))
            {
                printf("\nEnter again : ");
            }
            getchar();
            while (option != 'Y' && option != 'y' && option != 'n' && option != 'N')
            {
                printf("\nInvalid input\nEnter again : ");
                getchar();
                while (!scanf("%c", &option))
                {
                    printf("\nEnter again : ");
                }
            }
            if (option == 'y' || option == 'Y')
            {
                n *temp = malloc(sizeof(n));
                temp->data = data;
                temp->next = NULL;
                travel->next = temp;
            }
            return 1;
        }
    }
    return 0;
}

int main()
{
    int op, data;
    n arr[10];
    int i;
    for (i = 0; i < 10; i++)
    {
        arr[i].next = NULL;
        arr[i].data = -1;
    }
    bool flag = true;
    while (flag)
    {
        printf("\n1.Enter the data\n2. Stop\nEnter the operation : \t");
        while (!scanf("%d", &op))
        {
            printf("Enter operation again : ");
        }
        getchar();
        if (op == 2)
        {
            flag = false;
            break;
        }
        if (op == 1)
        {
            printf("\nEnter the Number : \t");
            while (!scanf("%d", &data))
            {
                printf("Enter data again : ");
            }
            if (serch_and_insert(arr, data))
            {
                printf("\noperation successful\n");
            }
            else
            {
                printf("\noperation unsuccessful\n");
            }
        }
    }
    return 0;
}