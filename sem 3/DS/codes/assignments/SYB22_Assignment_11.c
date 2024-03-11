// *------------------- SYB22 Avdhut Pailwan -------------------*
// TODO: implement quick sort on array of integers

#include <stdio.h>

// below function will print the array *array = array and size  = size of array

void print_array(int *array, int size)
{
    int i; // iterator
    printf("\n");
    for (i = 0; i < size; i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n");
}

// below function will sort array using quick sort
// *array = array[] , beginning = beginning, end = end, pivot = pivot

void quick(int *array, int beginning, int end, int pivot)
{

    // base case to terminate recursion

    if (beginning > end)
    {
        return;
    }

    // initialize left_index = left index, right_index = right index

    int left_index = beginning;
    int right_index = end;
    pivot = beginning;

    // below loop will place the pivot element in its correct position

    while (left_index < right_index)
    {
        while (array[right_index] > array[pivot] && pivot != right_index)
        {
            --right_index;
        }
        if (right_index == pivot)
        {
            break;
        }
        if (array[right_index] <= array[pivot])
        {
            int temp = array[pivot];
            array[pivot] = array[right_index];
            array[right_index] = temp;
            pivot = right_index;
        }
        while (array[left_index] <= array[pivot] && left_index != pivot)
        {
            ++left_index;
        }
        if (left_index == pivot)
        {
            break;
        }
        if (array[left_index] > array[pivot])
        {
            int temp = array[pivot];
            array[pivot] = array[left_index];
            array[left_index] = temp;
            pivot = left_index;
        }
    }

    quick(array, pivot + 1, end, pivot + 1); // right subarry of sorted element to sort using recursion
    quick(array, 0, pivot - 1, 0);           // left subarry of sorted element to sort using recursion
}

int main()
{
    // size = size of array, i = iterator

    int size, i;

    printf("Enter number of elements in array : ");
    scanf("%d", &size);

    int array[size]; // array to sort

    printf("enter integers in array : ");

    // taking array input

    for (i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }

    quick(array, 0, size - 1, 0); // call quick function to quick sort

    print_array(array, size); // print the sorted array

    return 0;
}