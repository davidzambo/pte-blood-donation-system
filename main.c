#include<stdio.h>
#include<stdbool.h>

#include "src/initializer.h"
#include "src/lib/validator.h"
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
    DONOR *donor_list;

    // printf("\e[1;1H\e[2J");

    // do
    // {
    // 	printf("Enter the current date (i.e. 2018.09.29.), then please press <ENTER>:  ");
    // 	scanf("%s", &current_date);

    // 	isValidDate = is_valid_date(current_date);

    // 	if (is_valid_date == false)
    // 	{
    // 		printf("The given date is not in the proper format!\n\n");
    // 	}
    // } while (is_valid_date == false);

    // file_reader(FILENAME);

    donor_list = initializer(argc, FILENAME);

//    printf("\nMAIN ADDRESS: %p | 2nd donor: %s\n", donor_list, donor_list[1].name);
    do
    {
//        printf("\nIN DO ADDRESS: %p | 2nd donor: %s\n", donor_list, donor_list[1].name);
        menu_action = render_menu();
        switch (menu_action)
        {
            case '1':
//                printf("\nIN 1: ADDRESS: %p | 2nd donor: %s\n", donor_list, donor_list[1].name);
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