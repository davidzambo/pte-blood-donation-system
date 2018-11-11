#include<stdio.h>
#include<stdbool.h>

#include "src/initializer.h"
#include "src/lib/datevalidator.h"
#include "src/lib/filereader.h"
#include "src/listdonors.h"
#include "src/lib/strhelper.h"
#include "src/createdonor.h"
#include "src/showdonors.h"
#include "src/menu.h"

int main(int argc, char *args[])
{
    char menu_action;
    char current_date[10];
    bool isValidDate;
    char *FILENAME = args[1];
    char *menuitem;
    int submenu;
    DONOR *donor;

    // printf("\e[1;1H\e[2J");

    // do
    // {
    // 	printf("Enter the current date (i.e. 2018.09.29.), then please press <ENTER>:  ");
    // 	scanf("%s", &current_date);

    // 	isValidDate = is_valid_date(current_date);

    // 	if (isValidDate == false)
    // 	{
    // 		printf("The given date is not in the proper format!\n\n");
    // 	}
    // } while (isValidDate == false);

    // file_reader(FILENAME);

    initializer(argc, FILENAME);

    do
    {
        menu_action = render_menu();
        switch (menu_action)
        {
            case '1':
                list_donors(donor);

//                submenu = show_donors(FILENAME);
//
//                if (submenu == -1)
//                {
//                    menu_action = 'q';
//                }

                break;
            case '2':
                if (create_donor(FILENAME) == -1)
                {
                    menu_action = 'q';
                };
                break;
            case '3':
                printf("search");
                break;
            case 'q': // exit on "q"
                return 0;
            default:
                printf("something fucked up");
        }
    } while (menu_action != (char) 'q');

    printf("Hooray! You're not an idiot!!!\n");
    return 0;

}