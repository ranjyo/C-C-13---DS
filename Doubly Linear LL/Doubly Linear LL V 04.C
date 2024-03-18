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

void  Insert_Last( struct Node  **First , int No )
{
            struct Node *NewN = NULL;

            NewN = (struct Node*)malloc(sizeof(struct Node));

            NewN -> Data = No;
            NewN -> Next = NULL;
            NewN -> Prev = NULL;

            if( NULL == *First )
            {
                        *First = NewN;
                        printf("\n\n Inside if block of Insert Last");
            }
            else
            {
                        struct Node *Temp = *First;

                        while(Temp -> Next != NULL)
                        {
                                    Temp = Temp -> Next;
                        }

                        Temp -> Next  = NewN;
                        NewN -> Prev = Temp;
            }

            printf("\n %d Element Inserted at Last Position Successfully", No);

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

int  Count_LL_Nodes(struct  Node  *First)
{
                int  Cnt = 0;

                while( First != NULL)
                {
                        Cnt++;
                        First = First -> Next;
                }

                return Cnt;
}


void  Delete_First(struct  Node **First)
{
                if(NULL  == *First)
                {
                            printf("\n Link List Already Empty , Can't Delete any Element!!!");
                }
                else
                {
                            struct Node *Temp = *First;

                            *First = Temp -> Next;

                            printf("\n\n Deleted First Element in LL is = %d.", Temp->Data);

                            free(Temp);

                            if(*First != NULL)
                            {
                                (*First) -> Prev = NULL;
                            }
                }

                return;
}

void  Delete_Last(struct Node  **First)
{
                if(NULL  == *First)
                {
                            printf("\n Link List Already Empty , Can't Delete any Element!!!");
                }
                else
                {
                            struct Node *Temp = *First;

                            if(Temp -> Next == NULL)
                            {
                                    *First = NULL;
                                    printf("\n\n Deleted First Element in LL is = %d.", Temp->Data);

                                    free(Temp);
                            }
                            else
                            {
                                    while(Temp -> Next -> Next != NULL)
                                    {
                                                Temp = Temp -> Next;
                                    }
                                    printf("\n\n Deleted Last Element in LL is = %d.", Temp->Next->Data);

                                    free(Temp->Next);

                                    Temp->Next = NULL;
                            }
                }

                return;
}


void  Insert_At_Position(struct Node **First, int Pos, int  Val)
{
                int Ele_Cnt = Count_LL_Nodes(*First);

                struct Node *NewN = NULL, *Temp = NULL;

                if(Pos <= 0 || Pos > Ele_Cnt + 1)
                {
                            printf("\n Invalid Position To Insert!!!");
                }
                else  if(Pos == 1)
                {
                            Insert_First(First, Val);
                }
                else if(Pos == Ele_Cnt + 1)
                {
                            Insert_Last(First, Val);
                }
                else
                {
                            NewN = (struct Node *)malloc(sizeof(struct Node));

                            NewN -> Prev = NULL;
                            NewN -> Data = Val;
                            NewN -> Next = NULL;

                            Temp = *First;

                            while( Pos > 2 )
                            {
                               Temp = Temp -> Next;
                               Pos--;
                            }

                            NewN -> Next = Temp -> Next;
                            NewN -> Prev = Temp;

                            (Temp -> Next) -> Prev = NewN;
                            Temp -> Next = NewN;

                            printf("\n %d Element Inserted at Given Position Successfully", Val);
                }

                return;
}


int main()
{
                struct Node *Head = NULL;

                Insert_Last(&Head, 10);
                Insert_First(&Head, 30);

                Insert_Last(&Head, 50);
                Insert_First(&Head, 45);
                Insert_Last(&Head, 40);

                Insert_At_Position(&Head, 0 , 55);
                Insert_At_Position(&Head, 1 , 15);

                Insert_At_Position(&Head, 2 , 41);

                Insert_At_Position(&Head, 5 , 101);
                Insert_At_Position(&Head, 1 , 21);

                Insert_At_Position(&Head, 3, 884);
                getch();

                system("cls");
                Display_LL(Head);
                getch();

                Delete_First(&Head);
                Delete_Last(&Head);

                Display_LL(Head);
                getch();
                printf("\n Element Count = %d.", Count_LL_Nodes(Head));
                getch();

                return 0;
}
