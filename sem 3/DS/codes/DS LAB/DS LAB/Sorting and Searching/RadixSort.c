#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BASE 10

void radix_sort(int *arr, int size) {
    
    int max_num = arr[0];
    
    for (int i = 1; i < size; i++) {
        if (arr[i] > max_num) {
            max_num = arr[i];
        }
    }

    int num_digits = log10(max_num) + 1;
    int mod = BASE, div = 1;

    for (int i = 0; i < num_digits; i++, mod *= BASE, div *= BASE) {
        int buckets[BASE][size];
        int count[BASE] = {0};

        for (int j = 0; j < size; j++) {
            int bucket = (arr[j] % mod) / div;
            buckets[bucket][count[bucket]++] = arr[j];
        }

        int k = 0;
        for (int j = 0; j < BASE; j++) {
            for (int l = 0; l < count[j]; l++) {
            arr[k++] = buckets[j][l];
            }
        }

    }
}

int main() {
  
    int size;
    printf("Enter Size of Array: ");
    scanf("%d",&size);

    int arr[size];

    printf("Enter Array Elements: ");
    for(int i=0;i<size;i++) {
        scanf("%d",&arr[i]);
    }

    radix_sort(arr, size);

    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

  return 0;
}
