#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void compress(char [], char [], int, int);
int main()
{
    char* str = malloc(500*sizeof(char));
    scanf("%s",str);
    str = realloc(str,(strlen(str)*sizeof(char)));
    char* ans = malloc(sizeof(str));
    ans[0]=str[0];
    compress(str,ans,1,0);
    return 0;
}
void compress(char s[], char a[], int si, int aj){
    if(si == strlen(s)){
        a[aj+1]='\0';
        printf("%s",a);
        return;
    }
    if(s[si]!=a[aj]){
        a[++aj]=s[si];
        compress(s,a,si+1,aj);
    }else{
        a[aj]='\0';
        compress(s,a,si+1,--aj);
    }
}
// Avdhut Pailwan SYB22