#include<stdio.h>
#include<stdlib.h>

void BubbleSort(int arr[],int n) {
    for(int i=1;i<n;i++) {
        for(int j=0;j<n-i;j++) {
            if(arr[j] > arr[j+1] ) {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
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

    BubbleSort(arr,n);

    printf("Sorted Element: \n");
    for(int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}