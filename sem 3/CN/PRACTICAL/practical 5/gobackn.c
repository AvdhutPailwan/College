#include <stdio.h>
#include <windows.h>
int main()
{
	int i, n, w;
	printf("Enter Number of frames to send :\t");
	scanf("%d", &n);
	int frame[n];
	printf("enter %d frames :\t", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &frame[i]);
	}
	printf("enter window size :\t");
	scanf("%d", &w);
	for (i = 0; i < w; i++)
	{
		printf("\nsending frame %d", frame[i]);
		Sleep(2000);
		printf(".");
		Sleep(2000);
		printf(".");
		Sleep(2000);
		printf(".\n");
		Sleep(1000);
		printf("%d\tframe sent\n", frame[i]);
		Sleep(1000);
	}
	for (i = 0; i < n; i++)
	{
		char f = 'n';
		while (f == 'n' || f == 'N')
		{
			getchar();
			printf("\ndid you receive frame %d?    [Y/n] :\t", frame[i]);
			scanf("%c", &f);
			if (f == 'Y' || f == 'y')
			{
				printf("\nack recived for %d\n", frame[i]);
				Sleep(1000);
				if (i + w >= n)
					continue;
				printf("\nsending frame %d", frame[i + w]);
				Sleep(2000);
				printf(".");
				Sleep(2000);
				printf(".");
				Sleep(2000);
				printf(".\n");
				Sleep(1000);
				printf("%d\tframe sent\n", frame[i + w]);
				Sleep(1000);
			}
			else if (f == 'n' || f == 'N')
			{
				int j;
				printf("\nack not received\n");
				Sleep(500);
				for (j = i; j < i + w; j++)
				{
					if (j >= n)
						break;
					printf("\nsending frame %d again", frame[j]);
					Sleep(2000);
					printf(".");
					Sleep(2000);
					printf(".");
					Sleep(2000);
					printf(".\n");
					Sleep(2000);
					printf("%d\tframe sent\n", frame[j]);
					Sleep(1000);
				}
			}
			else
			{
				printf("invalid input\n");
			}
		}
	}
	printf("\nall frames sent successfully!\n");
	return 0;
}
