#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{
            int  Data;
            struct Node *Next;
};

void  Insert_First( struct Node  **First  ,  int  No )
{
            struct Node *NewN = NULL;                                                  // Creating  Pointer for New Node

            NewN = (struct Node*)malloc(sizeof(struct Node));                          // Allocation Dynamic Memory for New Node in Data Section (Heap) by malloc

            NewN ->Data = No;
            NewN ->Next = NULL;                                                        //  Setting Values to New Node

            if( NULL == *First )                                                       // Only Once means for inserting very 1st element in LL
            {
                        *First  =  NewN;
                        NewN -> Next = NewN;
                        printf("\n\n Inside if block of insert first");
            }
            else                                                                       // Works for every next element i.e. from 2nd elements onwards
            {
                    struct Node *Temp = *First;

                    while( Temp -> Next != *First )
                    {
                        Temp = Temp -> Next;
                    }

                    NewN -> Next = *First;
                    *First = NewN;

                    Temp -> Next = NewN;
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

                            struct Node *Temp = First;

                            do
                            {
                                        printf("  | %d |  ->", First -> Data);
                                        First = First -> Next;
                            }while( First != Temp );
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
