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
    *jump = strl(ch);
    a=realloc(a,((*jump)*sizeof(char))+sizeof(int));
    for(int i = 0; i<*jump; i++){
        int count = 0;
        if(ch[i-1]==' ' || i == 0){
            for(int j = i; j<*jump; j++){
                count++;
                if(ch[j]==' '|| j==*jump-1){
                    printf("%d",count);
                    break;
                }
            }
        }
        if(ch[i]!=' '){
            printf("%c",ch[i]);
        }
    }
    printf("\n%s\n", ch);
    free(a);
    return 0;
}