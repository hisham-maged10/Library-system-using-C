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
FILE *fmembersn;
FILE *fmembers;
FILE *fmemberstemp;
int j=0,sm=0;
int savej=NULL;
member members[100];
int increasethisid=NULL;
int readmembers()
{
    return fopen("members.txt","r");
}
int writemembers()
{
    return fopen("members.txt","w");
}
void loadmembersinfo()
{
    member x[100];
    fmembers=readmembers();
    fmemberstemp=fopen("memberstemp.txt","r");
    if(fmemberstemp==NULL)
    {
    if(fmembers==NULL)
    {
        j=0;
        savej=-1;
        fclose(fmembers);
        fclose(fmemberstemp);
        closeallfiles();
        return;
    }
    else{
        fseek(fmembers,0,SEEK_SET);
        while(!(feof(fmembers)))
        {
        if(savej!=NULL)
        {
        j++;
         break;
        }
        fscanf(fmembers,"%[^,],%[^,],%d,%[^,],%d,%d,%d,%[^\n]",x[sm].lastname,x[sm].firstname,&x[sm].id,x[sm].address,&x[sm].number,&x[sm].age,&x[sm].borrowcounter,x[sm].email);
        members[j]=x[sm];
        sm++;
        j++;
        }
        fclose(fmembers);
        fclose(fmemberstemp);
        closeallfiles();
        j--;
        savej=j;
        savej--;
         }
    }
    else
    {
        fseek(fmemberstemp,0,SEEK_SET);
        while(!(feof(fmemberstemp)))
        {
        fscanf(fmemberstemp,"%[^,],%[^,],%d,%[^,],%d,%d,%d,%[^\n]",x[sm].lastname,x[sm].firstname,&x[sm].id,x[sm].address,&x[sm].number,&x[sm].age,&x[sm].borrowcounter,x[sm].email);
        members[j]=x[sm];
        sm++;
        j++;
        }
        fclose(fmemberstemp);
        fclose(fmembers);
        j--;
    }
}
void reg()
{
    system("cls");
    member b;
    int check;
    char checkenter;
    fmembers=fopen("members.txt","r");
    pos(37,3);
    printf("\t\t\t Add Member Menu%d");
    if(fmembers==NULL)
    {
    fmembers=writemembers();
    if(fmemberstemp==NULL)
    {
    fmemberstemp=fopen("memberstemp.txt","a+");
    }
    else
    {
    fmemberstemp=fopen("memberstemp.txt","a");
    }
    fclose(fmembers);
    pos(40,5);
    printf("Enter The First Name Of The User: ");
    fflush(stdin);
    gets(b.firstname);
     check=validatestringallchar(b.firstname);
     if(check==1)
     {  do{
        printf("Wrong input, Enter again: ");
        fflush(stdin);
        gets(b.firstname);
        check=validatestringallchar(b.firstname);
         }while(check==1);
     }
    pos(40,7);
    printf("Enter the Last Name Of The User: ");
    fflush(stdin);
    gets(b.lastname);
     check=validatestringallchar(b.lastname);
     if(check==1)
     {  do{
        printf("Wrong input, Enter again: ");
        fflush(stdin);
        gets(b.firstname);
        check=validatestringallchar(b.lastname);
         }while(check==1);
     }
    pos(40,9);
    printf("Enter The User's ID: ");
    fflush(stdin);
    scanf("%d",&b.id);
    if(checkidindex(b.id)==0)
    {
    pos(40,11);
    printf("Enter The User's Address:- ");
    pos(40,12);
    printf("Enter The Street Number: ");
    fflush(stdin);
    scanf("%d",&b.separateaddress.streetno);
    pos(40,13);
    printf("Enter The Street Name: ");
    fflush(stdin);
    gets(b.separateaddress.streetname);
    check=validatestringallchar(b.separateaddress.streetname);
     if(check==1)
     {  do{
        printf("Wrong input, Enter again: ");
        fflush(stdin);
        gets(b.separateaddress.streetname);
        check=validatestringallchar(b.separateaddress.streetname);
         }while(check==1);
     }
    pos(40,14);
    printf("Enter The City Name: ");
    fflush(stdin);
    gets(b.separateaddress.city);
    check=validatestringallchar(b.separateaddress.city);
     if(check==1)
     {  do{
        printf("Wrong input, Enter again: ");
        fflush(stdin);
        gets(b.separateaddress.city);
        check=validatestringallchar(b.separateaddress.city);
         }while(check==1);
     }
    pos(40,16);
    printf("Enter the User's Mobile Number: ");
    fflush(stdin);
    scanf("%d",&b.number);
    check=checkphonenumber(b.number);
    if(check==0)
        do
    {
        printf("Wrong Entry!!\n");
        printf("Enter a Valid Mobile Number: ");
        scanf("%d",&b.number);
        check=checkphonenumber(b.number);

    }while(check==0);
    pos(40,18);
    printf("Enter the User's Age: ");
    fflush(stdin);
    scanf("%d",&b.age);
    check=checkage(b.age);
     if(check==0)
        do
    {
        printf("Wrong Entry!!\n");
        printf("Enter a Valid Age: ");
        scanf("%d",&b.age);
        check=checkage(b.age);

    }while(check==0);
    pos(40,20);
    printf("Enter The User's Email: ");
    fflush(stdin);
    gets(b.email);
    check=validatemail(b.email);
     if(check==0)
     {  do{
        printf("Wrong input, Enter again: ");
        fflush(stdin);
        gets(b.email);
        check=validatemail(b.email);
         }while(check==0);
     }
    b.borrowcounter=0;
    fprintf(fmemberstemp,"%s,%s,%d,%d.%s.%s,0%d,%d,%d,%s\n",b.lastname,b.firstname,b.id,b.separateaddress.streetno,b.separateaddress.streetname,b.separateaddress.city,b.number,b.age,b.borrowcounter,b.email);
    fclose(fmemberstemp);
    members[j]=b;
    fclose(fmemberstemp);
    loadmembersinfo();
    fclose(fmemberstemp);
    j++;
    fclose(fmemberstemp);
    closeallfiles();
    printf("press any key to return to members management menu");
    getch();
    membermenu();
    }
    else
    {
        pos(40,11);
        printf("This User ID already exists!!");
        pos(40,12);
        printf("Press any key to return to member management menu...");
        fclose(fmemberstemp);
        closeallfiles();
        getch();
        membermenu();
    }
    }
    else{
    fmembers=fopen("members.txt","a");
    if(fmemberstemp==NULL)
    {
    fmemberstemp=fopen("memberstemp.txt","a+");
    }
    else
    {
    fmemberstemp=fopen("memberstemp.txt","a");
    }
    fclose(fmembers);
        pos(40,5);
    printf("Enter The First Name Of The User: ");
    fflush(stdin);
    gets(b.firstname);
    check=validatestringallchar(b.firstname);
     if(check==1)
     {  do{
        printf("Wrong input, Enter again: ");
        fflush(stdin);
        gets(b.firstname);
        check=validatestringallchar(b.firstname);
         }while(check==1);
     }
    pos(40,7);
    printf("Enter the Last Name Of The User: ");
    fflush(stdin);
    gets(b.lastname);
    check=validatestringallchar(b.lastname);
     if(check==1)
     {  do{
        printf("Wrong input, Enter again: ");
        fflush(stdin);
        gets(b.lastname);
        check=validatestringallchar(b.lastname);
         }while(check==1);
     }
    pos(40,9);
    printf("Enter The User's ID: ");
    fflush(stdin);
    scanf("%d",&b.id);
    if(checkidindex(b.id)==0)
    {
        pos(40,11);
    printf("Enter The User's Address:- ");
    pos(40,12);
    printf("Enter The Street Number: ");
    fflush(stdin);
    scanf("%d",&b.separateaddress.streetno);
    pos(40,13);
    printf("Enter The Street Name: ");
    fflush(stdin);
    gets(b.separateaddress.streetname);
    check=validatestringallchar(b.separateaddress.streetname);
     if(check==1)
     {  do{
        printf("Wrong input, Enter again: ");
        fflush(stdin);
        gets(b.separateaddress.streetname);
        check=validatestringallchar(b.separateaddress.streetname);
         }while(check==1);
     }
    pos(40,14);
    printf("Enter The City Name: ");
    fflush(stdin);
    gets(b.separateaddress.city);
    check=validatestringallchar(b.separateaddress.city);
     if(check==1)
     {  do{
        printf("Wrong input, Enter again: ");
        fflush(stdin);
        gets(b.separateaddress.city);
        check=validatestringallchar(b.separateaddress.city);
         }while(check==1);
     }
    pos(40,16);
    printf("Enter the User's Mobile Number: ");
    fflush(stdin);
    scanf("%d",&b.number);
    check=checkphonenumber(b.number);
    if(check==0)
        do
    {
        printf("Wrong Entry!!\n");
        printf("Enter a Valid Mobile Number: ");
        scanf("%d",&b.number);
        check=checkphonenumber(b.number);

    }while(check==0);
    pos(40,18);
    printf("Enter the User's Age: ");
    fflush(stdin);
    scanf("%d",&b.age);
    check=checkage(b.age);
     if(check==0)
        do
    {
        printf("Wrong Entry!!\n");
        printf("Enter a Valid Age: ");
        scanf("%d",&b.age);
        check=checkage(b.age);

    }while(check==0);
    pos(40,20);
    printf("Enter The User's Email: ");
    fflush(stdin);
    gets(b.email);
    check=validatemail(b.email);
     if(check==0)
     {  do{
        printf("Wrong input, Enter again: ");
        fflush(stdin);
        gets(b.email);
        check=validatemail(b.email);
         }while(check==0);
     }
    b.borrowcounter=0;
    fprintf(fmemberstemp,"%s,%s,%d,%d.%s.%s,0%d,%d,%d,%s\n",b.lastname,b.firstname,b.id,b.separateaddress.streetno,b.separateaddress.streetname,b.separateaddress.city,b.number,b.age,b.borrowcounter,b.email);
    fclose(fmemberstemp);
    members[j]=b;
    fclose(fmemberstemp);
    loadmembersinfo();
    fclose(fmemberstemp);
    j++;
    fclose(fmemberstemp);
    closeallfiles();
    printf("press any key to return to members management menu");
    getch();
    membermenu();
    }
    else
    {
        pos(40,11);
        printf("This User ID already exists!!");
        pos(40,12);
        printf("Press any key to return to member management menu...");
        fclose(fmemberstemp);
        closeallfiles();
        getch();
        membermenu();
    }
    }

}
void removemem()
{
    system("cls");
    int si=0;
    int dline;
    int linecounter;
    int nullcounter=NULL;
    int needcounter;
    char c;
    int searchtarget;
    pos(37,3);
    printf("\t\t\t Delete Members Menu");
    pos(40,5);
    printf("Please Enter the Member's ID: ");
    fflush(stdin);
    scanf("%d",&searchtarget);
    for(si=0;si<=savej;si++)
    {
        if(searchtarget == members[si].id)
        {   nullcounter++;
            needcounter=si;
            printf("%d",si);
            break;
        }
    }
    if(nullcounter!=NULL)
    {
    pos(40,7);
    printf("The Member is found");
    pos(40,9);
    printf("The Member's Information\n");
    pos(37,11);
    printf("First Name: %s",members[needcounter].firstname);
    pos(37,13);
    printf("Last Name: %s",members[needcounter].lastname);
    pos(37,15);
    printf("ID: %d",members[needcounter].id);
    pos(37,17);
    printf("Address: %s",members[needcounter].address);
    pos(37,19);
    printf("Phone Number: %d",members[needcounter].number);
    pos(37,21);
    printf("Age: %d",members[needcounter].age);
    pos(37,23);
    printf("Email: %s",members[needcounter].email);
    pos(37,25);
    printf("PRESS ANY KEY TO CONTINUE DELETING THE MEMBER");
    getch();
    fmembers=fopen("members.txt","r");
    dline=needcounter+1;
    linecounter=1;
    fmembersn=fopen("memberscopy.txt","w");
    fseek(fmembers,0,SEEK_SET);
    while(1)
    {
        c=getc(fmembers);
        if(c==EOF)
            break;
        if(c== '\n')
            linecounter++;
        if(linecounter != dline)
            putc(c,fmembersn);
    }
    fclose(fmembersn);
    fclose(fmembers);
    pos(37,29);
    printf("Member successfully deleted");
    loadmembersinfo();
    closeallfiles();
    pos(37,30);
    printf("To return to main menu press any key ");
    if(getch())
        mainmenu();
    }
    else
    {
        pos(37,6);
        printf("The Entered ID is not Valid,Press any key to Enter The ID again");
        closeallfiles();
        if(getch())
        membermenu();
    }
}
void printallmembers()
{

        system("cls");
        int counter=0;
        pos(37,3);
        printf("\t\t\t Books List");
        pos(37,4);
        printf("\t\t\t -----------");
        pos(0,5);
        printf("Last Name\tFirst Name\tID\tAddress  \t\tMobile No.\tAge\tEmail");
        pos(0,6);
        for(counter=0;counter<=savej;counter++)
        {
        printf("%s\t\t%s\t\t%d\t%s\t0%d\t%d\t%s\n",members[counter].lastname,members[counter].firstname,members[counter].id,members[counter].address,members[counter].number,members[counter].age,members[counter].email);
        }
        printf("\nPress any key to return to main menu...");
        getch();
        mainmenu();
}
void increaseborrowcounter()
{
    FILE *fmembersn;
    fmembers=fopen("members.txt","r");
    fmembersn=fopen("memberscopy.txt", "w");
    int si=0;
    int changeline;
    int neededcounter=NULL;
    int linecounter=0;
    char line[500];
    char searchtarget[50];
    int len;
    for(si=0;si<=savej;si++)
    {
        if (members[si].id == increasethisid)
        {
            neededcounter=si;
            break;
        }
    }
    if(neededcounter!=NULL)
    {
    changeline=neededcounter+1;
    while(!(feof(fmembers)))
    {
        strcpy(line,"\0");
        fflush(stdin);
        fgets(line,500,fmembers);
        len = strlen(line);
    if( line[len-1] == '\n' )
    line[len-1] = 0;
        if(!feof(fmembers))
        {
            linecounter++;
            if(linecounter!=changeline){
            fprintf(fmembersn,"%s",line);
            if(linecounter!=(changeline-1))
                fprintf(fmembersn,"\n");
            }
            else
            {
                fprintf(fmembersn,"%s,%s,%d,%s,0%d,%d,%d,%s\n",members[neededcounter].lastname,members[neededcounter].firstname,members[neededcounter].id,members[neededcounter].address,members[neededcounter].number,members[neededcounter].age,members[neededcounter].borrowcounter,members[neededcounter].email);

            }
        }
    }
    fclose(fmembersn);
    fclose(fmembers);
    closeallfiles();
    remove("members.txt");
    rename("memberscopy.txt","members.txt");
    loadmembersinfo();
    closeallfiles();
}
}
int checkidindex(int id)
{
    int ci;
    int nullcheck=NULL;
    int neededindex;
    for(ci=0;ci<=savej;ci++)
    {
        if(id==members[ci].id)
        {
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
