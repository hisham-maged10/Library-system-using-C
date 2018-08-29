#ifndef VALIDATION_FUNCTIONS_H_INCLUDED
#define VALIDATION_FUNCTIONS_H_INCLUDED

int checkisbnindex(char*);
int checkidindex(int);
int validatestringallchar(char*);
int validatemail(char*);
int checkyear(int);
int checkdaymonth(int,int);
int checkmonth(int);
int checkphonenumber(int);
void converttolowercase(char* str);

#endif // VALIDATION_FUNCTIONS_H_INCLUDED
