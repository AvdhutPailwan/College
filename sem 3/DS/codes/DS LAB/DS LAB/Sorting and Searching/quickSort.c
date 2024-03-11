#define MAX 100
#include <stdio.h>

void quickSort( int[], int, int);
int partition( int[], int, int);

void main() {
   int i,a[MAX], n;

    printf("\nThis program sorts input array of integers in Ascending Order using Quick Sort ");
    printf("\n\n Enter size of Array : ");
    scanf("%d",&n);

    printf("\n\nEnter %d numbers of an Array : ",n);
    for(i=0; i<n; i++)
       scanf("%d",&a[i]);

   printf("\n\nUnsorted array is: ");
   for(i = 0; i < n; i++)
      printf("%d ", a[i]);

   quickSort( a, 0, n-1);

   printf("\n\nSorted array is: ");
   for(i = 0; i < n; i++)
      printf("%d ", a[i]);

   printf("\n\n\n");
}

void quickSort( int a[], int l, int r) {
    int j;
   
    if( l < r ) {  // divide and conquer
        j = partition( a, l, r);
        
        quickSort( a, l, j-1);
        quickSort( a, j+1, r);
    }
}

int partition( int a[], int l, int r) {

   int pivot, start, end, t;
   
   pivot = a[l];
   start = l;
   end = r;
   
    while(start < end) {
        while( a[start] <= pivot)
            start++;

        while( a[end] > pivot)
            end--;

        if( start < end) {
            t = a[start];
            a[start] = a[end];
            a[end] = t;
        }
    }

    t = a[l];
    a[l] = a[end];
    a[end] = t;
    
    return end;
}