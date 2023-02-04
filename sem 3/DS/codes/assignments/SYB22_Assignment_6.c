#include <stdio.h>
#include <string.h>
#define I 0

struct lawyer
{
    char name[10];
    int firstClient;
} typedef lawyer;
struct client
{
    char name[10];
    int age;
    int nextClient;
} typedef client;
int return_fc(lawyer l[], char layr[], int i);
int return_lc(client c[], int travel);
int return_match(client c[], lawyer l[], char lyar[], char name[], int age);
int return_lawyer_index(lawyer l[], char layr[], int i);
int display_lawyer_client(client c[], lawyer l[]);
int insert_client(client c[], lawyer l[], int *avail);
int delete_record(client c[], int *avail, lawyer l[]);
void display_free_slot(client c[], int avail);
int main()
{
    lawyer l[4] = {{"Hall", 3}, {"Moss", 11}, {"Ford", 20}, {"Brown", 8}};
    client c[30] = {{"Hall", 35, 15}, {"Moss", 28, 12}, {"Ford", 47, 24}, {"Brown", 54, 21}, {"Gina", 38, 13}, {"Pride", 42, 28}, {"0", -1, 25}, {"Berk", 38, 2}, {"White", 45, -1}, {"0", -1, 27}, {"Todd", 25, -1}, {"Dixon", 32, 23}, {"Newman", 46, 5}, {"Harris", 42, 29}, {"0", -1, 6}, {"Jackson", 52, 26}, {"0", -1, 22}, {"Roberts", 40, -1}, {"0", -1, -1}, {"Eisen", 32, 0}, {"Adams", 48, 4}, {"Cohen", 36, 19}, {"0", -1, 18}, {"Fisher", 33, 17}, {"Graves", 42, 10}, {"0", -1, 9}, {"Parker", 50, 8}, {"0", -1, 16}, {"Singer", 45, -1}, {"Lewis", 28, 1}};
    int avail = 14;
    int flag = 1;
    while (flag)
    {
        printf("\nWhat would you like to do?\n1. display lawyer's clients list\n2. insert client info\n3. delete record of the client\n4. display free slots in the table\n5. stop\n  :   ");
        int op;
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            (display_lawyer_client(c, l)) ?: printf("\nInvalid Lawyer!\n");
            break;
        case 2:
            (insert_client(c, l, &avail)) ? printf("\nSUCCESS!\n") : printf("\nNo free slots!\n");
            break;
        case 3:
            (delete_record(c, &avail, l)) ? printf("\nSUCCESS!\n") : printf("\nInvalid Client!\n");
            break;
        case 4:
            display_free_slot(c,avail);
            break;
        case 5:
            flag = 0;
            break;

        default:
            break;
        }
    }
    return 0;
}
int return_fc(lawyer l[], char layr[], int i)
{
    if (i == 4)
        return -1;
    if (!strcmp(l[i].name, layr))
        return l[i].firstClient;
    return_fc(l, layr, i + 1);
}
int return_lc(client c[], int travel)
{
    if (c[travel].nextClient == -1)
        return travel;
    return_lc(c, c[travel].nextClient);
}
int return_match(client c[], lawyer l[], char lyar[], char name[], int age){
    int i,j;
    for(i = 0; i<4; i++){
        if(!strcmp(l[i].name,lyar))break;
    }
    if(i==4)return -1;
    j = l[i].firstClient;
    do{
        if((!(strcmp(name,c[j].name)))&& age == c[j].age)return j;
        j = c[j].nextClient;
    }while(j!=-1);
    if(j==-1)return -1;

}
int return_lawyer_index(lawyer l[], char layr[], int i){
    if (i == 4)
        return -1;
    if (!strcmp(l[i].name, layr))
        return i;
    return_fc(l, layr, i + 1);
}
int display_lawyer_client(client c[], lawyer l[])
{
    char layr[10];
    printf("Enter the name of the lawyer :  ");
    scanf("%s", layr);
    int travel;
    travel = return_fc(l, layr, I);
    if (travel == -1)
        return 0;
    printf("\naddr   name          age\n----------------------------------------------------------\n");
    while (c[travel].nextClient != -1)
    {
        printf("%-7d%-14s%d\n", travel, c[travel].name, c[travel].age);
        travel = c[travel].nextClient;
    }
    printf("%-7d%-14s%d\n\n", travel, c[travel].name, c[travel].age);

    return 1;
}
int insert_client(client c[], lawyer l[], int *avail)
{
    if (*avail == -1)
        return 0;
    char layr[10];
    printf("Enter the name of the lawyer :  ");
    scanf("%s", layr);
    int travel = return_fc(l, layr, I);
    travel = return_lc(c, travel);
    c[travel].nextClient = *avail;
    printf("enter the name of client : ");
    scanf("%s", c[*avail].name);
    printf("enter the age of client : ");
    scanf("%d", &c[*avail].age);
    travel = *avail;
    *avail = c[travel].nextClient;
    c[travel].nextClient = -1;
    return 1;
}
int delete_record(client c[], int *avail, lawyer l[])
{
	int del_age;
	char del_name[10];
    char lyar[10];
	int lfs = return_lc(c,*avail);
	printf("Enter the name of lawyer : ");
	scanf("%s",lyar);
	printf("Enter the name of client : ");
	scanf("%s",del_name);
	printf("Enter the age of client : ");
	scanf("%d",&del_age);
	int del_i = return_match(c,l,lyar,del_name,del_age);
    if(del_i == -1)return 0;
    int fc = return_fc(l,lyar,I);
    int li = return_lawyer_index(l,lyar,I);
	char tem[10] = "0";
	strcpy(c[del_i].name,tem);
	c[del_i].age = -1;
	int temp = c[del_i].nextClient;
	c[del_i].nextClient = -1;
	c[lfs].nextClient = del_i;
	int i;
    if(fc == del_i){
        l[li].firstClient = temp;
        return 1;
    }
	for(i =fc; c[i].nextClient!=del_i;i = c[i].nextClient );
    printf("\n%d\n",i);
    c[i].nextClient = temp;
	return 1;
	
}
void display_free_slot(client c[], int avail){
	int count = 0;
	while(c[avail].nextClient!=-1){
		avail = c[avail].nextClient;
		count++;
	}
	printf("\nfree slots : %d\n",count+1);
}
