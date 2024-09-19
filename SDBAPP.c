#include "STD.h"
Bool validateMenuEntry(int n)
{
    if(n>=0 && n<=7)
        return True;
    else
    {
        printf("Invalid Input!\n");
        return False;
    }
}
void SDB_APP()
{
    while(1)
    {
        int x = -1;
        printf("To add entry, enter 1\n");
        printf("To get used size in database, enter 2\n");
        printf("To read student data, enter 3\n");
        printf("To get list of all student IDS, enter 4\n");
        printf("To check if id exists, enter 5\n");
        printf("To delete student data, enter 6\n");
        printf("To check if data base is full, enter 7\n");
        printf("To exit, enter 0\n");
        do
        {
            printf("Choice: ");
            scanf("%d", &x);
        } while(!validateMenuEntry(x));
        SDB_action(x);
    }
}
void SDB_action(uint8 choice)
{
    int id;
    int list[6], count=0;
    switch(choice)
    {
        case 0: exit(1);
                break;
        case 1: if(SDB_AddEntry()) printf("Data is saved\n"); else printf("Data is not saved\n");
        printf("\nClick enter to continue");
                getchar(); getchar();
                system("cls");
                break;
        case 2: printf("Used size is %d\n", SDB_GetUsedSize());
                printf("\nClick enter to continue");
                getchar(); getchar();
                system("cls");
                break;
        case 3: printf("Enter student id to search: ");
                scanf("%d", &id);
                if(!SDB_ReadEntry(id)) printf("Account not found\n");
                printf("\nClick enter to continue");
                getchar(); getchar();
                system("cls");
                break;
        case 4: SDB_GetList(&count,&list);
                for(int i=0;i<count;i++)
                    printf("%d ", list[i]);
                printf("\n");
                printf("\nClick enter to continue");
                getchar(); getchar();
                system("cls");
                break;
        case 5: printf("Enter id to check availability: ");
                scanf("%d", &id);
                if(SDB_IsIdExist(id)) printf("It is found!\n"); else printf("Id not found\n");
                printf("\nClick enter to continue");
                getchar(); getchar();
                system("cls");
                break;
        case 6: printf("Enter student id to delete: ");
                scanf("%d", &id);
                SDB_DeleteEntry(id);
                printf("\nClick enter to continue");
                getchar(); getchar();
                system("cls");
                break;
        case 7: if(SDB_isFull()) printf("Database full\n"); else printf("Database not full\n");
                printf("\nClick enter to continue");
                getchar(); getchar();
                system("cls");
                break;
    }
}
