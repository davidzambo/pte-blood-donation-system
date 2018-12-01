
//
// Created by zdavid on 02/10/18.
//

#include "createdonor.h"
#include <stdio.h>
#include <malloc.h>
#include "structs/donor.h"
#include "lib/filehelper.h"
#include "lib/strhelper.h"


int create_donor(char *FILENAME, DONOR *donor_list) {

    char save_or_cancel;
    char length = 0;

    while ((donor_list + length)->id != 0) {
        length++;
    }

    DONOR new_donor;

    printf("LENGTH: %d", length);

    printf("\n================= REGISTER A NEW DONOR =================\n");

    printf("Name: ");
    scanf(" %[^\n]s", new_donor.name);
    getchar();

    printf("Blood group: ");
    scanf("%[^\n]s", new_donor.blood_type);
    getchar();

    printf("Email: ");
    scanf("%[^\n]s", new_donor.email);
    getchar();

    printf("Number of blood donations before: ");
    scanf("%d", &new_donor.blood_donations);
    getchar();

    printf("Date of last donation: ");
    scanf("%11[^\n]s", new_donor.last_donate_at);
    getchar();

    printf("\nPlease check the entered values!\n");
    printf("\nName: %s", new_donor.name);
    printf("\nBlood group: %s", new_donor.blood_type);
    printf("\nEmail: %s", new_donor.email);
    printf("\nBlood donations before: %d", new_donor.blood_donations);
    printf("\nDate of last donation: %s", new_donor.last_donate_at);

    while ((save_or_cancel != 'c') && (save_or_cancel != 's'))
    {
        printf("\n\nSave record (s) or cancel (c)? ");
        scanf("%1s", &save_or_cancel);
        getchar();

        if (save_or_cancel == 'c') {
            return 0;
        }

        if (save_or_cancel == 's') {
            donor_list = realloc(donor_list, (length + 2) * sizeof(DONOR));

            (donor_list + length + 1)->id = length + 1;
            strcopy((donor_list + length + 1)->name, new_donor.name);
            strcopy((donor_list + length + 1)->blood_type, new_donor.blood_type);
            strcopy((donor_list + length + 1)->email, new_donor.email);
            (donor_list + length + 1)->blood_donations = new_donor.blood_donations;
            strcopy((donor_list + length + 1)->last_donate_at, new_donor.last_donate_at);

            printf("\nid %d %d", (donor_list + length + 1)->id, length + 1);
            printf("\nname %s %s", (donor_list + length + 1)->name, new_donor.name);
            printf("\nblood_type %s %s", (donor_list + length + 1)->blood_type, new_donor.blood_type);
            printf("\nemail %s %s", (donor_list + length + 1)->email, new_donor.email);
            printf("\nblood_donations %d %d", (donor_list + length + 1)->blood_donations, new_donor.blood_donations);
            printf("\nlast_donate_at %s %s", (donor_list + length + 1)->last_donate_at, new_donor.last_donate_at);





            donor_list = realloc(donor_list, (length + 1) * sizeof(DONOR));

            FILE *db;
            db = fopen(FILENAME, "a");
            int length = get_record_length(FILENAME);
            fprintf(db, "%d\t%s\t%s\t%s\t%d\t%s\n", length + 1, new_donor.name, new_donor.blood_type, new_donor.email, new_donor.blood_donations, new_donor.last_donate_at);
            fclose(db);
            return 1;
        }
    }
}