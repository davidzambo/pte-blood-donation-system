#include <stdio.h>

char render_menu()
{
    char menuitem = 0;
    while ((menuitem < 49) || (menuitem > 51))
    {
        printf("\e[1;1H\e[2J");
        printf("========================== MENU ==========================\n");
        printf("\nBy pressing the number of the selected menu item, you can\nchoose from the following actions:\n\n");
        printf("\n 1: View the list of the donors");
        printf("\n 2: Register a new donor");
        printf("\n 3: Search for donors by blood type");
        printf("\n\n q: Exit the program");
        printf("\n\nYour choice: ");
        scanf("%c", &menuitem);
        
        if (menuitem == 'q')
        {
            printf("\nExit.\n\n");
            break;
        }
    }

    return menuitem;
}