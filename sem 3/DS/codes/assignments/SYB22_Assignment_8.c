// *------------ SYB22 Avdhut Pailwan ----------------*
// todo : graph implementation using adjcency matrix

#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n = 5;                            // No. of nodes
    char a[n]; // Node
    int mat[n][n];  // Adjecency matrix
    int i, j, k,src;    // iterators
    printf("Enter values of nodes : ");
    for(i=0;i<n;i++){
      
      if (scanf("%c",&a[i]) == 1) {
          getchar();
      } else {
          i--;
      }
    }
    printf("Enter the index of start node : ");
    while(1){
      if(scanf("%d",&src)==1)break;
      else {
        printf("\nenter again : ");
        getchar();
      }
    }

    // initialization of matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            mat[i][j] = 0;
        }
    }
    // Edges between
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            printf("edge is present between %c and %c? [1/0] :     ", a[i], a[j]);
          if (scanf("%d", &mat[i][j]) == 1) {
              
          } else {
              j--;
          }
            
            mat[j][i] = mat[i][j];
        }
    }

    // matrix multiplication for path length calculation
    bool flag = true;
    int sum[n][n];   // it will check when all the possible paths are traced.
    //initializing the sum matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            sum[i][j] = mat[i][j];
        }
    }
    int count = 1;  // it will track the path length
    // path length calculation 
    while (flag)
    {
        int mul[n][n], temp[n][n],skip[n];
        for(i=0;i<n;i++){
          skip[i]=0;
        }
        bool zero = false;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                mul[i][j] = 0;
            }
        }
        if (count == 1)
        {
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < n; j++)
                {
                    temp[i][j] = mat[i][j];
                }
            }
        }

        for (i = 0; i < n; i++)
        {
            bool flag3 = false;
            if(src == i){
              printf("\n%c-node has path length %d with node ", a[src], count);
              flag3=true;
            }
            int count2 = 0;
            for (j = 0; j < n; j++)
            {
                
                if (i == j)
                    continue;
                if (temp[i][j]==0)count2++;
                
                if (temp[i][j]>0 && flag3==true
                  )
                    printf("%c ", a[j]);
            }
          if(count2>=n)skip[i]=1;
        }
        printf("\n");
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                for (k = 0; k < n; k++)
                {
                    mul[i][j] += temp[i][k] * mat[k][j];
                }
            }
        }
        count = count+1;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                temp[i][j] = mul[i][j];
            }
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                sum[i][j] = sum[i][j] + temp[i][j];
            }
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (sum[i][j] == 0 && skip[i]==0)
                    zero = 1;
            }
        }
        if (!zero)
            break;
    }

    return 0;
}