// *--------------------------- SYB22 Avdhut Pailwan ---------------------------------*
// TODO : Write selection sort
#include<stdio.h>
#include<string.h>
#define I 0
void input_array(int*, int, int);
void print_array(int*, int, int);
void selection_sort(int*,int,int);
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
    selection_sort(arr,I,n);
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
void selection_sort(int a[], int i,int size){
    if(i==size)return;
    int j=i+1;
    for(;j<size;j++){
        if(a[i]>a[j]){
            int temp =  a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    selection_sort(a,i+1,size);
}