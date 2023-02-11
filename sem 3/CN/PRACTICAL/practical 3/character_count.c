#include <stdio.h>
#include <stdlib.h>
int strl(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}
int main()
{
    void *a = (void *)malloc(200 * sizeof(char));
    char *ch;
    int *jump;
    jump = a;
    ch = a + sizeof(int);
    scanf("%[^\n]%*c", ch);
    printf("Given string is : %s\n", ch);
    *jump = strl(ch);
    a = realloc(a, ((*jump) * sizeof(char)) + sizeof(int));
    int i, j;
    for (i = 0; i < *jump; i++)
    {
        int count = 0;
        if (ch[i - 1] == ' ' || i == 0)
        {
            for (j = i; j < *jump; j++)
            {
                count++;
                if (ch[j] == ' ' || j == *jump - 1)
                {
                    if (ch[j + 1] == '\0')
                        count++;
                    printf("%d", count);
                    break;
                }
            }
        }
        if (ch[i] == ' ')
            continue;
        printf("%c", ch[i]);
    }
    free(a);
    return 0;
}
