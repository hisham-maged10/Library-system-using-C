#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include "Structs.h"
#include "Menu Functions.h"
#include "Books Functions.h"
#include "Members Functions.h"
#include "searchfunctions.h"
#include "borrows Functions.h"
#include "Admin Functions.h"
#include "Exit functions.h"
#include "print functions.h"
#include "validation functions.h"
#include "save functions.h"
#include "Loadinfo.h"
FILE *fbooks;
FILE *fbookstemp;
book books[100];
int i=0,sb=0;
int savei=NULL;
char decreasethisisbn[50];
FILE *fbooksn;

int readbooks()
{
    return fopen("books.txt","r");
}
int writebooks()
{
    return fopen("books.txt","w");
}
void loadbooksinfo()
{
    book x[100];
    fbooks=readbooks();
    fbookstemp=fopen("bookstemp.txt","r");
    if(fbookstemp==NULL)
    {
    if(fbooks==NULL)
    {
        i=0;
        savei=-1;
        fclose(fbooks);
        fclose(fbookstemp);
        closeallfiles();
        return;
    }
    else
    {
        fseek(fbooks,0,SEEK_SET);
        while(!(feof(fbooks)))
        {

        if(savei!=NULL)
        {
            i++;
            break;
        }
        fscanf(fbooks,"%[^,],%[^,],%[^,],%[^,],%[^,],%d,%d,%d,%[^\n]",x[sb].title,x[sb].author,x[sb].publisher,x[sb].ISBN,x[sb].compdate,&x[sb].noc,&x[sb].avail,&x[sb].rank,x[sb].category);

        books[i]=x[sb];
        sb++;
        i++;
        }
        fclose(fbooks);
        fclose(fbookstemp);
        closeallfiles();
        i--;
        savei=i;
        savei--;
    }
    }
    else
    {
        fseek(fbookstemp,0,SEEK_SET);
        while(!(feof(fbookstemp)))
        {
        fscanf(fbookstemp,"%[^,],%[^,],%[^,],%[^,],%[^,],%d,%d,%d,%[^\n]",x[sb].title,x[sb].author,x[sb].publisher,x[sb].ISBN,x[sb].compdate,&x[sb].noc,&x[sb].avail,&x[sb].rank,x[sb].category);
        books[i]=x[sb];
        sb++;
        i++;
        }
        fclose(fbookstemp);
        fclose(fbooks);
        i--;
    }
}
void addbook()
{
    system("cls");
    book b;
    int check;
    char checkenter;
    fbooks=readbooks();
    fbookstemp=fopen("bookstemp.txt","r");
    pos(37,3);
    printf("\t\t\t Add Book Menu");
    if(fbooks==NULL)
    {
    fbooks=writebooks();
    if(fbookstemp==NULL)
    {
    fbookstemp=fopen("bookstemp.txt","a+");
    }
    else
    {
    fbookstemp=fopen("bookstemp.txt","a");
    }
    fclose(fbooks);
    pos(40,5);
    printf("Enter The title of the book: ");
    fflush(stdin);
    gets(b.title);
    /*  check=validatestringallchar(b.title);
    if(check==1)
     {  do{
        printf("Wrong input, Enter again: ");
        fflush(stdin);
        gets(b.title);
        check=validatestringallchar(b.title);
         }while(check==1);
     }*/
    pos(40,7);
    printf("Enter the Author: ");
    fflush(stdin);
    gets(b.author);
    check=validatestringallchar(b.author);
     if(check==1)
     {  do{
        printf("Wrong input, Enter again: ");
        fflush(stdin);
        gets(b.author);
        check=validatestringallchar(b.author);
         }while(check==1);
     }
    pos(40,9);
    printf("Enter the Publisher: ");
    fflush(stdin);
    gets(b.publisher);
    check=validatestringallchar(b.publisher);
     if(check==1)
     {  do{
        printf("Wrong input, Enter again: ");
        fflush(stdin);
        gets(b.publisher);
        check=validatestringallchar(b.publisher);
         }while(check==1);
     }
    pos(40,11);
    printf("Enter the ISBN: ");
    fflush(stdin);
    scanf("%s",b.ISBN);
    if(checkisbnindex(b.ISBN)==0)
    {
    pos(40,13);
    printf("Enter the Date of Publication: ");
    pos(40,14);
    printf("Month: ");
    fflush(stdin);
    scanf("%d",&b.published.m);
    check=checkmonth(b.published.m);
     if(check==0)
        do
    {
        printf("invalid month entry!!\n");
        printf("Enter month number (1-12): ");
        scanf("%d",&b.published.m);
        check=checkmonth(b.published.m);

    }while(check==0);
    pos(40,15);
    printf("Day: ");
    fflush(stdin);
    scanf("%d",&b.published.d);
    check=checkdaymonth(b.published.m,b.published.d);
    if(check==0)
        do
    {
        printf("invalid day entry!!\n");
        printf("Enter Day number: ");
        scanf("%d",&b.published.d);
        check=checkdaymonth(b.published.m,b.published.d);

    }while(check==0);
    pos(40,16);
    printf("Year: ");
    fflush(stdin);
    scanf("%d",&b.published.y);
    check=checkyear(b.published.y);
    if(check==0)
        do
    {
        printf("invalid Year entry!!\n");
        printf("Enter Year: ");
        scanf("%d",&b.published.y);
        check=checkyear(b.published.y);

    }while(check==0);
    pos(40,18);
    printf("Enter The Number of copies: ");
    fflush(stdin);
    scanf("%d",&b.noc);
    pos(40,20);
    printf("Enter The Current available number of copies: ");
    fflush(stdin);
    scanf("%d",&b.avail);
    check=checkavail(b.noc,b.avail);
    if(check==0)
        do
    {
        printf("invalid Number of Available Copies!!\n");
        printf("Enter Available Number of Copies: ");
        scanf("%d",&b.avail);
        check=checkavail(b.noc,b.avail);

    }while(check==0);
    pos(40,21);
    printf("Enter the book's Category: ");
    fflush(stdin);
    scanf("%s",b.category);
     check=validatestringallchar(b.category);
     if(check==1)
     {  do{
        printf("Wrong input, Enter again: ");
        fflush(stdin);
        gets(b.category);
        check=validatestringallchar(b.category);
         }while(check==1);
     }
    b.rank=0;
    fprintf(fbookstemp,"%s,%s,%s,%s,%d/%d/%d,%d,%d,%d,%s\n",b.title,b.author,b.publisher,b.ISBN,b.published.d,b.published.m,b.published.y,b.noc,b.avail,b.rank,b.category);
    fclose(fbookstemp);
    books[i]=b;
    loadbooksinfo();
    fclose(fbookstemp);
    i++;
    fclose(fbookstemp);
    closeallfiles();
    fclose(fbookstemp);
    }
    else
    {
        pos(40,13);
        printf("This ISBN already Exists!!");
        pos(40,14);
        printf("Press any key to return to Book Management Menu...");
        fclose(fbookstemp);
        closeallfiles();
        getch();
        bookmenu();
    }
    }
    else{
    fbooks=fopen("books.txt","a");
    if(fbookstemp==NULL)
    {
    fbookstemp=fopen("bookstemp.txt","a+");
    }
    else
    {
    fbookstemp=fopen("bookstemp.txt","a");
    }
    fclose(fbooks);
    pos(40,5);
    printf("Enter The title of the book: ");
    fflush(stdin);
    gets(b.title);
  /*   check=validatestringallchar(b.title);
     if(check==1)
     {  do{
        printf("Wrong input, Enter again: ");
        fflush(stdin);
        gets(b.title);
        check=validatestringallchar(b.title);
         }while(check==1);
     }*/
    pos(40,7);
    printf("Enter the Author: ");
    fflush(stdin);
    gets(b.author);
     check=validatestringallchar(b.author);
     if(check==1)
     {  do{
        printf("Wrong input, Enter again: ");
        fflush(stdin);
        gets(b.author);
        check=validatestringallchar(b.author);
         }while(check==1);
     }
    pos(40,9);
    printf("Enter the Publisher: ");
    fflush(stdin);
    gets(b.publisher);
     check=validatestringallchar(b.publisher);
     if(check==1)
     {  do{
        printf("Wrong input, Enter again: ");
        fflush(stdin);
        gets(b.publisher);
        check=validatestringallchar(b.publisher);
         }while(check==1);
     }
    pos(40,11);
    printf("Enter the ISBN: ");
    fflush(stdin);
    scanf("%s",b.ISBN);
    if(checkisbnindex(b.ISBN)==0)
    {
        pos(40,13);
    printf("Enter the Date of Publication: ");
    pos(40,14);
    printf("Month: ");
    fflush(stdin);
    scanf("%d",&b.published.m);
    check=checkmonth(b.published.m);
     if(check==0)
        do
    {
        printf("invalid month entry!!\n");
        printf("Enter month number (1-12): ");
        scanf("%d",&b.published.m);
        check=checkmonth(b.published.m);

    }while(check==0);
    pos(40,15);
    printf("Day: ");
    fflush(stdin);
    scanf("%d",&b.published.d);
    check=checkdaymonth(b.published.m,b.published.d);
    if(check==0)
        do
    {
        printf("invalid day entry!!\n");
        printf("Enter Day number: ");
        scanf("%d",&b.published.d);
        check=checkdaymonth(b.published.m,b.published.d);

    }while(check==0);
    pos(40,16);
    printf("Year: ");
    fflush(stdin);
    scanf("%d",&b.published.y);
    check=checkyear(b.published.y);
    if(check==0)
        do
    {
        printf("invalid Year entry!!\n");
        printf("Enter Year: ");
        scanf("%d",&b.published.y);
        check=checkyear(b.published.y);

    }while(check==0);
    pos(40,18);
    printf("Enter The Number of copies: ");
    fflush(stdin);
    scanf("%d",&b.noc);
    pos(40,20);
    printf("Enter The Current available number of copies: ");
    fflush(stdin);
    scanf("%d",&b.avail);
    check=checkavail(b.noc,b.avail);
    if(check==0)
        do
    {
        printf("invalid Number of Available Copies!!\n");
        printf("Enter Available Number of Copies: ");
        scanf("%d",&b.avail);
        check=checkavail(b.noc,b.avail);

    }while(check==0);
    pos(40,21);
    printf("Enter the book's Category: ");
    fflush(stdin);
    scanf("%s",b.category);
     check=validatestringallchar(b.category);
     if(check==1)
     {  do{
        printf("Wrong input, Enter again: ");
        fflush(stdin);
        gets(b.category);
        check=validatestringallchar(b.category);
         }while(check==1);
     }
    b.rank=0;
    fprintf(fbookstemp,"%s,%s,%s,%s,%d/%d/%d,%d,%d,%d,%s\n",b.title,b.author,b.publisher,b.ISBN,b.published.d,b.published.m,b.published.y,b.noc,b.avail,b.rank,b.category);
    fclose(fbookstemp);
    books[i]=b;
    loadbooksinfo();
    fclose(fbookstemp);
    i++;
    fclose(fbookstemp);
    closeallfiles();
    fclose(fbookstemp);
    }
    else
    {
        pos(40,13);
        printf("This ISBN already Exists!!");
        pos(40,14);
        printf("Press any key to return to Book Management Menu...");
        fclose(fbookstemp);
        closeallfiles();
        getch();
        bookmenu();
    }

    }
    printf("press any key to return to book management menu");
    getch();
    bookmenu();

}
void searchauthor()
{
    system("cls");
    int si=0;
    int authorcounter=0;
    int savecounter=0;
    int poscounter=9;
    int nullcounter=NULL;
    char searchtarget[50];
    pos(37,3);
    printf("\t\t\t Search by Author's Name");
    pos(40,5);
    printf("Enter the Author's Name: ");
    fflush(stdin);
    gets(searchtarget);
    for(si=0;si<=savei;si++)
    {
        if(strcasecmp(searchtarget,books[si].author) == 0)
        {
            authorcounter++;
            nullcounter++;
        }
    }
    if(nullcounter!=NULL)
    {
        book authordata[authorcounter];
        for(si=0;si<=savei;si++)
        {
        if(strcasecmp(searchtarget,books[si].author) == 0)
        {
            strcpy(authordata[savecounter].title,books[si].title);
            strcpy(authordata[savecounter].author,books[si].author);
            strcpy(authordata[savecounter].publisher,books[si].publisher);
            strcpy(authordata[savecounter].ISBN,books[si].ISBN);
            strcpy(authordata[savecounter].compdate,books[si].compdate);
            authordata[savecounter].noc=books[si].noc;
            authordata[savecounter].avail=books[si].avail;
            strcpy(authordata[savecounter].category,books[si].category);
            savecounter++;
        }
        }
        pos(37,7);
        printf("\t\t\t The List of books found (%d found)",savecounter);
        pos(37,8);
        printf("\t\t\t ----------------------------------");
        pos(0,poscounter);
        for(si=0;si<savecounter;si++)
        {
            printf("%s, %s, %s, %s, %s, %d, %d, %s\n",authordata[si].title,authordata[si].author,authordata[si].publisher,authordata[si].ISBN,authordata[si].compdate,authordata[si].noc,authordata[si].avail,authordata[si].category);
            poscounter++;
        }
        pos(37,(poscounter+5));
        printf("Enter any key to return to search menu..");
        if(getch())
            searchmenu();
    }
    else{
        pos(37,6);
        printf("There is no books that matches that request !! ");
        pos(37,8);
        printf("Enter any key to return to search menu..");
        if(getch())
        searchmenu();
}

}
void searchcategory()
{
    system("cls");
    int si=0;
    int catgcounter=0;
    int savecounter=0;
    int poscounter=9;
    int nullcounter=NULL;
    char searchtarget[50];
    pos(37,3);
    printf("\t\t\t Search by Book's Category");
    pos(40,5);
    printf("Enter the Book's Category: ");
    fflush(stdin);
    gets(searchtarget);
    for(si=0;si<=savei;si++)
    {
        if(strcasecmp(searchtarget,books[si].category) == 0)
        {
            nullcounter++;
            catgcounter++;
        }
    }
    if(nullcounter!=NULL)
    {
        book authordata[catgcounter];
        for(si=0;si<=savei;si++)
        {
        if(strcasecmp(searchtarget,books[si].category) == 0)
        {
            strcpy(authordata[savecounter].title,books[si].title);
            strcpy(authordata[savecounter].author,books[si].author);
            strcpy(authordata[savecounter].publisher,books[si].publisher);
            strcpy(authordata[savecounter].ISBN,books[si].ISBN);
            strcpy(authordata[savecounter].compdate,books[si].compdate);
            authordata[savecounter].noc=books[si].noc;
            authordata[savecounter].avail=books[si].avail;
            strcpy(authordata[savecounter].category,books[si].category);
            savecounter++;
        }
        }
        pos(37,7);
        printf("\t\t\t The List of books found (%d found)",savecounter);
        pos(37,8);
        printf("\t\t\t ----------------------------------");
        pos(0,poscounter);
        for(si=0;si<savecounter;si++)
        {
            printf("%s, %s, %s, %s, %s, %d, %d, %s\n",authordata[si].title,authordata[si].author,authordata[si].publisher,authordata[si].ISBN,authordata[si].compdate,authordata[si].noc,authordata[si].avail,authordata[si].category);
            poscounter++;
        }
        pos(37,(poscounter+5));
        printf("Enter any key to return to search menu..");
        if(getch())
            searchmenu();
    }
    else{
        pos(37,6);
        printf("There is no books that matches that request !! ");
        pos(37,8);
        printf("Enter any key to return to search menu..");
        if(getch())
        searchmenu();
}
}
void searchisbninsmenu()
{
    system("cls");
    int si=0;
    int nullcounter=NULL;
    int neededcounter;
    char searchtarget[50];
    pos(37,3);
    printf("\t\t\t Search by ISBN");
    pos(40,5);
    printf("Enter the Book's ISBN: ");
    fflush(stdin);
    scanf("%s",searchtarget);
    for(si=0;si<=savei;si++)
    {
        if(strcasecmp(searchtarget,books[si].ISBN) == 0)
        {   nullcounter++;
            neededcounter=si;
            break;
        }
    }
    if(nullcounter!=NULL)
    {
        pos(40,7);
        printf("The book is found!");
        pos(40,9);
        printf("The book's Information\n");
        pos(37,11);
        printf("Title: %s",books[neededcounter].title);
        pos(37,13);
        printf("Author: %s",books[neededcounter].author);
        pos(37,15);
        printf("Publisher: %s",books[neededcounter].publisher);
        pos(37,17);
        printf("ISBN: %s",books[neededcounter].ISBN);
        if(books[neededcounter].compdate==NULL){
        pos(37,19);
        printf("Date of Publication: %d/%d/%d",books[neededcounter].published.d,books[neededcounter].published.m,books[neededcounter].published.y);
        }else{
        pos(37,19);
        printf("Date of Publication: %s",books[neededcounter].compdate);
        }
        pos(37,21);
        printf("Number of copies: %d",books[neededcounter].noc);
        pos(37,23);
        printf("Number of Available copies: %d",books[neededcounter].avail);
        pos(37,25);
        printf("Category: %s",books[neededcounter].category);
        pos(37,3);
        printf("Press any key to return to Main Menu...");
        if(getch())
        mainmenu();
    }
    else{
        pos(37,6);
        printf("The Entered ISBN is not Valid,Press any key to Enter The ISBN again");
        if(getch())
        bookmenu();
    }
}
void searchtitle()
{
    system("cls");
    int si=0;
    char searchtarget[50];
    int neededcounter;
    int savecounter=0;
    int titlecounter=NULL;
    char *retaddress=NULL;
    int poscounter=9;
    pos(37,3);
    printf("\t\t\t Search by Book's Title");
    pos(40,5);
    printf("Enter the Book's Title or a part of it: ");
    fflush(stdin);
    gets(searchtarget);
     for(si=0;si<=savei;si++)
    {
        converttolowercase(books[si].title);
        retaddress=strstr(books[si].title,searchtarget);
        if (retaddress != NULL)
        {
            titlecounter++;
        }
        retaddress=NULL;
    }
   if(titlecounter!=NULL)
   {
    book titledata[titlecounter];
     for(si=0;si<=savei;si++)
    {
     retaddress=strstr(books[si].title,searchtarget);
        if (retaddress != NULL)
        {
            strcpy(titledata[savecounter].title,books[si].title);
            strcpy(titledata[savecounter].author,books[si].author);
            strcpy(titledata[savecounter].publisher,books[si].publisher);
            strcpy(titledata[savecounter].ISBN,books[si].ISBN);
            strcpy(titledata[savecounter].compdate,books[si].compdate);
            titledata[savecounter].noc=books[si].noc;
            titledata[savecounter].avail=books[si].avail;
            strcpy(titledata[savecounter].category,books[si].category);
            savecounter++;

        }
        retaddress=NULL;
    }
    pos(37,7);
        printf("\t\t\t The List of books found (%d found)",savecounter);
        pos(37,8);
        printf("\t\t\t ----------------------------------");
        pos(0,poscounter);
        for(si=0;si<savecounter;si++)
        {
            printf("%s, %s, %s, %s, %s, %d, %d, %s\n",titledata[si].title,titledata[si].author,titledata[si].publisher,titledata[si].ISBN,titledata[si].compdate,titledata[si].noc,titledata[si].avail,titledata[si].category);
            poscounter++;
        }
        pos(37,(poscounter+5));
        printf("Enter any key to return to search menu..");
        if(getch())
            searchmenu();

}
else
{
    pos(37,6);
        printf("There is no books that matches that request !! ");
        pos(37,8);
        printf("Enter any key to return to search menu..");
        if(getch())
        searchmenu();
}
}
void addcopy()
{
    system("cls");
    fbooks=fopen("books.txt","r");
    fbooksn=fopen("deletetemp.txt", "a+");
    int si=0;
    int changeline;
    int neededcounter=NULL;
    int linecounter=0;
    char line[500];
    char searchtarget[100];
    int len;
    pos(37,3);
    printf("\t\t\t add copy Menu");
    pos(40,5);
    printf("Please Enter the Book's ISBN: ");
    fflush(stdin);
    scanf("%s",searchtarget);
    for(si=0;si<=savei;si++)
    {
        if (strcmp(books[si].ISBN,searchtarget)==0)
        {
            neededcounter=si;
            break;
        }
    }
    if(neededcounter!=NULL)
    {
    books[neededcounter].noc++;
    books[neededcounter].avail++;
    changeline=neededcounter+1;
    while(!(feof(fbooks)))
    {
        strcpy(line,"\0");
        fflush(stdin);
        fgets(line,500,fbooks);
        len = strlen(line);
    if( line[len-1] == '\n' )
    line[len-1] = 0;
        if(!feof(fbooks))
        {
            linecounter++;
            if(linecounter!=changeline){
            fprintf(fbooksn,"%s",line);
            if(linecounter!=(changeline-1))
                fprintf(fbooksn,"\n");
            }
            else
            {
            fprintf(fbooksn,"%s,%s,%s,%s,%s,%d,%d,%d,%s\n",books[neededcounter].title,books[neededcounter].author,books[neededcounter].publisher,books[neededcounter].ISBN,books[neededcounter].compdate,books[neededcounter].noc,books[neededcounter].avail,books[neededcounter].rank,books[neededcounter].category);
            }
        }
    }
    fclose(fbooks);
    fclose(fbooksn);
    closeallfiles();
    pos(37,29);
    printf("The copy has been added successfully to the system.");
    loadbooksinfo();
    fclose(fbooks);
    fclose(fbooksn);
    closeallfiles();
    pos(37,30);
    printf("To return to main menu press any key ");
    if(getch())
        mainmenu();
    }
    else
    {
        pos(37,6);
        printf("The Entered ISBN is not Valid,Press any key to Enter The ISBN again");
        closeallfiles();
        if(getch())
        addcopy();
    }
}
void popular()
{
    loadbooksinfo();
    fclose(fbooks);
    fclose(fbookstemp);
    system("cls");
    pos(37,3);
    printf("\t\t\tThe Most Popular Books");
    pos(37,4);
    printf("\t\t\t-----------------------");
    pos(0,5);
     int si=0;
     book x[i];
     for(si=0;si<savei;si++)
     {
            strcpy(x[si].title,books[si].title);
            strcpy(x[si].author,books[si].author);
            strcpy(x[si].publisher,books[si].publisher);
            strcpy(x[si].ISBN,books[si].ISBN);
            strcpy(x[si].compdate,books[si].compdate);
            x[si].noc=books[si].noc;
            x[si].avail=books[si].avail;
            strcpy(x[si].category,books[si].category);
            x[si].rank=books[si].rank;
     }


   while(1)
   {
            int swapped=0;
            for (si=0;si<savei-1;si++){
            if (x[si].rank < x[si+1].rank){
            swapstrings(x[si].title,x[si+1].title);
            swapstrings(x[si].author,x[si+1].author);
            swapstrings(x[si].publisher,x[si+1].publisher);
            swapstrings(x[si].ISBN,x[si+1].ISBN);
            swapstrings(x[si].compdate,x[si+1].compdate);
            swapstrings(x[si].category,x[si+1].category);
            swapnumbers(&x[si].rank, &x[si+1].rank);
            swapnumbers(&x[si].noc, &x[si+1].noc);
            swapnumbers(&x[si].avail, &x[si+1].avail);
              swapped=1;
           }
       }
       if (swapped==0)
        break;
}
        pos(0,5);
        printf("Title\t\t\t\tAuthor\t\tPublisher\t\tISBN\t\tDate of publication\tNo. of copies\t\tNo. of available copies\t\tCategory\t\tRank\n");
        if(savei>4)
        {
        pos(0,7);
        for(si=0;si<5;si++)
        {
        printf("\n%s\t\t%s\t%s\t%s\t%s\t\t%d\t\t\t%d\t\t\t\t%s\t\t%d\n",x[si].title,x[si].author,x[si].publisher,x[si].ISBN,x[si].compdate,x[si].noc,x[si].avail,x[si].category,(si+1));
        if(si==5)
            break;
        }
        }
        else if(savei>3)
        {
            pos(0,7);
        for(si=0;si<4;si++)
        {
        printf("\n%s\t\t%s\t%s\t%s\t%s\t\t%d\t\t\t%d\t\t\t\t%s\t\t%d\n",x[si].title,x[si].author,x[si].publisher,x[si].ISBN,x[si].compdate,x[si].noc,x[si].avail,x[si].category,(si+1));
        if(si==4)
            break;
        }
        }
        else if(savei>2)
        {
        pos(0,7);
        for(si=0;si<2;si++)
        {
        printf("\n%s\t\t%s\t%s\t%s\t%s\t\t%d\t\t\t%d\t\t\t\t%s\t\t%d\n",x[si].title,x[si].author,x[si].publisher,x[si].ISBN,x[si].compdate,x[si].noc,x[si].avail,x[si].category,(si+1));
        if(si==2)
            break;
        }
        }
        else if(savei>1)
        {
        pos(0,7);
        for(si=0;si<1;si++)
        {
       if(si==1)
            break;
        printf("\n%s\t\t%s\t%s\t%s\t%s\t\t%d\t\t\t%d\t\t\t\t%s\t\t%d\n",x[si].title,x[si].author,x[si].publisher,x[si].ISBN,x[si].compdate,x[si].noc,x[si].avail,x[si].category,(si+1));
        }
        }
        else
        {
             pos(0,7);
             printf("There are no books in the system!!");
        }
        printf("\nPress any key to return to admin menu...");
        getch();
        adminmenu();

}
void printallbooks()
{
        system("cls");
        int counter=0;
        pos(37,3);
        printf("\t\t\t Books List");
        pos(37,4);
        printf("\t\t\t -----------");
        pos(0,5);
        printf("Title\t\t\t\tAuthor\t\tPublisher\t\tISBN\t\tDate of publication\tNo. of copies\t\tNo. of available copies\t\tCategory\n");
        pos(0,6);
        for(counter=0;counter<=savei;counter++)
        {
        printf("\n%s\t\t%s\t%s\t%s\t%s\t\t%d\t\t\t%d\t\t\t\t%s\t\t\n",books[counter].title,books[counter].author,books[counter].publisher,books[counter].ISBN,books[counter].compdate,books[counter].noc,books[counter].avail,books[counter].category);
        }
}
int checkisbnindex(char *isbn)
{
    int ci;
    int nullcheck=NULL;
    int neededindex;
     for(ci=0;ci<=savei;ci++)
    {
        if(strcasecmp(isbn,books[ci].ISBN) == 0){
            nullcheck++;
            neededindex=ci;
            break;
        }
    }
    if(nullcheck!=NULL)
    {
        return neededindex;
    }
    else
        return 0;
}
void deletebook()
{
    system("cls");
    int si=0;
    int dline;
    int linecounter;
    int nullcounter=NULL;
    int neededcounter;
    char c;
    char searchtarget[50];
    pos(37,3);
    printf("\t\t\t Delete book Menu");
    pos(40,5);
    printf("Please Enter the Book's ISBN: ");
    fflush(stdin);
    scanf("%s",searchtarget);
    for(si=0;si<=(savei);si++)
    {
        if(strcmp(searchtarget,books[si].ISBN) == 0)
        {   nullcounter++;
            neededcounter=si;
            break;
        }
    }
    if(nullcounter!=NULL)
    {
    pos(40,7);
    printf("The book is found");
    pos(40,9);
    printf("The book's Information\n");
    pos(37,11);
    printf("Title: %s",books[neededcounter].title);
    pos(37,13);
    printf("Author: %s",books[neededcounter].author);
    pos(37,15);
    printf("Publisher: %s",books[neededcounter].publisher);
    pos(37,17);
    printf("ISBN: %s",books[neededcounter].ISBN);
    if(books[neededcounter].compdate==NULL){
    pos(37,19);
    printf("Date of Publication: %d/%d/%d",books[neededcounter].published.d,books[neededcounter].published.m,books[neededcounter].published.y);
    }else{
    pos(37,19);
    printf("Date of Publication: %s",books[neededcounter].compdate);
    }
    pos(37,21);
    printf("Number of copies: %d",books[neededcounter].noc);
    pos(37,23);
    printf("Number of Available copies: %d",books[neededcounter].avail);
    pos(37,25);
    printf("Category: %s",books[neededcounter].category);
    pos(37,27);
    printf("PRESS ANY KEY TO CONTINUE DELETING THE FILE");
    getch();
    fbooks=fopen("books.txt","r");
    dline=neededcounter+1;
    linecounter=1;
    fbooksn=fopen("deletetemp.txt","w");
    fseek(fbooks,0,SEEK_SET);
    while(1)
    {
        c=getc(fbooks);
        if(c==EOF)
            break;
        if(c== '\n')
            linecounter++;
        if(linecounter != dline)
            putc(c,fbooksn);
    }
    fclose(fbooksn);
    fclose(fbooks);
    closeallfiles();
    pos(37,29);
    printf("file successfully deleted");
    loadbooksinfo();
    closeallfiles();
    pos(37,30);
    printf("To return to main menu press any key ");
    if(getch())
        mainmenu();
    }
    else
    {
        pos(37,6);
        printf("The Entered ISBN is not Valid,Press any key to Enter The ISBN again");
        closeallfiles();
        if(getch())
        bookmenu();
    }
}
void decreaseavailnoc()
{
    FILE *fbooksn;
    fbooks=fopen("books.txt","r");
    fbooksn=fopen("bookscopy.txt", "w");
    int si=0;
    int changeline;
    int neededcounter=NULL;
    int linecounter=0;
    char line[500];
    char searchtarget[50];
    int len;
    for(si=0;si<=savei;si++)
    {
        if (strcasecmp(books[si].ISBN,decreasethisisbn)==0)
        {
            neededcounter=si;
            break;
        }
    }
    if(neededcounter!=NULL)
    {
    changeline=neededcounter+1;
    while(!(feof(fbooks)))
    {
        strcpy(line,"\0");
        fflush(stdin);
        fgets(line,500,fbooks);
        len = strlen(line);
    if( line[len-1] == '\n' )
    line[len-1] = 0;
        if(!feof(fbooks))
        {
            linecounter++;
            if(linecounter!=changeline){
            fprintf(fbooksn,"%s",line);
            if(linecounter!=(changeline-1))
                fprintf(fbooksn,"\n");
            }
            else
            {
            fprintf(fbooksn,"%s,%s,%s,%s,%s,%d,%d,%d,%s\n",books[neededcounter].title,books[neededcounter].author,books[neededcounter].publisher,books[neededcounter].ISBN,books[neededcounter].compdate,books[neededcounter].noc,books[neededcounter].avail,books[neededcounter].rank,books[neededcounter].category);
            }
        }
    }
    fclose(fbooksn);
    fclose(fbooks);
    closeallfiles();
    remove("books.txt");
    rename("bookscopy.txt","books.txt");
    loadbooksinfo();
    closeallfiles();
}
}
