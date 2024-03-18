#include"Singly_Linear_LL_Library\Singly_Linear_Link_List.C"

int main()
{
        char ch = '\0';
        int No = 0, Choice = 0, Loc = 0;
        struct Node *Head = NULL;

        while(1)
        {
            printf("\n\n ****** WELCOME Fork Infosystems Singly Linear LL Console App ****** \n");

            printf("\n Select Your Choice => ");
            printf("\n\t\t 1. Insert First ");
            printf("\n\t\t 2. Insert Last ");
            printf("\n\t\t 3. Insert At Position ");
            printf("\n\t\t 4. Delete First ");
            printf("\n\t\t 5. Delete Last ");
            printf("\n\t\t 6. Delete At Position ");
            printf("\n\t\t 7. Display Whole Link List ");
            printf("\n\t\t 8. Count Link List Nodes ");
            printf("\n\t\t 9. Delete All Nodes ");
            printf("\n\t\t 0. EXIT ");

            printf("\n\n Choice : ");
            scanf("%d",&Choice);

            switch(Choice)
            {
                    case 1:
                            printf("\n Enter a Number To Insert First in LL : ");
                            scanf("%d",&No);

                            Insert_First(&Head, No);

                            getch();
                            fflush(stdin);
                            system("cls");
                            break;
                    case 2:
                            printf("\n Enter a Number To Insert Last in LL : ");
                            scanf("%d",&No);

                            Insert_Last(&Head, No);

                            getch();
                            fflush(stdin);
                            system("cls");
                            break;
                    case 3:
                            printf("\n Enter Insertion Position For Node : ");
                            scanf("%d",&Loc);

                            printf("\n Enter a Number To Insert at %d Position in LL : ",Loc);
                            scanf("%d",&No);

                            Insert_At_Position(&Head, Loc, No);

                            getch();
                            fflush(stdin);
                            system("cls");
                            break;
                    case 4:
                            Delete_First(&Head);

                            getch();
                            fflush(stdin);
                            system("cls");
                            break;
                    case 5:
                            Delete_Last(&Head);

                            getch();
                            fflush(stdin);
                            system("cls");
                            break;
                    case 6:
                            printf("\n Enter Deleting Position For Node : ");
                            scanf("%d",&Loc);

                            Delete_At_Position(&Head, Loc);

                            getch();
                            fflush(stdin);
                            system("cls");
                            break;
                    case 7:
                            Display_LL(Head);

                            getch();
                            fflush(stdin);
                            system("cls");
                            break;
                    case 8:
                            printf("\n\n Count Of Elements in LL are : %d.", Count_LL_Nodes(Head));

                            getch();
                            fflush(stdin);
                            system("cls");
                            break;
                    case 9:
                            Free_All_Nodes(&Head);
                            printf("\n\n Link List All Nodes Deleted Successfully.");

                            getch();
                            fflush(stdin);
                            system("cls");
                            break;
                    case 0:
                            fflush(stdin);
                            printf("\n\n Are You Sure Want To Quit (Yes/No) : ");
                            ch = getchar();

                            if(ch == 'y' || ch == 'Y')
                            {
                                Free_All_Nodes(&Head);
                                goto Quit;
                            }

                            fflush(stdin);
                            system("cls");
                            break;
                    default:
                            printf("\n\n Invalid Choice Select Correct Choice...");

                            getch();
                            fflush(stdin);
                            system("cls");
                            break;
            }
        }


    Quit:
        printf("\n\n Thanks For Using Our Service...\n");
        getch();
        return 0;
}
