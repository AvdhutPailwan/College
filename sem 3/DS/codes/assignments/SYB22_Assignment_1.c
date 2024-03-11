#include<stdio.h>

int factorial(int);
int main()
{
    int n;
    printf("Enter the number : ");
    scanf("%d",&n);
    while(n<0){
        printf("Only non-negative positive integers.\nEnter again: ");
        scanf("%d",&n);
    }
    printf("Factorial :%6d",factorial(n));
    return 0;
}
int factorial(int a){
    if(a==0)return 1;
    return a*factorial(a-1);
}
// Avdhut Pailwan SYB22