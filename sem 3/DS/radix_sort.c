#include<stdio.h>
#include<limits.h>
int max_num(int a[], int n){
  int max = INT_MIN;
  int i = 0;
  for(;i<n;i++){
    if(a[i]>max)max = a[i];
  }
  return max;
}
void radix_sort(int a[], int n, int max, int pos){
  if(max<=0)return;
  int i,j,k,rad_buk[n][10];
  for(i=0;i<n;i++){
      for(j=0;j<10;j++){
        rad_buk[i][j]=0;
      }
    }
    for(i=0;i<n;i++){
      rad_buk[i][((a[i]/pos)%10)] = a[i];
    }
    k=0;
    for(i=0;i<10;i++){
      for(j=0;j<n;j++){
        if(rad_buk[j][i] != 0)a[k++] = rad_buk[j][i];
      }
    }
    radix_sort(a,n,max/10,pos*10);
}
int main(){
  int n,pos=1,i; 
  // int j,k;
  printf("Enter the no. of integers : ");
  while(!scanf("%d",&n));
  int a[n],temp[n];
  for(i=0; i<n;i++){
    while(!scanf("%d",&a[i]));
    temp[i]=a[i];
  }
  int max = max_num(a, n);
  // int rad_buk[n][10];
  
  // while(max>0){
  //   for(i=0;i<n;i++){
  //     for(j=0;j<10;j++){
  //       rad_buk[i][j]=0;
  //     }
  //   }
  //   for(i=0;i<n;i++){
  //     rad_buk[i][((a[i]/pos)%10)] = a[i];
  //   }
  //   k=0;
  //   for(i=0;i<10;i++){
  //     for(j=0;j<n;j++){
  //       if(rad_buk[j][i] != 0)temp[k++] = rad_buk[j][i];
  //     }
  //   }
  //   for(i=0;i<n;i++){
  //     a[i]=temp[i];
  //   }
  //   max = max/10;
  //   pos = pos*10;
  // }
  radix_sort(a,n,max,pos);
  printf("\n");
  for(i=0;i<n;i++){
    printf("%d  ",a[i]);
  }
  printf("\n");
}