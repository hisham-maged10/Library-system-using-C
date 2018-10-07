/**
 * @author ${hisham_maged10}
 *https://github.com/hisham-maged10
 * ${DesktopApps}
 */
#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

typedef struct address
{
    int streetno;
    char streetname[25];
    char city[25];
}address;
typedef struct date{
    int m,d,y;
}date;
typedef struct books{
    char title[50];
    char author[25];
    char publisher[50];
    char ISBN[50];
    date published;
    int noc;
    int avail;
    char category[25];
    char compdate[25];
    int rank;
}book;
typedef struct members{
    char firstname[25];
    char lastname[25];
    int id;
    char address[200];
    address separateaddress;
    int number;
    int age;
    char email[100];
    int borrowcounter;
}member;

typedef struct borrows{
    char bisbn[50];
    int bid;
    char compdateissue[25];
    char compdatedue[25];
    date duedate;
    char returndate[25];

}borrow;

#endif // STRUCTS_H_INCLUDED
