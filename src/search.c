//
// Created by zdavid on 03/12/18.
//

#include <stdio.h>
#include "search.h"
#include "lib/validator.h"
#include "lib/strhelper.h"

int search(DONOR *donor_list, char *currentDate)
{
    int i = 0, name_length = 0, email_length = 0, isValid = 0;
    char action, bloodType[4];

    printf("========================================= SEARCH FOR DONORS =========================================\n");

    do {
        printf("\nWhat kind of blood group are you searching for? ");

        while (isValid == 0)
        {
            scanf(" %4[^\n]s", bloodType);
            getchar();

            isValid = is_valid_blood_type(bloodType);
        }

        printf("ID\tNAME\t\t\t\t\t\t\tBLOOD\tEMAIL\t\t\t\t\t\t\tDONATIONS\tLAST DONATION\n");
        printf("\t\t\t\t\t\t\t\t\tTYPE\n");

        while (donor_list[i].id != 0)
        {
            if (strcompare(bloodType, donor_list[i].blood_type))
            {
                char nameView[33] = {}, emailView[33] = {};

                // FORMAT THE NAME VIEW
                strcopy(nameView, donor_list[i].name);
                name_length = strlength(nameView);
                while (name_length < 28) {
                    strconcat(nameView, "\t");
                    name_length += 4;
                }

                // FORMAT THE EMAIL VIEW
                strcopy(emailView, donor_list[i].email);
                email_length = strlength(emailView);
                while (email_length < 28) {
                    strconcat(emailView, "\t");
                    email_length += 4;
                }

                printf("#%d\t%s\t%s\t\t%s\t%d\t\t\t%s\n",
                       donor_list[i].id,
                       nameView,
                       donor_list[i].blood_type,
                       emailView,
                       donor_list[i].blood_donations,
                       donor_list[i].last_donate_at);
            }
            i++;
        }

        printf("\n\t\t\t\t\t\t\t\t\tNO MORE RESULTS\t\t\t\t\t\t\t\t\t\t\t\t\t\n");

        do
        {
            printf("\nWould you like to send them an invitation for blood donation by email?");
            printf("\n(Y)es / (N)o / (S)earch again? / (B)ack to main menu");
            scanf("%1[\n]s", &action);
            getchar();

            if (action == 'Y') action = 'y';
            if (action == 'N') action = 'n';
            if (action == 'S' || action == 's') {
                break;
            }
            if (action == 'B') action = 'b';
        } while (!(action == 'n' || action == 'y' || action == 'b'));
    } while (action != 'b');
    return 0;
}
