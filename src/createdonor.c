
//
// Created by zdavid on 02/10/18.
//

#include "createdonor.h"
#include <stdio.h>
#include "structs/donor.h"

int create_donor() {
    Donor donor;
    int donations;
    char save_or_cancel;

    printf("\e[1;1H\e[2J");
    printf("\n================= REGISTER A NEW DONOR =================\n");
    printf("Name: ");
    scanf("%[^\n]s", donor.name);

    printf("Blood group: ");
    scanf("%[^\n]s", donor.blood_type);

    printf("Email: ");
    scanf("%[^\n]s", donor.email);

    printf("Blood donations before: ");
    scanf("%d", &donor.blood_donations);

    printf("Date of last donation: ");
    scanf("%11[^\n]s", donor.last_donate_at);

    printf("\nPlease check the entered values!");
    printf("\nName: %s", donor.name);
    printf("\nBlood group: %s", donor.blood_type);
    printf("\nEmail: ", donor.email);
    printf("\nBlood donations before: %d", donations);
    printf("\nDate of last donation: %s", donor.last_donate_at);

    while ((save_or_cancel != 'n') && (save_or_cancel != 'y'))
    {
        printf("\nSave record (y) or cancel (n) ?");
        scanf("%s[^\n]", &save_or_cancel);

        if (save_or_cancel == 'n') {
            return 0;
        }

        if (save_or_cancel == 'y') {
            return 1;
        }
    }
     {

    }
    return 0;
}