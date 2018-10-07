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
#include <ctype.h>
int validatestringallchar(char *teststring)
{
    int x;
    int found=0;
    int len=strlen(teststring);
    for(x=0;x<len;x++)
    {
        if(isdigit(teststring[x])!=0)
        {
            found=1;
            break;
        }
    }
    if(found==1)
    {
        return 1;
    }
    else if(found==0)
        {
            return 0;
        }
        return 1;
}
int validatemail(char* teststring)
{
    char *ret;
    if(strchr(teststring,'@')!=NULL)
    {
        ret=strchr(teststring,'@');
        if(strchr(ret,'.')!=NULL)
        {
            if(strstr(teststring,".com")!=NULL)
                return 1;
        }
        else{
            return 0;
        }
    }
    else
        return 0;
}
int checkdaymonth(int month,int day)
{
 if(month == 1 && day>31)
    {
     return 0;
    }
    else if(month == 2 && day>28)
    {
        return 0;
    }
    else if(month == 3 && day>31)
    {
        return 0;
    }
    else if(month == 4 && day>30)
    {
        return 0;
    }
    else if(month == 5 && day>31)
    {
        return 0;
    }
    else if(month == 6 && day>30)
    {
      return 0;
    }
    else if(month == 7 && day>31)
    {
        return 0;
    }
    else if(month == 8 && day>31)
    {
       return 0;
    }
    else if(month == 9 && day>30)
    {
        return 0;
    }
    else if(month == 10 && day>31)
    {
        return 0;
    }
    else if(month == 11 && day>30)
    {
        return 0;
    }
    else if(month == 12 && day>31)
    {
        return 0;
}
else
{
    return 1;
}
}
int checkmonth(int month)
{
    if(month<0 || month>12)
        return 0;
    else
        return 1;
}
int checkyear(int year)
{
    if(year<1900 || year>2017)
        return 0;
    else
        return 1;
}
int checkavail(int noc,int avail)
{
    if(avail>noc)
        return 0;
    else
        return 1;
}
int checkphonenumber(int x)
{
    char temp[11];
    char c;
    char c2;
    int counter=0;
    int v=0;
    itoa(x,temp,10);
    while(temp[v]!='\0')
    {
        counter++;
        v++;
    }
    if(counter>10 || counter<10)
        return 0;
    else{
    c=temp[0];
    c2=temp[1];
    if(c!='1')
    {
        return 0;
    }
    else if(c2=='2' || c2=='0' || c2=='4' || c2=='5' || c2=='1')
        return 1;
    else
        return 0;
    }

}
int checkage(int x)
{
    if(x>100 || x<10)
        return 0;
    else
        return 1;
}
void converttolowercase(char* str)
{
    int v;
    for(v=0;str[v]!='\0';v++)
        {
    str[v] = tolower(str[v]);
        }
}
void swapnumbers(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
void swapstrings(char *str1, char *str2)
{
  char *temp = (char *)malloc((strlen(str1) + 1) * sizeof(char));
  strcpy(temp, str1);
  strcpy(str1, str2);
  strcpy(str2, temp);
  free(temp);
}
