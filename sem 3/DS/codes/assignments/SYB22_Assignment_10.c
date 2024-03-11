// *--------------------------- SYB22 Avdhut Pailwan ---------------------------------*
// TODO : Write bubble sort
#include<stdio.h>
#include<string.h>
#define I 0
void input_array(int*, int, int);
void print_array(int*, int, int);
void bubble_sort(int*,int,int);
int main()
{
    int n;
    printf("Enter No. of elements in array :\t");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements in array :\t");
    input_array(arr,I,n);
    printf("The elements in array are :\t");
    print_array(arr,I,n);
    bubble_sort(arr,I,n);
    printf("\nThe sorted array is : ");
    print_array(arr,I,n);
    return 0;
}
void input_array(int arr[], int i, int size){
    if(i==size)return;
    scanf("%d",&arr[i]);
    input_array(arr,i+1,size);
}
void print_array(int arr[], int i, int size){
    if(i==size){
        printf("\n");
        return;
    }
    printf("%d ",arr[i]);
    print_array(arr,i+1,size);
}
void bubble_sort(int a[], int i,int size){
    if(i==size-1)return;
    int j=0;
    for(;j<size-i-1;j++){
        if(a[j]>a[j+1]){
            int temp =  a[j];
            a[j] = a[j+1];
            a[j+1] = temp;
        }
    }
    bubble_sort(a,i+1,size);
}