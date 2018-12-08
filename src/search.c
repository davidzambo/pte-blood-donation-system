//
// Created by zdavid on 03/12/18.
//

#include <stdio.h>
#include <stdlib.h>
#include "search.h"
#include "lib/validator.h"
#include "lib/strhelper.h"

int search(DONOR *donor_list, char *currentDate)
{
    int i = 0, nameLength = 0, emailLength = 0, isValid = 0, resultCounter = 0;
    char action, bloodType[4];
    DONOR** results = malloc(1 * sizeof(DONOR*));

    printf("========================================= SEARCH FOR DONORS =========================================\n");

    do {

        while (isValid == 0)
        {
            printf("\nWhat kind of blood group are you searching for? ");
            scanf(" %4[^\n]s", bloodType);
            getchar();

            isValid = is_valid_blood_type(bloodType);
        }

        printf("\nID\tNAME\t\t\t\t\t\t\tBLOOD\tEMAIL\t\t\t\t\t\t\tDONATIONS\tLAST DONATION\n");
        printf("\t\t\t\t\t\t\t\t\tTYPE\n");

        while (donor_list[i].name[0] != 0)
        {
            if (strcompare(bloodType, donor_list[i].blood_type))
            {
                resultCounter++;
                /*
                 * Store the address of the matching donor in an array
                 */
                results = realloc(results, resultCounter + 1 * sizeof(DONOR*));
                results[resultCounter - 1] = &donor_list[i];
            }
            i++;
        }

        for (i = 0; i < resultCounter; i++)
        {
            char nameView[33] = {}, emailView[33] = {};

            // FORMAT THE NAME VIEW
            strcopy(nameView, results[i]->name);
            nameLength = strlength(nameView);
            while (nameLength < 28) {
                strconcat(nameView, "\t");
                nameLength += 4;
            }

            // FORMAT THE EMAIL VIEW
            strcopy(emailView, results[i]->email);
            emailLength = strlength(emailView);
            while (emailLength < 28) {
                strconcat(emailView, "\t");
                emailLength += 4;
            }

            printf("#%d\t%s\t%s\t\t%s\t%d\t\t\t%s\n",
                   results[i]->id,
                   nameView,
                   results[i]->blood_type,
                   emailView,
                   results[i]->blood_donations,
                   results[i]->last_donate_at);
        }

        printf("\n\t\t\t\t\t\t\t\t\tNO MORE RESULTS\t\t\t\t\t\t\t\t\t\t\t\t\t\n");
        printf("=====================================================================================================\n");
        do
        {
            printf("\nWould you like to send them an invitation for blood donation by email?");
            printf("\n(Y)es / (N)o / (S)earch again ? ");
            scanf("%c", &action);
            getchar();

            if (action == 'Y') action = 'y';
            if (action == 'N') action = 'n';

            if (action == 'S' || action == 's')
            {
                isValid = 0;
                i = 0;
                break;
            }

        } while (!(action == 'n' || action == 'y'));

        if (action == 'n')
        {
            return 0;
        }

        if (action == 'y')
        {
            for (i = 0; i < resultCounter; i++)
            {
                results[i]->blood_donations++;
                strcopy(results[i]->last_donate_at, currentDate);
            }

            printf("\n %d invitations successfully sent!\n", resultCounter + 1);
            return 0;
        }
    } while (action != 'b');

    return 0;
}
