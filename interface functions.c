#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
COORD coord={0,0};
void pos(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);


}
