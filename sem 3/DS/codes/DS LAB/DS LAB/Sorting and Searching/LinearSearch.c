#include<stdio.h>
#include<stdlib.h>

int linearSearch(int arr[],int n,int key) {
    for(int i=0;i<n;i++) {
        if (arr[i] == key ){
            return i;
        }
    }
    return -1;
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

    int key;
    printf("Enter Key: ");
    scanf("%d",&key);

    int ans=linearSearch(arr,n,key);

    printf("Element is at index: %d \n",ans);

    return 0;
}