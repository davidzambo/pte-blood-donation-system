
//
// Created by zdavid on 02/10/18.
//

#include "createdonor.h"
#include <stdio.h>
#include <malloc.h>
#include "structs/donor.h"
#include "lib/filehelper.h"
#include "lib/strhelper.h"
#include "lib/validator.h"

/**
 * Create and store donor into file
 *
 * @param FILENAME
 * @param donor_list
 * @return
 */
int create_donor(char *FILENAME, DONOR *donor_list) {

    char saveOrCancel = 'x', addNew = 'n';
    unsigned int length = 0;
    int isValid = 0;
    char str_buffer[32];

    while (donor_list[length].name[0] != '\0') {
        length++;
    }

    do {
        DONOR newDonor;

        printf("\n================= REGISTER A NEW DONOR =================\n");
        while (isValid == 0)
        {
            printf("Name: ");
            scanf(" %[^\n]s", newDonor.name);
//            getchar();
//            printf("\nSCANNED: %s", newDonor.name);
            isValid = is_valid_name(newDonor.name);
        }
        isValid = 0;

        while (isValid == 0)
        {
            printf("Blood group: ");
            scanf(" %[^\n]s", newDonor.blood_type);
//            getchar();
            isValid = is_valid_blood_type(newDonor.blood_type);
        }
        isValid = 0;

        while (isValid == 0)
        {
            printf("Email: ");
            scanf(" %[^\n]s", newDonor.email);
//            getchar();
            isValid = is_valid_email(newDonor.email, 0);
        }
        isValid = 0;

        while (isValid == 0)
        {
            printf("Number of blood donations before: ");
            scanf(" %[^\n]s", str_buffer);
//            getchar();
            isValid = is_valid_blood_donation(str_buffer);
        }
        newDonor.blood_donations = (unsigned) strtoint(str_buffer);
        isValid = 0;

        while (isValid == 0)
        {
            printf("Date of last donation: ");
            scanf(" %11[^\n]s", newDonor.last_donate_at);
//            getchar();
            isValid = is_valid_date(newDonor.last_donate_at, 0);
        }

        printf("\n\nPlease check the entered values!\n");
        printf("\nName: %s", newDonor.name);
        printf("\nBlood group: %s", newDonor.blood_type);
        printf("\nEmail: %s", newDonor.email);
        printf("\nBlood donations before: %d", newDonor.blood_donations);
        printf("\nDate of last donation: %s", newDonor.last_donate_at);

        do
        {
            printf("\n\nSave record (s) or cancel (c)? ");
            scanf(" %c", &saveOrCancel);
            getchar();

            if (saveOrCancel == 'c')
            {
                return 0;
            }

            if (saveOrCancel == 's')
            {

                length++;
                /**
                 * Reallocate memory size for donor list
                 *
                 * length is the number of elements that the array contains
                 * So if you have a 12 length donor list, it contains only
                 * 11 donors.
                 *
                 * At this step, we filled up the last available donor,
                 * so we have to allocate a new one to separate the whole list
                 * from the memory during the while loop
                 *
                 * That's the reason of the length + 2
                 */

                donor_list = realloc(donor_list, (length + 2) * sizeof(DONOR));

                if (!donor_list) {
                    printf("\nUnable to allocate memory!\n");
                    return 0;
                }

                strcopy(donor_list[length].name, "\0");

                /*
                 * Copy the new donor data the the donor list
                 *
                 * Take care of length!
                 * We know, what is the length of the array,
                 * but array starts at 0;
                 *
                 */
                donor_list[length - 1].id = length;
                strcopy(donor_list[length - 1].name, newDonor.name);
                strcopy(donor_list[length - 1].blood_type, newDonor.blood_type);
                strcopy(donor_list[length - 1].email, newDonor.email);
                donor_list[length - 1].blood_donations = newDonor.blood_donations;
                strcopy(donor_list[length - 1].last_donate_at, newDonor.last_donate_at);


                /*
                 * For debugging
                printf("\nid %d %d", donor_list[length].id, length);
                printf("\nname %s %s", donor_list[length].name, newDonor.name);
                printf("\nblood_type %s %s", donor_list[length].blood_type, newDonor.blood_type);
                printf("\nemail %s %s", donor_list[length].email, newDonor.email);
                printf("\nblood_donations %d %d", donor_list[length].blood_donations, newDonor.blood_donations);
                printf("\nlast_donate_at %s %s", donor_list[length].last_donate_at, newDonor.last_donate_at);
                */

                /*
                 * Write data to file
                 */
                FILE *db;
                db = fopen(FILENAME, "a");

                fprintf(db, "%d\t%s\t%s\t%s\t%d\t%s\n",
                        donor_list[length - 1].id,
                        donor_list[length - 1].name,
                        donor_list[length - 1].blood_type,
                        donor_list[length - 1].email,
                        donor_list[length - 1].blood_donations,
                        donor_list[length - 1].last_donate_at);

                fclose(db);


//                int i = 0;
//                for (i = 0; i < 20; i++)
//                {
//                    if (i == length - 1)
//                    {
//                        printf("\nTHATS THE LAST ONE!!!\n");
//                    }
//                    printf("DONOR: %p | %d\t%s\t%s\t%s\t%d\t%s\n",
//                           &donor_list[i],
//                            donor_list[i].id,
//                            donor_list[i].name,
//                            donor_list[i].blood_type,
//                            donor_list[i].email,
//                            donor_list[i].blood_donations,
//                            donor_list[i].last_donate_at);
//                }

                printf("\nNew record successfully saved to file!");

                /*
                 * Let user save another donor
                 */
                do
                {
                    printf("\n\nWould you like to add another donor? ([y]es / [n]o) ");
                    scanf(" %c", &addNew);
                } while (!( addNew == 'y' || addNew == 'Y' || addNew == 'n' || addNew == 'N'));

                if (addNew == 'n' || addNew == 'N')
                {
                    return 0;
                }
                /*
                 * Investigate Y and y
                 */
                if (addNew == 'Y' || addNew == 'y')
                {
                    addNew = 'y';

                    /*
                     * Should set to 0 to enable all validators
                     */
                    isValid = 0;
                    /*
                     * Must 'disable' to let it read it from the user
                     */
//                    saveOrCancel = 's';
                    /**
                     * break out the 'saveOrCancel' loop
                     */
//                    break;
                }
            }
        } while ((saveOrCancel != 'c') && (saveOrCancel != 's'));

    } while (addNew == 'y');

    return 1;
}
