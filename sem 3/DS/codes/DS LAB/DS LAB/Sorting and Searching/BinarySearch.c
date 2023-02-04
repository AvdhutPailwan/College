#include<stdio.h>
#include<stdlib.h>

int binarySearch(int arr[],int n,int key) {
    int s=0;
    int e=n-1;

    while(s<=e) {
        int mid=(s+e)/2;
        if(arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] < key ) {
            s=mid+1;
        }
        else {
            e=mid-1;
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

    int ans=binarySearch(arr,n,key);

    printf("Element is at index: %d \n",ans);

    return 0;
}