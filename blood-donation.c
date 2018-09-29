#include<stdio.h>
#include<stdbool.h>
#include "initializer.h"
#include "datevalidator.h"

void main(int argc, char *args[]){
	int i;
	char current_date[10];
	bool isValidDate;

	if (initializer(argc, *args) == false)
	{
		return;
	}

	printf("==== WELCOME TO OUR BLOOD DONATION SYSTEM ====\n\n");
	printf("db_name: %s", args);
	do 
	{
		printf("Please enter the current date (i.e. 2018.09.29.), then please press <ENTER>:  ");
		scanf("%s", &current_date);

		isValidDate = is_valid_date(current_date);

		if (isValidDate == false) 
		{
			printf("The given date is not in the proper format!\n\n");
		} 
	} while (isValidDate == false);

	printf("Hooray! You're not an idiot!!!\n");

}

