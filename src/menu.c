//
// Created by zdavid on 02/10/18.
//

#include "menu.h"
#include <stdio.h>
#include <stdlib.h>

char render_menu()
{
    char menuitem = '0';
    while (((int) menuitem < 49) || ( (int) menuitem > 51))
    {
        printf("================================================ MENU ===============================================\n");
        printf("\nBy pressing the number of the selected menu item, you can\nchoose from the following actions:\n\n");
        printf("\n 1: View the list of the donors");
        printf("\n 2: Register a new donor");
        printf("\n 3: Search for donors by blood type");
        printf("\n\n q: Exit the program");
        printf("\n\nYour choice: ");
        scanf(" %c", &menuitem);

//        printf("\nCHOSEN decimal: %d char: %c", menuitem, menuitem);

        if (menuitem == 'q')
        {
            printf("\nExit.\n\n");
            break;
        }
    }

    return menuitem;
}
