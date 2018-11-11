
//
// Created by zdavid on 02/10/18.
//

#include "createdonor.h"
#include <stdio.h>
#include "structs/donor.h"
#include "lib/filehelper.h"

int create_donor(char *FILENAME) {
    DONOR donor;

    char save_or_cancel;
    printf("\e[1;1H\e[2J");
    printf("\n================= REGISTER A NEW DONOR =================\n");

    printf("Name: ");
    scanf("%[^\n]s", donor.name);
    getchar();

    printf("Blood group: ");
    scanf("%[^\n]s", donor.blood_type);
    getchar();

    printf("Email: ");
    scanf("%[^\n]s", donor.email);
    getchar();

    printf("Number of blood donations before: ");
    scanf("%d", &donor.blood_donations);
    getchar();

    printf("Date of last donation: ");
    scanf("%11[^\n]s", donor.last_donate_at);
    getchar();

    printf("\nPlease check the entered values!\n");
    printf("\nName: %s", donor.name);
    printf("\nBlood group: %s", donor.blood_type);
    printf("\nEmail: %s", donor.email);
    printf("\nBlood donations before: %d", donor.blood_donations);
    printf("\nDate of last donation: %s", donor.last_donate_at);

    while ((save_or_cancel != 'c') && (save_or_cancel != 's'))
    {
        printf("\n\nSave record (s) or cancel (c)? ");
        scanf("%1s", &save_or_cancel);
        getchar();

        if (save_or_cancel == 'c') {
            return 0;
        }

        if (save_or_cancel == 's') {
            FILE *db;
            db = fopen(FILENAME, "a");
            int length = get_record_length(FILENAME);
            fprintf(db, "%d\t%s\t%s\t%s\t%d\t%s\n", length + 1, donor.name, donor.blood_type, donor.email, donor.blood_donations, donor.last_donate_at);
            fclose(db);
            return 1;
        }
    }
}