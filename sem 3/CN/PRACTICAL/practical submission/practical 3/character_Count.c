#include<stdio.h>
#include<stdlib.h>
int strl(char str[]){
  int i = 0;
  while(str[i]!='\0'){
    i++;
  }
  return i;
}
int main()
{
    void* a = (void*)malloc(200*sizeof(char));
    char* ch;
    int* jump;
    jump = a;
    ch = a+sizeof(int);
    scanf("%[^\n]%*c", ch);
    printf("Given string is : %s\n", ch);
    *jump = strl(ch);
    a=realloc(a,((*jump)*sizeof(char))+sizeof(int));
    for(int i = 0; i<*jump; i++){
        int count = 0;
        if(ch[i-1]==' ' || i == 0){
            for(int j = i; j<*jump; j++){
                count++;
                if(ch[j]==' '|| j==*jump-1){
                    printf("\n%-6d",count);
                    break;
                }
            }
        }
        printf("%c",ch[i]);
    }
    free(a);
    return 0;
}