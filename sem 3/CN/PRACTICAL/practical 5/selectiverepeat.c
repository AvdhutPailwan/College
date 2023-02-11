#include <stdio.h>
#include <windows.h>
int main()
{
	int i, n, w, j;
	printf("Enter Size of frame :\t");
	scanf("%d", &n);

	printf("enter window size :\t");
	scanf("%d", &w);

	for (i = 0; i < n; i = i + w)
	{
		for (j = i; j < i + w; j++)
		{
			if (j >= n)
				break;
			printf("\nsending frame %d", j);
			Sleep(2000);
			printf(".");
			Sleep(2000);
			printf(".");
			Sleep(2000);
			printf(".\n");
			Sleep(1000);
			printf("%d\tframe sent\n", j);
			Sleep(1000);
		}
		for (j = i; j < i + w; j++)
		{
			if (j >= n)
				break;
			char f = 'n';
			while (f == 'n' || f == 'N')
			{
				getchar();
				printf("\ndid you receive frame %d?    [Y/n] :\t", j);
				scanf("%c", &f);

				if (f == 'Y' || f == 'y')
				{
					printf("\nack%d received\n", j);

					Sleep(1000);
				}
				else if (f == 'n' || f == 'N')
				{
					printf("\nnck%d received\n", j);
					Sleep(500);
					printf("\nsending frame %d again", j);
					Sleep(2000);
					printf(".");
					Sleep(2000);
					printf(".");
					Sleep(2000);
					printf(".\n");
					Sleep(2000);
					printf("%d\tframe sent\n", j);
					Sleep(1000);
				}
				else
				{
					printf("invalid input\n");
				}
			}
		}
	}
	printf("\nall frames sent successfully!\n");
	return 0;
}
