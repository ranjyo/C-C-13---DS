#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{
            struct Node *Prev;
            int  Data;
            struct Node *Next;
};

void  Insert_First( struct Node  **First  ,  int  No )
{
            struct Node *NewN = NULL;

            NewN = (struct Node*)malloc(sizeof(struct Node));

            NewN -> Data = No;
            NewN -> Next = NULL;
            NewN -> Prev = NULL;

            if( NULL == *First )
            {
                        *First = NewN;
                        printf("\n\n Inside if block of insert first");
            }
            else
            {
                        NewN -> Next = *First;
                        (*First)-> Prev = NewN;
                        *First = NewN;
            }

            printf("\n %d Element Inserted  at First Position Successfully", No);

            return;
}


void  Display_LL(struct  Node  *First)
{
                if( NULL == First )
                {
                            printf("\n Given Link List is Already Empty!!!");
                }
                else
                {
                            printf("\n Elements in Given Link List are => \n\t");

                            printf(" NULL <--> ");
                            while( First != NULL )
                            {
                                        printf("  | %d |  <-->", First -> Data);
                                        First = First -> Next;
                            }
                }
                printf(" NULL ");
                return;
}

int main()
{
                struct Node *Head = NULL;

                Display_LL(Head);
                getch();

                Insert_First(&Head, 10);

                Insert_First(&Head, 30);

                Insert_First(&Head, 50);

                Display_LL(Head);

                getch();

                return 0;
}
