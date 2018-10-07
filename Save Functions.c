/**
 * @author ${hisham_maged10}
 *https://github.com/hisham-maged10
 * ${DesktopApps}
 */
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
FILE *fbooksn;
book books[100];
member members[100];
borrow borrows[100];
FILE *fborrowsn;
FILE *fmembersn;
FILE *fbooks,*fmembers,*fborrows;
FILE *fbookstemp,*fmemberstemp,*fborrowstemp;
char decreasethisisbn[50];
void savebooks()
{
      FILE *ftemp;
   char line[300];
    int len;
    if(fbooksn!=NULL)
    {
    remove("books.txt");
    rename("deletetemp.txt","books.txt");
    }
    fbooks=fopen("books.txt","r");
    fbookstemp=fopen("bookstemp.txt","a+");
    ftemp = fopen("bookstempfinal.txt", "a+");
    fseek(fbooks,0,SEEK_SET);
    fseek(fbookstemp,0,SEEK_SET);
    while (!feof(fbooks))
        {
        strcpy(line,"\0");
        fgets(line,300,fbooks);
        len = strlen(line);
        if( line[len-1] == '\n' )
        line[len-1] = 0;
        fprintf(ftemp,"%s\n",line);
        }
        fclose(fbooks);
    while (!feof(fbookstemp))
        {
            strcpy(line,"\0");
       fgets(line,300,fbookstemp);
       if(strcmp(line,"\n")==0)
        continue;
        len = strlen(line);
        if( line[len-1] == '\n' )
        line[len-1] = 0;
        fprintf(ftemp,"%s\n",line);
        }
        fclose(fbookstemp);
        fclose(ftemp);
    remove("books.txt");
    remove("bookstemp.txt");
    rename("bookstempfinal.txt","books.txt");
    removeemptylinesbooks();
    remove("bookscopy.txt");
    remove("deletetemp.txt");
}
void savemembers()
{
           FILE *ftemp;
   char line[300];
       int len;
       int linecounter=0;
       int lastline=0;
       if(fmembersn!=NULL)
       {
       remove("members.txt");
    rename("memberscopy.txt","members.txt");
       }
       fclose(fmembersn);
    fmembers=fopen("members.txt","r");
    fmemberstemp=fopen("memberstemp.txt","a+");
    ftemp = fopen("memberstempfinal.txt", "a+");
    while (!feof(fmembers))
        {
        strcpy(line,"\0");
        fgets(line,300,fmembers);
        len = strlen(line);
        if( line[len-1] == '\n' )
        line[len-1] = 0;
        linecounter++;
        fprintf(ftemp,"%s\n",line);
        }
        fclose(fmembers);
    while (!feof(fmemberstemp))
        {
        strcpy(line,"\0");
       fgets(line,300,fmemberstemp);
       if(strcmp(line,"\n")==0)
        continue;
        len = strlen(line);
        if( line[len-1] == '\n' )
        line[len-1] = 0;
        fprintf(ftemp,"%s\n",line);
        }
    fclose(fmemberstemp);
    fclose(ftemp);
    closeallfiles();
    remove("members.txt");
    remove("memberstemp.txt");
    rename("memberstempfinal.txt","members.txt");
    removeemptylinesmembers();
    remove("memberscopy.txt");

}
void saveborrows()
{
         FILE *ftemp;
   char line[300];
       int len;
       int linecounter=0;
       int lastline=0;
       if(fborrowsn!=NULL)
       {
        remove("borrows.txt");
        rename("borrowscopy.txt","borrows.txt");
       }
    fborrows=fopen("borrows.txt","r");
    fborrowstemp=fopen("borrowstemp.txt","a+");
    ftemp = fopen("borrowstempfinal.txt", "a+");
    while (!feof(fborrows))
        {
        strcpy(line,"\0");
        fgets(line,300,fborrows);
        len = strlen(line);
        if( line[len-1] == '\n' )
        line[len-1] = 0;
        linecounter++;
        fprintf(ftemp,"%s\n",line);
        }
        fclose(fborrows);
    while (!feof(fborrowstemp))
        {
        strcpy(line,"\0");
       fgets(line,300,fborrowstemp);
       if(strcmp(line,"\n")==0)
        continue;
        len = strlen(line);
        if( line[len-1] == '\n' )
        line[len-1] = 0;
        fprintf(ftemp,"%s\n",line);
        }
        fclose(fborrowstemp);
    fclose(ftemp);
    closeallfiles();
    remove("borrows.txt");
    remove("borrowstemp.txt");
    rename("borrowstempfinal.txt","borrows.txt");
    decreaseavailnoc();
    increaseborrowcounter();
    removeemptylinesborrows();
    remove("borrowscopy.txt");
}
void saveall()
{
      fbooks=fopen("books.txt","r");
        fbookstemp=fopen("bookstemp.txt","r");
        fmembers=fopen("members.txt","r");
        fmemberstemp=fopen("memberstemp.txt","r");
        fborrows=fopen("borrows.txt","r");
        fborrowstemp=fopen("borrowstemp.txt","r");
        fbooksn=fopen("deletetemp.txt","r");
        fmembersn=fopen("memberscopy.txt","r");
        fborrowsn=fopen("borrowscopy.txt","r");
     if (fbooks != NULL && ( fbookstemp != NULL || fbooksn!=NULL) && fmembers != NULL && (fmemberstemp != NULL || fmembersn!=NULL) && fborrows != NULL && (fborrowstemp != NULL || fborrowsn!=NULL))
     {
        fclose(fbooks);
        fclose(fbookstemp);
        fclose(fmembers);
        fclose(fmemberstemp);
        fclose(fborrows);
        fclose(fborrowstemp);
        fclose(fbooksn);
        fclose(fmembersn);
        fclose(fborrowsn);
        pos(40,16);
        printf("Books,Members,Borrows have been successfully saved.");
     }

     else if (fbooks != NULL && ( fbookstemp != NULL || fbooksn!=NULL) && fmembers != NULL && (fmemberstemp != NULL || fmembersn!=NULL) )
     {
         fclose(fbooks);
        fclose(fbookstemp);
        fclose(fmembers);
        fclose(fmemberstemp);
        fclose(fborrows);
        fclose(fborrowstemp);
        fclose(fbooksn);
        fclose(fmembersn);
        fclose(fborrowsn);
        pos(40,16);
        printf("Books,Members have been successfully saved, but there is nothing to be saved in Borrows");
     }
     else if (fmembers != NULL && (fmemberstemp != NULL || fmembersn!=NULL) && fborrows != NULL && (fborrowstemp != NULL || fborrowsn!=NULL) )
     {
         fclose(fbooks);
        fclose(fbookstemp);
        fclose(fmembers);
        fclose(fmemberstemp);
        fclose(fborrows);
        fclose(fborrowstemp);
        fclose(fbooksn);
        fclose(fmembersn);
        fclose(fborrowsn);
        pos(40,16);
        printf("Members,Borrows have been successfully saved, but there is nothing to be saved in Books");
     }
     else if (fbooks != NULL && ( fbookstemp != NULL || fbooksn!=NULL) && fborrows != NULL && (fborrowstemp != NULL || fborrowsn!=NULL) )
     {
         fclose(fbooks);
        fclose(fbookstemp);
        fclose(fmembers);
        fclose(fmemberstemp);
        fclose(fborrows);
        fclose(fborrowstemp);
        fclose(fbooksn);
        fclose(fmembersn);
        fclose(fborrowsn);
        pos(40,16);
        printf("Books,Borrows have been successfully saved, but there is nothing to be saved in Members");
     }
     else if (fbooks != NULL && ( fbookstemp != NULL || fbooksn!=NULL) )
     {
         fclose(fbooks);
        fclose(fbookstemp);
        fclose(fmembers);
        fclose(fmemberstemp);
        fclose(fborrows);
        fclose(fborrowstemp);
        fclose(fbooksn);
        fclose(fmembersn);
        fclose(fborrowsn);
        pos(40,16);
        printf("Books have been successfully saved, but there is nothing to be saved in Members,Borrows.");
     }
     else if (fmembers != NULL && (fmemberstemp != NULL || fmembersn!=NULL) )
     {
         fclose(fbooks);
        fclose(fbookstemp);
        fclose(fmembers);
        fclose(fmemberstemp);
        fclose(fborrows);
        fclose(fborrowstemp);
        fclose(fbooksn);
        fclose(fmembersn);
        fclose(fborrowsn);
        pos(40,16);
       printf("Members have been successfully saved, but there is nothing to be saved in Books,Borrows.");
     }
     else if (fborrows != NULL && (fborrowstemp != NULL || fborrowsn!=NULL) )
     {
         fclose(fbooks);
        fclose(fbookstemp);
        fclose(fmembers);
        fclose(fmemberstemp);
        fclose(fborrows);
        fclose(fborrowstemp);
        fclose(fbooksn);
        fclose(fmembersn);
        fclose(fborrowsn);
        pos(40,16);
        printf("Borrows have been successfully saved, but there is nothing to be saved in Books,Members.");
     }
     else if ( fbookstemp == NULL && fbooksn == NULL  && fmemberstemp == NULL && fmembersn == NULL  && fborrowstemp == NULL && fborrowsn == NULL )
     {
         fclose(fbooks);
        fclose(fbookstemp);
        fclose(fmembers);
        fclose(fmemberstemp);
        fclose(fborrows);
        fclose(fborrowstemp);
        fclose(fbooksn);
        fclose(fmembersn);
        fclose(fborrowsn);
        pos(40,16);
        printf("Error: There is nothing to be saved!!");
     }
        if (fbooks != NULL && ( fbookstemp != NULL || fbooksn!=NULL))
    {
        fclose(fbooks);
        fclose(fbookstemp);
        fclose(fmembers);
        fclose(fmemberstemp);
        fclose(fborrows);
        fclose(fborrowstemp);
        fclose(fbooksn);
        fclose(fmembersn);
        fclose(fborrowsn);
        savebooks();
    }
            fclose(fbooks);
        fclose(fbookstemp);
        fclose(fmembers);
        fclose(fmemberstemp);
        fclose(fborrows);
        fclose(fborrowstemp);
        fclose(fbooksn);
        fclose(fmembersn);
        fclose(fborrowsn);

        fmembers=fopen("members.txt","r");
        fmemberstemp=fopen("memberstemp.txt","r");
        if (fmembers != NULL && (fmemberstemp != NULL || fmembersn!=NULL))
    {
          fclose(fbooks);
        fclose(fbookstemp);
        fclose(fmembers);
        fclose(fmemberstemp);
        fclose(fborrows);
        fclose(fborrowstemp);
        fclose(fbooksn);
        fclose(fmembersn);
        fclose(fborrowsn);
        savemembers();

    }    fclose(fbooks);
        fclose(fbookstemp);
        fclose(fmembers);
        fclose(fmemberstemp);
        fclose(fborrows);
        fclose(fborrowstemp);
        fclose(fbooksn);
        fclose(fmembersn);
        fclose(fborrowsn);

        fborrows=fopen("borrows.txt","r");
        fborrowstemp=fopen("borrowstemp.txt","r");
        if (fborrows != NULL && (fborrowstemp != NULL || fborrowsn!=NULL))
    {
            fclose(fbooks);
        fclose(fbookstemp);
        fclose(fmembers);
        fclose(fmemberstemp);
        fclose(fborrows);
        fclose(fborrowstemp);
        fclose(fbooksn);
        fclose(fmembersn);
        fclose(fborrowsn);
        saveborrows();
    }
            fclose(fbooks);
        fclose(fbookstemp);
        fclose(fmembers);
        fclose(fmemberstemp);
        fclose(fborrows);
        fclose(fborrowstemp);
        fclose(fbooksn);
        fclose(fmembersn);
        fclose(fborrowsn);

    remove("bookscopy.txt");
    remove("memberscopy.txt");
    remove("borrowscopy.txt");
    remove("deletetemp.txt");

}
void removetempandexit()
{
    closeallfiles();
    exit(1);
}
void removeemptylinesbooks()
{
    FILE *fp2;
        char line[300];
        char x[]="blank.txt";
        fbooks=readbooks();
        fp2=fopen(x,"w");
        while (!feof(fbooks)) {
                fflush(stdin);
                fgets(line, 300, fbooks);
                if (strcmp(line, "\n") == 0) {
                        continue;
                }
                fputs(line, fp2);
                strcpy(line, "\0");
        }
        fclose(fbooks);
        closeallfiles();
        fclose(fp2);
        remove("books.txt");
        rename(x,"books.txt");
}
void removeemptylinesmembers()
{
    FILE *fp2;
        char line[300];
        char x[]="blank.txt";
        fmembers=readmembers();
        fp2=fopen(x,"w");
        while (!feof(fmembers)) {
                fflush(stdin);
                fgets(line, 300, fmembers);
                if (strcmp(line, "\n") == 0) {
                        continue;
                }
                fputs(line, fp2);
                strcpy(line, "\0");
        }
        fclose(fmembers);
        closeallfiles();
        fclose(fp2);
        remove("members.txt");
        rename(x,"members.txt");
}
void removeemptylinesborrows()
{
    FILE *fp2;
        char line[300];
        char x[]="blank.txt";
        fborrows=readborrows();
        fp2=fopen(x,"w");
        while (!feof(fborrows)) {
                fflush(stdin);
                fgets(line, 300, fborrows);
                if (strcmp(line, "\n") == 0) {
                        continue;
                }
                fputs(line, fp2);
                strcpy(line, "\0");
        }
        fclose(fborrows);
        closeallfiles();
        fclose(fp2);
        remove("borrows.txt");
        rename(x,"borrows.txt");
}
void closeallfiles()
{
    fclose(fbooks);
    fclose(fbookstemp);
    fclose(fmembers);
    fclose(fmemberstemp);
    fclose(fborrows);
    fclose(fborrowstemp);
}
void exitwithoutsaving()
{
    int b,m,bb;
    b=checkbooktemp();
    m=checkmembertemp();
    bb=checkborrowtemp();
    if(b==1 && m==1 && bb==1)
    {
        pos(40,11);
        printf("You made changes in Books,Members,Borrows!!");
        pos(40,13);
        printf("Are you sure you want to exit without saving? (y/n)");
        switch(getch())
        {
        case 'y':removetempandexit();
        break;
        case 'Y':removetempandexit();
        break;
        case 'n':savemenu();
        break;
        case 'N':
        savemenu();
        break;
        default:
            {
        pos(40,14);
        printf("Error!!");
        pos(40,15);
        printf("Wrong input please press Y or N");
        pos(40,16);
        printf("Press any key to continue...");
        if(getch()){
        exitwithoutsaving();
        }
        }
        }
    }
    else if(b==1 && m==1)
    {
        pos(40,11);
        printf("You made changes in Books,Members!!");
        pos(40,13);
        printf("Are you sure you want to exit without saving? (y/n)");
        switch(getch())
        {
        case 'y':removetempandexit();
        break;
        case 'Y':removetempandexit();
        break;
        case 'n':savemenu();
        break;
        case 'N':
        savemenu();
        break;
        default:
            {
        pos(40,14);
        printf("Error!!");
        pos(40,15);
        printf("Wrong input please press Y or N");
        pos(40,16);
        printf("Press any key to continue...");
        if(getch()){
        exitwithoutsaving();
        }
        }
        }
    }
    else if(m==1 && bb==1)
    {
        pos(40,11);
        printf("You made changes in Members,Borrows!!");
        pos(40,13);
        printf("Are you sure you want to exit without saving? (y/n)");
        switch(getch())
        {
        case 'y':removetempandexit();
        break;
        case 'Y':removetempandexit();
        break;
        case 'n':savemenu();
        break;
        case 'N':
        savemenu();
        break;
        default:
            {
        pos(40,14);
        printf("Error!!");
        pos(40,15);
        printf("Wrong input please press Y or N");
        pos(40,16);
        printf("Press any key to continue...");
        if(getch()){
        exitwithoutsaving();
        }
        }
        }
    }
   else if(b==1 && bb==1)
    {
        pos(40,11);
        printf("You made changes in Books,Borrows!!");
        pos(40,13);
        printf("Are you sure you want to exit without saving? (y/n)");
        switch(getch())
        {
        case 'y':removetempandexit();
        break;
        case 'Y':removetempandexit();
        break;
        case 'n':savemenu();
        break;
        case 'N':
        savemenu();
        break;
        default:
            {
        pos(40,14);
        printf("Error!!");
        pos(40,15);
        printf("Wrong input please press Y or N");
        pos(40,16);
        printf("Press any key to continue...");
        if(getch()){
        exitwithoutsaving();
        }
        }
        }
    }
    else if(b==1)
    {
        pos(40,11);
        printf("You made changes in Books!!");
        pos(40,13);
        printf("Are you sure you want to exit without saving? (y/n)");
        switch(getch())
        {
        case 'y':removetempandexit();
        break;
        case 'Y':removetempandexit();
        break;
        case 'n':savemenu();
        break;
        case 'N':
        savemenu();
        break;
        default:
            {
        pos(40,14);
        printf("Error!!");
        pos(40,15);
        printf("Wrong input please press Y or N");
        pos(40,16);
        printf("Press any key to continue...");
        if(getch()){
        exitwithoutsaving();
        }
        }
        }
    }
   else if(m==1)
    {
        pos(40,11);
        printf("You made changes in Members!!");
        pos(40,13);
        printf("Are you sure you want to exit without saving? (y/n)");
        switch(getch())
        {
        case 'y':removetempandexit();
        break;
        case 'Y':removetempandexit();
        break;
        case 'n':savemenu();
        break;
        case 'N':
        savemenu();
        break;
        default:
            {
        pos(40,14);
        printf("Error!!");
        pos(40,15);
        printf("Wrong input please press Y or N");
        pos(40,16);
        printf("Press any key to continue...");
        if(getch()){
        exitwithoutsaving();
        }
        }
        }
    }
   else if(bb==1)
    {
        pos(40,11);
        printf("You made changes in Borrows!!");
        pos(40,13);
        printf("Are you sure you want to exit without saving? (y/n)");
        switch(getch())
        {
        case 'y':removetempandexit();
        break;
        case 'Y':removetempandexit();
        break;
        case 'n':savemenu();
        break;
        case 'N':
        savemenu();
        break;
        default:
            {
        pos(40,14);
        printf("Error!!");
        pos(40,15);
        printf("Wrong input please press Y or N");
        pos(40,16);
        printf("Press any key to continue...");
        if(getch()){
        exitwithoutsaving();
        }
        }
        }
    }
    else if(b==0 && m==0 && bb==0)
    {
       removetempandexit();

    }


}
int checkbooktemp()
{
    fbookstemp=fopen("bookstemp.txt","r");
    fbooksn=fopen("bookscopy.txt","r");
    if(fbookstemp!=NULL || fbooksn!=NULL ){
        fclose(fbookstemp);
        fclose(fbooksn);
        return 1;
    }
    else{
        fclose(fbookstemp);
        fclose(fbooksn);
        return 0;
}
}
int checkmembertemp()
{
      fmemberstemp=fopen("memberstemp.txt","r");
      fmembersn=fopen("memberscopy.txt","r");
    if(fmemberstemp!=NULL || fmembersn!=NULL ){
        fclose(fmemberstemp);
        fclose(fmembersn);
        return 1;
    }
    else{
        fclose(fmemberstemp);
        fclose(fmembersn);
        return 0;
}
}
int checkborrowtemp()
{
      fborrowstemp=fopen("borrowstemp.txt","r");
      fborrowsn=fopen("borrowscopy.txt","r");
    if(fborrowstemp!=NULL || fborrowsn!=NULL ){
        fclose(fborrowstemp);
        fclose(fborrowsn);
        return 1;
    }
    else{
        fclose(fborrowstemp);
        fclose(fborrowsn);
        return 0;
}
}
void checksaveatstart()
{
    system("color 74");
    system("cls");
     int b,m,bb;
    b=checkbooktemp();
    m=checkmembertemp();
    bb=checkborrowtemp();
    fclose(fbookstemp);
    fclose(fmemberstemp);
    fclose(fborrowstemp);
    if(b==1 && m==1 && bb==1)
    {
        pos(30,6);
        printf("You made changes in Books,Members,Borrows that you didn't save!!");
        pos(30,8);
        printf("Are you sure you want to continue without saving? (y/n)");
        pos(30,10);
        printf("Note:you can Choose which of them to save or save them all");
        pos(30,12);
        printf("Note:if you don't save, The information can't be restored again");
        pos(30,13);
        printf("Please Choose Y or N:");
        switch(getch())
        {
        case 'y':removetempatstart();
        break;
        case 'Y':removetempatstart();
        break;
        case 'n':savemenu();
        break;
        case 'N':
        savemenu();
        break;
        default:
            {
        pos(40,14);
        printf("Error!!");
        pos(40,15);
        printf("Wrong input please press Y or N");
        pos(40,16);
        printf("Press any key to continue...");
        if(getch()){
        checksaveatstart();
        }
        }
        }
    }
    else if(b==1 && m==1)
    {
        pos(30,6);
        printf("You made changes in Books,Members!!");
        pos(30,8);
        printf("Are you sure you want to exit without saving? (y/n)");
        pos(30,10);
        printf("Note:you can Choose which of them to save or save them all");
        pos(30,12);
        printf("Note:if you don't save, The information can't be restored again");
        pos(30,13);
        printf("Please Choose Y or N:");
        switch(getch())
        {
        case 'y':removetempatstart();
        break;
        case 'Y':removetempatstart();
        break;
        case 'n':savemenu();
        break;
        case 'N':
        savemenu();
        break;
        default:
            {
        pos(40,14);
        printf("Error!!");
        pos(40,15);
        printf("Wrong input please press Y or N");
        pos(40,16);
        printf("Press any key to continue...");
        if(getch()){
        checksaveatstart();
        }
        }
        }
    }
    else if(m==1 && bb==1)
    {
        pos(30,6);
        printf("You made changes in Members,Borrows!!");
        pos(30,8);
        printf("Are you sure you want to exit without saving? (y/n)");
        pos(30,10);
        printf("Note:you can Choose which of them to save or save them all");
        pos(30,12);
        printf("Note:if you don't save, The information can't be restored again");
        pos(30,13);
        printf("Please Choose Y or N:");
        switch(getch())
        {
        case 'y':removetempatstart();
        break;
        case 'Y':removetempatstart();
        break;
        case 'n':savemenu();
        break;
        case 'N':
        savemenu();
        break;
        default:
            {
        pos(40,14);
        printf("Error!!");
        pos(40,15);
        printf("Wrong input please press Y or N");
        pos(40,16);
        printf("Press any key to continue...");
        if(getch()){
        checksaveatstart();
        }
        }
        }
    }
   else if(b==1 && bb==1)
    {
        pos(30,6);
        printf("You made changes in Books,Borrows!!");
        pos(30,8);
        printf("Are you sure you want to exit without saving? (y/n)");
        pos(30,10);
        printf("Note:you can Choose which of them to save or save them all");
        pos(30,12);
        printf("Note:if you don't save, The information can't be restored again");
        pos(30,13);
        printf("Please Choose Y or N:");
        switch(getch())
        {
        case 'y':removetempatstart();
        break;
        case 'Y':removetempatstart();
        break;
        case 'n':savemenu();
        break;
        case 'N':
        savemenu();
        break;
        default:
            {
        pos(40,14);
        printf("Error!!");
        pos(40,15);
        printf("Wrong input please press Y or N");
        pos(40,16);
        printf("Press any key to continue...");
        if(getch()){
        checksaveatstart();
        }
        }
        }
    }
    else if(b==1)
    {
        pos(30,6);
        printf("You made changes in Books!!");
        pos(30,8);
        printf("Are you sure you want to exit without saving? (y/n)");
        pos(30,10);
        printf("Note:you can Choose which of them to save or save them all");
        pos(30,12);
        printf("Note:if you don't save, The information can't be restored again");
        pos(30,13);
        printf("Please Choose Y or N:");
        switch(getch())
        {
        case 'y':removetempatstart();
        break;
        case 'Y':removetempatstart();
        break;
        case 'n':savemenu();
        break;
        case 'N':
        savemenu();
        break;
        default:
            {
        pos(40,14);
        printf("Error!!");
        pos(40,15);
        printf("Wrong input please press Y or N");
        pos(40,16);
        printf("Press any key to continue...");
        if(getch()){
        checksaveatstart();
        }
        }
        }
    }
   else if(m==1)
    {
        pos(30,6);
        printf("You made changes in Members!!");
        pos(30,8);
        printf("Are you sure you want to exit without saving? (y/n)");
        pos(30,10);
        printf("Note:you can Choose which of them to save or save them all");
        pos(30,12);
        printf("Note:if you don't save, The information can't be restored again");
        pos(30,13);
        printf("Please Choose Y or N:");
        switch(getch())
        {
        case 'y':removetempatstart();
        break;
        case 'Y':removetempatstart();
        break;
        case 'n':savemenu();
        break;
        case 'N':
        savemenu();
        break;
        default:
            {
        pos(40,14);
        printf("Error!!");
        pos(40,15);
        printf("Wrong input please press Y or N");
        pos(40,16);
        printf("Press any key to continue...");
        if(getch()){
        checksaveatstart();
        }
        }
        }
    }
   else if(bb==1)
    {
        pos(30,6);
        printf("You made changes in Borrows!!");
        pos(30,8);
        printf("Are you sure you want to exit without saving? (y/n)");
        pos(30,10);
        printf("Note:you can Choose which of them to save or save them all");
        pos(30,12);
        printf("Note:if you don't save, The information can't be restored again");
        pos(30,13);
        printf("Please Choose Y or N:");
        switch(getch())
        {
        case 'y':removetempatstart();
        break;
        case 'Y':removetempatstart();
        break;
        case 'n':savemenu();
        break;
        case 'N':
        savemenu();
        break;
        default:
            {
        pos(40,14);
        printf("Error!!");
        pos(40,15);
        printf("Wrong input please press Y or N");
        pos(40,16);
        printf("Press any key to continue...");
        if(getch()){
        checksaveatstart();
        }
        }
        }
    }
    else if(b==0 && m==0 && bb==0)
    {
       mainmenu();

    }


}
void removetempatstart()
{
    fclose(fbookstemp);
    fclose(fmemberstemp);
    fclose(fborrowstemp);
    remove("bookstemp.txt");
    remove("borrowstemp.txt");
    remove("memberstemp.txt");
    remove("bookscopy.txt");
    remove("memberscopy.txt");
    remove("borrowscopy.txt");
    remove("deletetemp.txt");
    mainmenu();
}





