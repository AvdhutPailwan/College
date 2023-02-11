#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    // stuffing
    void *mem = malloc(200 * sizeof(char)); // initial memory assign to program
    int *len;                               // variable to store length of input
    len = mem;
    char *in; // array to store input
    in = mem + sizeof(int);
    printf("Enter the message :     ");
    scanf("%s", in); // message is taken
    *len = strlen(in);
    mem = realloc(mem, ((*len) * sizeof(char)) + sizeof(int) + ((*len) / 5)); // reallocating the memory so that memory can be saved
    char *stuffed = malloc(sizeof(mem));                                      // array to store stuffed code

    int i, j = 0, count = 0; // i for in array, j for stuffed array, count to stuff 0 after 5 ones

    for (i = 0; i < (*len); i++)
    {
        if (count == 5)
        {
            stuffed[j] = '0';
            j++;
            count == 0;
        }
        stuffed[j] = in[i];
        if (stuffed[j] == '1')
        {
            count++;
        }
        else
        {
            count = 0;
        }
        j++;
    }
    stuffed[j] = '\0'; // to locate end of string in stuffed
    printf("The stuffed code : %s\n", stuffed);
    free(mem);
    free(stuffed);
    // ---------------------------------------------------------------------------------

    // destuff
    char *rec = malloc(200 * sizeof(char));
    printf("Enter the received code :    ");
    scanf("%s", rec);
    int len2 = strlen(rec);
    rec = realloc(rec, len2 * sizeof(char));
    char *destuff = malloc(sizeof(rec));
    count = 0, j = 0;
    for (i = 0; i < (len2); i++)
    {
        if (count == 5)
        {
            j++;
            count == 0;
        }
        destuff[i] = rec[j];
        if (destuff[i] == '1')
        {
            count++;
        }
        else
        {
            count = 0;
        }
        j++;
    }
    destuff[i] = '\0';
    printf("The received code is :    %s\n", rec);
    printf("The destuffed code is :    %s\n", destuff);
    return 0;
}
