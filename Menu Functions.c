#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include "Structs.h"
#include "Menu Functions.h"
FILE *fbooks,*fmembers,*fborrows;
FILE *fbookstemp,*fmemberstemp,*fborrowstemp;
FILE *fbooksn;
FILE *fmembersn;
FILE *fborrowsn;
char password[]="orelse";
void mainmenu()
{
    char pass[50];
    char c;
    int counter=0;
    system("color 74");
    system("cls");
    loadborrowsinfo();
    fclose(fborrows);
    fclose(fborrowstemp);
    loadbooksinfo();
    fclose(fbooks);
    fclose(fbookstemp);
    loadmembersinfo();
    fclose(fmembers);
    fclose(fmemberstemp);
    closeallfiles();
    pos(37,3);
    printf("\t\t\t  MAIN MENU");
    pos(40,5);
    printf("Book Management (1)");
    pos(40,7);
    printf("Member Management (2)");
    pos(40,9);
    printf("Borrow Management (3)");
    pos(40,11);
    printf("Administrative Actions (4)");
    pos(40,13);
    printf("Print books,Members or Borrows (5)");
    pos(40,15);
    printf("Save Changes (6)");
    pos(40,17);
    printf("Exit (7)");
    pos(40,20);
    printf("Please choose an option: ");
    switch(getch())
    {
        case '1':
        bookmenu();
        break;
        case '2':
        membermenu();
        break;
        case '3':
        borrowmenu();
        break;
        case '4':
            system("cls");
            printf("Enter the Admin's Password: ");
            while((c=getch())!=13){ //13 is the ASCI code of Enter
                if(counter<0)
                    counter=0;
                if(c==8) //8 is the ASCI code of backspace
                {
                    putch('\b');  /*\b does a backspace and a NULL after it makes it remove a character before it and another \b to make the cursor return one move*/
                    putch(NULL);
                    putch('\b');
                    counter--;
                    continue;
                }
                pass[counter]=c;
                counter++;
                putch('*');
            }
            pass[counter]='\0';
        if(strcasecmp(password,pass)==0)
        adminmenu();
        else{
            printf("Invalid password!!\n");
            printf("press any key to return to Main Menu");
            getch();
            mainmenu();
        }
        break;
        case '5':
        printmenu();
        break;
        case '6':
        savemenu();
        break;
        case '7':
        exitmenu();
        break;
        default:
        {
        pos(40,22);
        printf("Error!!");
        pos(40,23);
        printf("Please select one of the above options.");
        pos(40,24);
        printf("Press any key to continue...");
        if(getch()){
        mainmenu();
        }
        }
    }
}
void printmenu()
{
    system("cls");
    pos(37,3);
    printf("\t\t\t  Print Menu");
    pos(40,5);
    printf("Print all Books (1)");
    pos(40,7);
    printf("Print all Members (2)");
    pos(40,9);
    printf("Print all Borrows (3)");
    pos(40,11);
    printf("Return to Main Menu (4)");
    pos(40,13);
    printf("Please Enter an option: ");
    switch(getch())
    {
        case '1':
        printallbooks();
        printf("\nPress any key to return to main menu...");
        getch();
        mainmenu();
        break;
        case '2':
        printallmembers();
        break;
        case '3':printallborrows();
        break;
        case '4':
        mainmenu();
        break;
        default:
        {
        pos(40,22);
        printf("Error!!");
        pos(40,23);
        printf("Please select one of the above options.");
        pos(40,24);
        printf("Press any key to continue...");
        if(getch()){
        mainmenu();
        }
        }
    }

}
void bookmenu()
{
     char pass[50];
    char c;
    int counter=0;
    system("cls");
    pos(37,3);
    printf("\t\t\t  Book Management");
    pos(40,5);
    printf("Insert a Book (1)");
    pos(40,7);
    printf("Search For a Book (2)");
    pos(40,9);
    printf("Add a New Copy (3)");
    pos(40,11);
    printf("Delete a Book (4)");
    pos(40,13);
    printf("Return To Main Menu (5)");
    pos(40,15);
    printf("Please choose an option: ");
    switch(getch())
    {
        case '1':
        addbook();
        break;
        case '2':
        searchmenu();
        break;
        case '3':
        addcopy();
        break;
        case '4':
            system("cls");
            printf("Enter the Admin's Password: ");
            while((c=getch())!=13){ //13 is the ASCI code of Enter
                if(counter<0)
                    counter=0;
                if(c==8) //8 is the ASCI code of backspace
                {
                    putch('\b');  /*\b does a backspace and a NULL after it makes it remove a character before it and another \b to make the cursor return one move*/
                    putch(NULL);
                    putch('\b');
                    counter--;
                    continue;
                }
                pass[counter]=c;
                counter++;
                putch('*');
            }
            pass[counter]='\0';
        if(strcasecmp(password,pass)==0)
        deletebook();
        else{
            printf("Invalid password!!\n");
            printf("press any key to return to Book Management Menu");
            getch();
            bookmenu();
        }
        break;
        case '5':
            mainmenu();
        break;
        default:
        {
        pos(40,22);
        printf("Error!!");
        pos(40,23);
        printf("Please select one of the above options.");
        pos(40,24);
        printf("Press any key to continue...");
        if(getch()){
        bookmenu();
        }
        }
    }
}
void membermenu()
{
      char pass[50];
    char c;
    int counter=0;
    system("cls");
    pos(37,3);
    printf("\t\t\t  Member Management");
    pos(40,5);
    printf("Register a New Member (1)");
    pos(40,7);
    printf("Remove a Member (2)");
    pos(40,9);
    printf("Return To Main Menu (3)");
    pos(40,11);
    printf("Please choose an option: ");
        switch(getch())
    {
        case '1':
        reg();
        break;
        case '2':
            system("cls");
            printf("Enter the Admin's Password: ");
            while((c=getch())!=13){ //13 is the ASCI code of Enter
                if(counter<0)
                    counter=0;
                if(c==8) //8 is the ASCI code of backspace
                {
                    putch('\b');  /*\b does a backspace and a NULL after it makes it remove a character before it and another \b to make the cursor return one move*/
                    putch(NULL);
                    putch('\b');
                    counter--;
                    continue;
                }
                pass[counter]=c;
                counter++;
                putch('*');
            }
            pass[counter]='\0';
        if(strcasecmp(password,pass)==0)
        removemem();
        else{
            printf("Invalid password!!\n");
            printf("press any key to return to Member Management Menu");
            getch();
            membermenu();
        }
        break;
        case '3':
        mainmenu();
        break;
        default:
        {
        pos(40,22);
        printf("Error!!");
        pos(40,23);
        printf("Please select one of the above options.");
        pos(40,24);
        printf("Press any key to continue...");
        if(getch()){
        membermenu();
        }
        }
    }
}
void borrowmenu()
{
    system("cls");
    pos(37,3);
    printf("\t\t\t  Borrow Management");
    pos(40,5);
    printf("Borrow a Book (1)");
    pos(40,7);
    printf("Return a Book (2)");
    pos(40,9);
    printf("Return To Main Menu (3)");
    pos(40,11);
    printf("Please choose an option: ");
    switch(getch())
    {
        case '1':
        borrowbook();
        break;
        case '2':
        returnbook();
        break;
        case '3':
        mainmenu();
        break;
        default:
        {
        pos(40,22);
        printf("Error!!");
        pos(40,23);
        printf("Please select one of the above options.");
        pos(40,24);
        printf("Press any key to continue...");
        if(getch()){
        borrowmenu();
        }
        }
    }
}
void adminmenu()
{
    system("cls");
    pos(37,3);
    printf("\t\t\t  Administrative Actions");
    pos(40,5);
    printf("Overdue Books (1)");
    pos(40,7);
    printf("The Most Popular Books (2)");
    pos(40,9);
    printf("Return To Main Menu (3)");
    pos(40,11);
    printf("Please choose an option: ");
    switch(getch())
    {
        case '1':
        overdue();
        break;
        case '2':
        popular();
        break;
        case '3':
        mainmenu();
        break;
        default:
        {
        pos(30,22);
        printf("Error!!");
        pos(30,23);
        printf("Please select one of the above options.");
        pos(30,24);
        printf("Press any key to continue...");
        if(getch()){
        adminmenu();
        }
        }
    }
}
void exitmenu()
{
    system("cls");
    pos(37,3);
    printf("\t\t\t  Exit");
    pos(40,5);
    printf("Save And Exit (1)");
    pos(40,7);
    printf("Exit Without Saving (2)");
    pos(40,9);
    printf("Return To Main Menu (3)");
    pos(40,11);
    printf("Please choose an option: ");
    switch(getch())
    {
        case '1':
            save_exit();
        break;
        case '2':
        dsave_exit();
        break;
        case '3':
        mainmenu();
        break;
        default:
        {
        pos(40,22);
        printf("Error!!");
        pos(40,23);
        printf("Please select one of the above options.");
        pos(40,24);
        printf("Press any key to continue...");
        if(getch()){
        exitmenu();
        }
        }
    }
}
void savemenu()
{
    system("cls");
    pos(37,3);
    printf("\t\t\t Save Changes Menu");
    pos(40,5);
    printf("Save Books (1)");
    pos(40,7);
    printf("Save Members (2)");
    pos(40,9);
    printf("Save Borrows (3)");
    pos(40,11);
    printf("Save All (4)");
    pos(40,13);
    printf("Return to Main Menu (5)");
    pos(40,15);
    printf("Please choose an option: ");
    switch(getch())
    {
        case '1':
            fbooks=fopen("books.txt","r");
            fbookstemp=fopen("bookstemp.txt","r");
            fbooksn=fopen("deletetemp.txt","r");
        if (fbooks != NULL && ( fbookstemp != NULL || fbooksn!=NULL))
    {
        fclose(fbookstemp);
        fclose(fbooks);
        fclose(fbooksn);
        savebooks();
        pos(40,16);
        printf("Books Saved successfully.");
        pos(40,18);
        printf("Press any key to return to main menu...");
        if(getch())
            mainmenu();
    }

        else
        {
            pos(40,16);
            printf("There is nothing to be saved !");
            pos(40,18);
            printf("press any key to continue...");
            fclose(fbooks);
            fclose(fbookstemp);
            fclose(fbooksn);
            if(getch())
                savemenu();
        }
        break;
        case '2':
            fmembers=fopen("members.txt","r");
            fmemberstemp=fopen("memberstemp.txt","r");
            fmembersn=fopen("memberscopy.txt","r");
        if (fmembers != NULL && (fmemberstemp != NULL || fmembersn!=NULL))
    {
        fclose(fmembers);
        fclose(fmemberstemp);
        fclose(fmembersn);
        savemembers();
        pos(40,16);
        printf("Members Saved successfully.");
        pos(40,18);
        printf("Press any key to return to main menu...");
        if(getch())
            mainmenu();
    }
        else
        {
            pos(40,16);
            printf("There is nothing to be saved !");
            pos(40,18);
            printf("press any key to continue...");
            fclose(fmembers);
            fclose(fmemberstemp);
            fclose(fmembersn);
            if(getch())
                savemenu();
        }
        fclose(fmembers);
        fclose(fmemberstemp);
        fclose(fmembersn);
        break;
        case '3':
             fborrows=fopen("borrows.txt","r");
            fborrowstemp=fopen("borrowstemp.txt","r");
            fborrowsn=fopen("borrowscopy.txt","r");
        if (fborrows != NULL && (fborrowstemp != NULL || fborrowsn!=NULL))
    {
        fclose(fborrows);
        fclose(fborrowstemp);
        fclose(fborrowsn);
        saveborrows();
        pos(40,16);
        printf("Borrows Saved successfully.");
        pos(40,18);
        printf("Press any key to return to main menu...");
        if(getch())
            mainmenu();
    }
        else
        {
            pos(40,16);
            printf("There is nothing to be saved !");
            pos(40,18);
            printf("press any key to continue...");
            fclose(fborrows);
            fclose(fborrowstemp);
            fclose(fborrowsn);
            if(getch())
                savemenu();
        }
        fclose(fborrows);
        fclose(fborrowstemp);
        fclose(fborrowsn);
        break;
        case '4':saveall();
        pos(40,18);
        printf("Press any key to return to Main Menu...");
        if(getch())
            mainmenu();
            break;
        case '5':mainmenu();
        break;
        default:
            {
                pos(40,16);
                printf("Wrong input,Enter any key to continue...");
                if(getch())
                    savemenu();
            }
    }
}



void save_exit()
{
    system("cls");
    pos(37,3);
    printf("\t\t\tExit With Saving Menu");
    pos(40,5);
    printf("Exit with saving (1)");
    pos(40,7);
    printf("Return to Exit menu (2)");
    pos(40,9);
    printf("Please choose an option: ");
    switch(getch())
    {
        case '1':saveall();
        exit(1);
        break;
        case '2':exitmenu();
        break;
        default:
            {
                pos(40,11);
                printf("Wrong input,Enter any key to continue...");
                if(getch())
                    save_exit();
            }
    }
}
void dsave_exit()
{
    system("cls");
    pos(37,3);
    printf("\t\t\tExit Without Saving Menu");
    pos(40,5);
    printf("Exit without saving (1)");
    pos(40,7);
    printf("Return to Exit menu (2)");
    pos(40,9);
    printf("Please choose an option: ");
    switch(getch())
    {
        case '1':
            exitwithoutsaving();
        break;
        case '2':exitmenu();
        break;
        default:
            {
                pos(40,11);
                printf("Wrong input,Enter any key to continue...");
                if(getch())
                    dsave_exit();
            }
    }
}

void searchmenu()
{
    system("cls");
    pos(37,3);
    printf("\t\t\t  Search Menu");
    pos(40,5);
    printf("Search by Book's title (1)");
    pos(40,7);
    printf("Search by Author's Name (2)");
    pos(40,9);
    printf("Search by ISBN (3)");
    pos(40,11);
    printf("Search by Category (4)");
    pos(40,15);
    printf("Return to Book Management Menu (5)");
    pos(40,17);
    printf("Please Choose an Option: ");
    switch(getch())
    {
        case '1':
            searchtitle();
        break;
        case '2':searchauthor();
        break;
        case '3':
        searchisbninsmenu();
        break;
        case '4':searchcategory();
        break;
        case '5':
        bookmenu();
        break;
        default:
        {
        pos(30,22);
        printf("Error!!");
        pos(30,23);
        printf("Please select one of the above options.");
        pos(30,24);
        printf("Press any key to continue...");
        if(getch()){
        searchmenu();
        }
        }
    }

}


