
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

    char saveOrCancel, addNew = 'n';
    int length = 0;
    int isValid = 0;
    char str_buffer[32];

    while ((donor_list + length)->id != 0) {
        length++;
    }
    printf("LENGTH: %d", length);

    do {
        DONOR new_donor;

        printf("\n================= REGISTER A NEW DONOR =================\n");
        while (isValid == 0)
        {
            printf("Name: ");
            scanf(" %[^\n]s", new_donor.name);
            getchar();
            isValid = is_valid_name(new_donor.name);
        }
        isValid = 0;

        while (isValid == 0)
        {
            printf("Blood group: ");
            scanf("%[^\n]s", new_donor.blood_type);
            getchar();
            isValid = is_valid_blood_type(new_donor.blood_type);
        }
        isValid = 0;

        while (isValid == 0)
        {
            printf("Email: ");
            scanf("%[^\n]s", new_donor.email);
            getchar();
            isValid = is_valid_email(new_donor.email);
        }
        isValid = 0;

        while (isValid == 0)
        {
            printf("Number of blood donations before: ");
            scanf("%[^\n]s", str_buffer); // &new_donor.blood_donations
            getchar();
            isValid = is_valid_blood_donation(str_buffer);
        }
        new_donor.blood_donations = strtoint(str_buffer);
        isValid = 0;

        while (isValid == 0)
        {
            printf("Date of last donation: ");
            scanf("%11[^\n]s", new_donor.last_donate_at);
            getchar();
            isValid = is_valid_date(new_donor.last_donate_at);
        }

        printf("\n\nPlease check the entered values!\n");
        printf("\nName: %s", new_donor.name);
        printf("\nBlood group: %s", new_donor.blood_type);
        printf("\nEmail: %s", new_donor.email);
        printf("\nBlood donations before: %d", new_donor.blood_donations);
        printf("\nDate of last donation: %s", new_donor.last_donate_at);

        while ((saveOrCancel != 'c') && (saveOrCancel != 's'))
        {
            printf("\n\nSave record (s) or cancel (c)? ");
            scanf("%1s", &saveOrCancel);
            getchar();

            if (saveOrCancel == 'c')
            {
                return 0;
            }

            if (saveOrCancel == 's')
            {

                /*
                 * Copy the new donor data the the donor list
                 *
                 * Take care of length!
                 * We know, what is the length of the array,
                 * but array starts at 0;
                 *
                 */
                donor_list[length].id = length + 1;
                strcopy(donor_list[length].name, new_donor.name);
                strcopy(donor_list[length].blood_type, new_donor.blood_type);
                strcopy(donor_list[length].email, new_donor.email);
                donor_list[length].blood_donations = new_donor.blood_donations;
                strcopy(donor_list[length].last_donate_at, new_donor.last_donate_at);

                /*
                 * For debugging
                printf("\nid %d %d", donor_list[length].id, length);
                printf("\nname %s %s", donor_list[length].name, new_donor.name);
                printf("\nblood_type %s %s", donor_list[length].blood_type, new_donor.blood_type);
                printf("\nemail %s %s", donor_list[length].email, new_donor.email);
                printf("\nblood_donations %d %d", donor_list[length].blood_donations, new_donor.blood_donations);
                printf("\nlast_donate_at %s %s", donor_list[length].last_donate_at, new_donor.last_donate_at);
                */

                /*
                 * Write data to file
                 */
                FILE *db;
                db = fopen(FILENAME, "a");

                fprintf(db, "%d\t%s\t%s\t%s\t%d\t%s\n",
                        donor_list[length].id,
                        donor_list[length].name,
                        donor_list[length].blood_type,
                        donor_list[length].email,
                        donor_list[length].blood_donations,
                        donor_list[length].last_donate_at);

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
                
                fclose(db);

                /*
                 * Let user save another donor
                 */
                do
                {
                    printf("\n\nWould you like to add another donor? ([y]es / [n]o) ");
                    scanf("%1s", &addNew);
                    getchar();
                } while (!( addNew == 'y' || addNew == 'Y' || addNew == 'n'));

                /*
                 * Investigate Y and y
                 */
                if (addNew == 'Y' || addNew == 'y')
                {
                    addNew = 'y';
                    /*
                     * Should increment the length, as the investigation at the
                     * beginning of the function will not run again
                     */
                    length++;
                    /*
                     * Should set to 0 to enable all validators
                     */
                    isValid = 0;
                    /*
                     * Must 'disable' to let it read it from the user
                     */
                    saveOrCancel = '\0';
                    printf("\n\n");
                    /**
                     * break out the 'saveOrCancel' loop
                     */
                    break;
                }
            }
        }
    } while (addNew == 'y');

    return 1;
}
