#include<stdio.h>
#include<stdlib.h>

void SelectionSort(int arr[],int n) {
    for(int i=0;i<n-1;i++) {
        int minIndex=i;
        for(int j=i;j<n;j++) {
            if(arr[minIndex] > arr[j]) {
                minIndex=j;
            }
        }
        int temp=arr[minIndex];
        arr[minIndex]=arr[i];
        arr[i]=temp;
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

    SelectionSort(arr,n);

    printf("Sorted Element: \n");
    for(int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}