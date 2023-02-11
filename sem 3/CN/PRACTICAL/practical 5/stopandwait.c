#include <stdio.h>
#include <windows.h>
int main()
{
	int i, n;
	printf("Enter Number of frames to send :\t");
	scanf("%d", &n);
	int frame[n];
	printf("enter %d frames : ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &frame[i]);
	}

	for (i = 0; i < n; i++)
	{
		char ack = 'n';
		printf("\nsending frame %d", frame[i]);
		Sleep(2000);
		printf(".");
		Sleep(2000);
		printf(".");
		Sleep(2000);
		printf(".\n");
		Sleep(1000);
		printf("\n%d\tframe sent\n", frame[i]);
		Sleep(1000);
		while (ack == 'n' || ack == 'N')
		{
			getchar();
			printf("did you receive frame? [Y/n] :	");
			scanf("%c", &ack);
			if (ack == 'Y' || ack == 'y')
			{
				printf("\nack recived for %d\n", frame[i]);
				Sleep(1000);
			}
			else if (ack == 'n' || ack == 'N')
			{
				printf("\nack not received\n");
				Sleep(500);
				printf("\nsending frame %d again", frame[i]);
				Sleep(2000);
				printf(".");
				Sleep(2000);
				printf(".");
				Sleep(2000);
				printf(".\n");
				Sleep(2000);
				printf("\n%d\tframe sent\n", frame[i]);
				Sleep(1000);
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
