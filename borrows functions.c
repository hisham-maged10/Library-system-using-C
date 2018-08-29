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
FILE *fborrowsn;
book books[100];
member members[100];
borrow borrows[100];
FILE *fbooks,*fmembers,*fborrows;
FILE *fbookstemp,*fmemberstemp,*fborrowstemp;
int z=0,sbb=0;
int savez=NULL;
char decreasethisisbn[50];

int readborrows()
{
    return fborrows=fopen("borrows.txt","r");
}
int writeborrows()
{
    return fborrows=fopen("borrows.txt","w");
}
void loadborrowsinfo()
{
    borrow x[100];
    fborrows=readborrows();
    fborrowstemp=fopen("borrowstemp.txt","r");
    if(fborrowstemp==NULL)
    {
    if(fborrows==NULL)
    {
        z=0;
        savez=-1;
        fclose(fborrows);
        fclose(fborrowstemp);
        closeallfiles();
        return;
    }
    else{
        fseek(fborrows,0,SEEK_SET);
        while(!(feof(fborrows)))
        {
        if(savez!=NULL)
        {
        z++;
         break;
        }
        fscanf(fborrows,"%[^,],%d,%[^,],%[^,],%[^\n]\n",x[sbb].bisbn,&x[sbb].bid,x[sbb].compdateissue,x[sbb].compdatedue,x[sbb].returndate);
        borrows[z]=x[sbb];
        sbb++;
        z++;
        }
        closeallfiles();
        fclose(fborrows);
        fclose(fborrowstemp);
        z--;
        savez=z;
        savez--;
         }
    }
    else
    {
        fseek(fborrowstemp,0,SEEK_SET);
        while(!(feof(fborrowstemp)))
        {
        fscanf(fborrowstemp,"%[^,],%d,%[^,],%[^,],%[^\n]\n",x[sbb].bisbn,&x[sbb].bid,x[sbb].compdateissue,x[sbb].compdatedue,x[sbb].returndate);
        borrows[z]=x[sbb];
        sbb++;
        z++;
        }
        fclose(fborrows);
        fclose(fborrowstemp);
        z--;
    }
}
void borrowbook()
{
    int increasethisid=NULL;
    time_t currenttime;
    time(&currenttime);
    struct tm *mytime=localtime(&currenttime);
    system("cls");
    fborrows=readborrows();
    printallbooks();
    char isbnborrow[50];
    int borrowid;
    int neededbindex,neededuindex;
    if(fborrows==NULL)
    {
    fborrows=writeborrows();
    if(fborrowstemp==NULL)
    {
    fborrowstemp=fopen("borrowstemp.txt","a+");
    }
    else
    {
    fborrowstemp=fopen("borrowstemp.txt","a");
    }
    fclose(fborrows);
    printf("Enter your user id: ");
    fflush(stdin);
    scanf("%d",&borrowid);
    if(checkidindex(borrowid)==0)
    {
        printf("Incorrect User ID!");
        printf("\nPress any key to to return to main menu...");
        fclose(fborrows);
        fclose(fborrowstemp);
        closeallfiles();
        getch();
        mainmenu();
    }
    else
    {
        increasethisid=borrowid;
        neededuindex=checkidindex(borrowid);
    }
    if(members[neededuindex].borrowcounter < 3)
        {
    printf("Enter The Book's ISBN that you want to borrow: ");
    fflush(stdin);
    gets(isbnborrow);
        if(checkisbnindex(isbnborrow)==0)
    {
        printf("Incorrect Book ISBN!");
        printf("\nPress any key to to return to main menu...");
        fclose(fborrows);
        fclose(fborrowstemp);
        closeallfiles();
        getch();
        mainmenu();
    }
    else
    {
        strcpy(decreasethisisbn,isbnborrow);
        neededbindex=checkisbnindex(isbnborrow);
    }
    printf("\n%s, %s, %s, %s, %s, %d, %d, %s\n",books[neededbindex].title,books[neededbindex].author,books[neededbindex].publisher,books[neededbindex].ISBN,books[neededbindex].compdate,books[neededbindex].noc,books[neededbindex].avail,books[neededbindex].category);
    getch();
    if(books[neededbindex].avail>0)
    {
    z++;
    books[neededbindex].avail--;
    strcpy(borrows[z].bisbn,books[neededbindex].ISBN);
    borrows[z].bid=members[neededuindex].id;
    borrows[z].duedate.m=mytime->tm_mon+1;
    borrows[z].duedate.d=mytime->tm_mday+5;
    borrows[z].duedate.y=mytime->tm_year+1900;
    if(borrows[z].duedate.d>31)
    {
        borrows[z].duedate.d-31;
        borrows[z].duedate.m++;

    }
     if(borrows[z].duedate.m>12)
    {
        borrows[z].duedate.m-12;
        borrows[z].duedate.y++;
    }
    strcpy(borrows[z].returndate,"null");
    fprintf(fborrowstemp,"\n%s,%d,%d/%d/%d,%d/%d/%d,%s",borrows[z].bisbn,borrows[z].bid,mytime->tm_mday,mytime->tm_mon+1,mytime->tm_year+1900,borrows[z].duedate.d,borrows[z].duedate.m,borrows[z].duedate.y,borrows[z].returndate);
    printf("\nBook has been successfully borrowed from the system.");
    fclose(fborrowstemp);
    closeallfiles();
    fclose(fborrowstemp);
    loadborrowsinfo();
    fclose(fborrowstemp);
    books[neededbindex].rank++;
    members[neededuindex].borrowcounter++;
    printf("\nPress any key to return to borrow menu...");
    getch();
    borrowmenu();
        }
    else if(books[neededbindex].avail==0)
        {
    printf("There are no available copies of the required book.");
    printf("\nPress any key to return to main menu...");
    fclose(fborrows);
    fclose(fborrowstemp);
    closeallfiles();
    getch();
    mainmenu();
        }
        closeallfiles();
    }
    else
    {
        printf("You Exceeded your number of borrowed copies you can borrow!!");
        printf("\nPress any key to return to borrow menu...");
        fclose(fborrows);
        fclose(fborrowstemp);
        closeallfiles();
        getch();
        borrowmenu();
    }
    closeallfiles();
    }
    else
    {
    fborrows=fopen("borrows.txt", "a");
    if(fborrowstemp==NULL)
    {
    fborrowstemp=fopen("borrowstemp.txt","a+");
    }
    else
    {
    fborrowstemp=fopen("borrowstemp.txt","a");
    }
    fclose(fborrows);
    printf("Enter your user id: ");
    fflush(stdin);
    scanf("%d",&borrowid);
    if(checkidindex(borrowid)==0)
    {
        printf("Incorrect User ID!");
        printf("\nPress any key to to input user id again...");
        fclose(fborrowstemp);
        closeallfiles();
        getch();
        borrowbook();
    }
    else
    {
        increasethisid=borrowid;
        neededuindex=checkidindex(borrowid);
    }
    if(members[neededuindex].borrowcounter <3)
        {
    printf("Enter The Book's ISBN that you want to borrow: ");
    fflush(stdin);
    gets(isbnborrow);
        if(checkisbnindex(isbnborrow)==0)
    {
        printf("Incorrect Book ISBN!");
        printf("\nPress any key to to input Book ISBN again...");
        fclose(fborrowstemp);
        closeallfiles();
        getch();
        borrowbook();
    }
    else
    {
        strcpy(decreasethisisbn,isbnborrow);
        neededbindex=checkisbnindex(isbnborrow);
    }
    printf("%s, %s, %s, %s, %s, %d, %d, %s\n",books[neededbindex].title,books[neededbindex].author,books[neededbindex].publisher,books[neededbindex].ISBN,books[neededbindex].compdate,books[neededbindex].noc,books[neededbindex].avail,books[neededbindex].category);
    getch();
    if(books[neededbindex].avail>0)
    {
    z++;
    books[neededbindex].avail--;
    strcpy(borrows[z].bisbn,books[neededbindex].ISBN);
    borrows[z].bid=members[neededuindex].id;
    borrows[z].duedate.m=mytime->tm_mon+1;
    borrows[z].duedate.d=mytime->tm_mday+5;
    borrows[z].duedate.y=mytime->tm_year+1900;
    if(borrows[z].duedate.d>31)
    {
        borrows[z].duedate.d-31;
        borrows[z].duedate.m++;

    }
     if(borrows[z].duedate.m>12)
    {
        borrows[z].duedate.m-12;
        borrows[z].duedate.y++;
    }
    strcpy(borrows[z].returndate,"null");
    fprintf(fborrowstemp,"%s,%d,%d/%d/%d,%d/%d/%d,%s\n",borrows[z].bisbn,borrows[z].bid,mytime->tm_mday,mytime->tm_mon+1,mytime->tm_year+1900,borrows[z].duedate.d,borrows[z].duedate.m,borrows[z].duedate.y,borrows[z].returndate);
    fclose(fborrowstemp);
    printf("\nBook has been successfully borrowed from the system.");
    fclose(fborrowstemp);
    closeallfiles();
    fclose(fborrowstemp);
    loadborrowsinfo();
    fclose(fborrowstemp);
    books[neededbindex].rank++;
    members[neededuindex].borrowcounter++;
    printf("\nPress any key to return to borrow menu...");
    getch();
    borrowmenu();
        }
    else if(books[neededbindex].avail==0)
        {
    printf("There are no available copies of the required book.");
    printf("\nPress any key to return to borrow menu...");
    fclose(fborrowstemp);
    closeallfiles();
    getch();
    borrowmenu();
        }
    }
    else
    {
        printf("You Exceeded your number of borrowed copies you can borrow!!");
        printf("\nPress any key to return to borrow menu...");
        fclose(fborrowstemp);
        closeallfiles();
        getch();
        borrowmenu();
    }

    }
    if(getch()){
            closeallfiles();
            fclose(fborrows);
            fclose(fborrowstemp);
    borrowmenu();
    }
}
void returnbook()
{
    system("cls");
    loadborrowsinfo();
    fclose(fborrows);
    fclose(fborrowstemp);
    time_t currenttime;
time(&currenttime);
struct tm *mytime=localtime(&currenttime);
    fborrows=fopen("borrows.txt","r");
    fborrowsn=fopen("borrowscopy.txt", "w");
    int si=0;
    int changeline;
    int neededcounter=NULL;
    int linecounter=0;
    char line[300];
    char searchtarget[50];
    int len;

    pos(37,3);
    printf("\t\t\t Return book Menu");
    pos(40,5);
    printf("Please Enter the Book's ISBN: ");
    fflush(stdin);
    scanf("%s",searchtarget);
    for(si=0;si<=savez;si++)
    {
        if (strcasecmp(borrows[si].bisbn,searchtarget)==0 && (strstr(borrows[si].returndate,"null")!=NULL) )
        {
            neededcounter=si;
            break;
        }
    }
    if(neededcounter!=NULL)
    {
    changeline=neededcounter+1;

    while(!(feof(fborrows)))
    {
        strcpy(line,"\0");
        fflush(stdin);
        fgets(line,300,fborrows);
        len = strlen(line);
        if( line[len-1] == '\n' )
        line[len-1] = 0;
        if(!feof(fborrows))
        {
            linecounter++;
            if(linecounter!=changeline){
            fprintf(fborrowsn,"%s\n",line);
            }
            else
            {
                fprintf(fborrowsn,"%s,%d,%s,%s,%d/%d/%d\n",borrows[neededcounter].bisbn,borrows[neededcounter].bid,borrows[neededcounter].compdateissue,borrows[neededcounter].compdatedue,mytime->tm_mday,mytime->tm_mon+1,mytime->tm_year+1900);
            }
        }
    }
    fclose(fborrows);
    fclose(fborrowsn);
    pos(37,29);
    printf("The book has returned successfully to the system.");
    loadborrowsinfo();
    closeallfiles();
    books[neededcounter].avail++;
    members[neededcounter].borrowcounter--;
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
        returnbook();
    }
}
void overdue()
{
     system("cls");
    time_t currenttime;
    time(&currenttime);
    struct tm *mytime=localtime(&currenttime);
    int nullcounter=NULL;
    int si=0;
    char *retaddress=NULL;
    int savecounter=0;
    int poscounter=9;
    char currentdate[25];
    int d,m,y;
    char day[5];
    char mon[5];
    char year[5];
    int r;
    d=mytime->tm_mday;
    m=mytime->tm_mon+1;
    y=mytime->tm_year+1900;
    itoa(d,day,10);
    itoa(m,mon,10);
    itoa(y,year,10);
    strcpy(currentdate,day);
    strcat(currentdate,"/");
    strcat(currentdate,mon);
    strcat(currentdate,"/");
    strcat(currentdate,year);

    for(si=0;si<=savez;si++)
    {
        retaddress=strstr(borrows[si].returndate,"null");
        if (retaddress != NULL)
        {
            nullcounter++;
        }
        retaddress=NULL;
    }
    if(nullcounter!=NULL)
   {
    borrow borrowswithnull[nullcounter];
    for(si=0;si<=savez;si++)
    {
     retaddress=strstr(borrows[si].returndate,"null");
        if (retaddress != NULL)
        {
            strcpy(borrowswithnull[savecounter].bisbn,borrows[si].bisbn);
            borrowswithnull[savecounter].bid=borrows[si].bid;
            strcpy(borrowswithnull[savecounter].compdateissue,borrows[si].compdateissue);
            strcpy(borrowswithnull[savecounter].compdatedue,borrows[si].compdatedue);
            savecounter++;
        }
        retaddress=NULL;
}
 pos(37,7);
        printf("\t\t\t The List of Overdue Borrows (%d found)",savecounter);
        pos(37,8);
        printf("\t\t\t ----------------------------------");
        pos(0,poscounter);
        printf("Book's ISBN\t\tUser's ID\tDate Issued\tDue Date");
        pos(0,(poscounter+1));
        for(si=0;si<savecounter;si++)
        {
            r=strcasecmp(currentdate,borrowswithnull[si].compdatedue);
               if(r>0)
               {
            printf("%s\t  \t%d\t\t%s\t%s\n",borrowswithnull[si].bisbn,borrowswithnull[si].bid,borrowswithnull[si].compdateissue,borrowswithnull[si].compdatedue);
            poscounter++;
               }
        }
        pos(37,(poscounter+5));
        printf("Enter any key to return to Admin Menu");
        if(getch())
            adminmenu();

   }
   else
{
    pos(37,6);
        printf("There are no overdue books at the moment! ");
        pos(37,8);
        printf("Enter any key to return to Main Menu...");
        if(getch())
        mainmenu();
}
}
void printallborrows()
{
        system("cls");
        int counter=0;
        pos(37,3);
        printf("\t\t\t Borrows List");
        pos(37,4);
        printf("\t\t\t -----------");
        pos(0,5);
        printf("Book's ISBN\tUser's ID\tDate Issued\t\tDue Date\t\tReturn Date");
        pos(0,6);
        for(counter=0;counter<=savez;counter++)
        {
       printf("%s\t\t%d\t\t%s\t\t%s\t\t%s\n",borrows[counter].bisbn,borrows[counter].bid,borrows[counter].compdateissue,borrows[counter].compdatedue,borrows[counter].returndate);
        }
        printf("\nPress any key to return to main menu...");
        getch();
        mainmenu();
}
