#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include "initializer.h"
#include "datevalidator.h"
#include "filereader.h"
#include "donor.h"
#include "newdonor.h"
#include "menu.h"

void main(int argc, char *args[])
{
	char menu_action;
	char current_date[10];
	bool isValidDate;
	char *FILENAME;
	char *menuitem;
	FILENAME = *(args + 1);

	printf("\e[1;1H\e[2J");

	if (initializer(argc, FILENAME) == false)
	{
		return;
	}

	printf("==== WELCOME TO OUR BLOOD DONATION SYSTEM ====\n\n");

	// do 
	// {
	// 	printf("Please enter the current date (i.e. 2018.09.29.), then please press <ENTER>:  ");
	// 	scanf("%s", &current_date);

	// 	isValidDate = is_valid_date(current_date);

	// 	if (isValidDate == false) 
	// 	{
	// 		printf("The given date is not in the proper format!\n\n");
	// 	} 
	// } while (isValidDate == false);

	// file_reader(FILENAME);
	
	do
	{
		menu_action = render_menu();
		switch (menu_action)
		{
		case '1':
			printf("show");
			break;
		case '2':
			create_new_donor();
			break;
		case '3':
			printf("search");
			break;
		case 'q': // exit on "q"
			return;
		default:
			printf("something fucked up");
		}
	} while (menu_action != (char) 'q');

	printf("Hooray! You're not an idiot!!!\n");
	return;

}

