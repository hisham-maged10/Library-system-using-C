#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include "Structs.h"
#include "Global Variables.h"
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

int main()
{
    checksaveatstart();
    mainmenu();
    getch();
    return 0;
}


