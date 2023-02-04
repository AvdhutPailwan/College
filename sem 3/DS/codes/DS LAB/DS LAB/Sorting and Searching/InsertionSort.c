#include<stdio.h>
#include<stdlib.h>

void InsertionSort(int arr[],int n) {
    for(int i=1;i<n;i++) {
        int temp=arr[i];
        int j;
        for(j=i-1;j>=0;j--) {
            if(arr[j] > temp ) {
                arr[j+1]=arr[j];
            }
            else {
                break;
            }
        }
        arr[j+1]=temp;
    }
}

int main() {

    int n;
    printf("Enter Size of Array: \n");
    scanf("%d",&n);

    int *arr=malloc(n*sizeof(int));
    printf("Enter Element: \n");
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }

    InsertionSort(arr,n);

    printf("Sorted Element: \n");
    for(int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}