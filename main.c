#include<stdio.h>
#include<stdbool.h>

#include "src/initializer.h"
#include "src/lib/validator.h"
#include "src/listdonors.h"
#include "src/lib/strhelper.h"
#include "src/createdonor.h"
#include "src/menu.h"
#include "src/search.h"

int main(int argc, char *args[])
{
    char menu_action;
    char currentDate[12];
    char *FILENAME = args[1];
    char *menuitem;
    int isValid = 0;
    DONOR *donor_list;

    printf("================================ WELCOME TO OUR BLOOD DONATION SYSTEM ===============================\n");

     do
     {
     	printf("Enter the current date (i.e. 2018.09.29.), then please press <ENTER>:  ");
     	scanf("%s", currentDate);
     	getchar();
        isValid = is_valid_date(currentDate, 0);
     } while (isValid != 1);

    donor_list = initializer(argc, FILENAME);

    do
    {
        menu_action = render_menu();
        switch (menu_action)
        {
            case '1':
                list_donors(donor_list);

//                submenu = show_donors(FILENAME);
//
//                if (submenu == -1)
//                {
//                    menu_action = 'q';
//                }

                break;
            case '2':
                if (create_donor(FILENAME, donor_list) == -1)
                {
                    menu_action = 'q';
                };
                break;
            case '3':
                search(donor_list, currentDate);
                break;
            case 'q': // exit on "q"
                return 0;
            default:
                printf("something fucked up");
        }
    } while (menu_action != (char) 'q');

    printf("\nExit...\n\n");
    return 0;

}