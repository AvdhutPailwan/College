#include <stdio.h>
int pow1(int a, int b)
{
    int i, temp = 1;
    for (i = 0; i < b; i++)
    {
        temp = temp * a;
    }
    return temp;
}
int main()
{
    int m_size, rbits = 0, i, j, k;
    printf("Enter the size of message : ");
    scanf("%d", &m_size);
    while (1)
    {
        if ((m_size + rbits + 1) <= pow1(2, rbits))
            break;
        rbits++;
    }
    int msg[m_size + 1];
    printf("enter the message seperated by space : ");
    for (i = m_size; i >= 1; i--)
    {
        scanf("%d", &msg[i]);
    }
    printf("\n");
    int data[m_size + rbits + 1];
    int rc = 0;
    int m = 1;
    for (i = 1; i < m_size + rbits + 1; i++)
    {
        if (i == pow1(2, rc))
        {
            data[i] = 99;
            rc++;
        }
        else
        {
            data[i] = msg[m];
            m++;
        }
    }

    for (i = 1; i < m_size + rbits + 1; i++)
    {
        if (data[i] == 99)
        {
            int count = 0;
            for (j = i; j < m_size + rbits + 1; j++)
            {
                for (k = 0; k < i; k++)
                {
                    if (data[j] == 1)
                    {
                        count++;
                    }
                    j++;
                }
                j = j + i - 1;
            }
            if (count % 2 == 0)
            {
                data[i] = 0;
            }
            else
            {
                data[i] = 1;
            }
        }
    }
    printf("The generated codeword : ");
    for (i = m_size + rbits; i >= 1; i--)
    {
        printf("%d", data[i]);
    }
    printf("\n_____________________________________________________________________________\n");
    printf("enter the codeword received : ");
    for (i = m_size + rbits; i >= 1; i--)
    {
        scanf("%d", &data[i]);
    }

    int parities[rbits];
    for (i = 0; i < rbits; i++)
    {
        parities[i] = 0;
    }

    int c = 0;
    for (i = 1; i < m_size + rbits + 1; i++)
    {
        if (i == pow1(2, c))
        {
            int count = 0;
            for (j = i; j < m_size + rbits + 1; j++)
            {
                for (k = 0; k < i; k++)
                {
                    if (data[j] == 1)
                    {
                        count++;
                    }
                    j++;
                }
                j = j + i - 1;
            }
            if (data[i] == 1)
            {
                count--;
            }
            if (count % 2 == data[i])
            {
                parities[c] = 0;
            }
            else if (count % 2 != data[i])
            {
                parities[c] = 1;
            }
            c++;
        }
    }

    c = 0;
    for (i = 0; i < rbits; i++)
    {
        c += parities[i] * (pow1(2, i));
    }

    if (c == 0)
    {
        printf("no error\n");
        return 0;
    }
    printf("error at position : %d\n", c);
    if (data[c] == 0)
    {
        data[c] = 1;
    }
    else
    {
        data[c] = 0;
    }
    printf("code after error correction is : ");
    for (i = m_size + rbits; i >= 1; i--)
    {
        printf("%d", data[i]);
    }
    printf("\n");
    return 0;
}
