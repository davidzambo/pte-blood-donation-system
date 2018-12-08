//
// Created by zdavid on 10/11/18.
//

#include "structs/donor.h"
#include "lib/strhelper.h"
#include "lib/validator.h"
#include <stdio.h>

void list_donors(DONOR *donor_list) {
    int i = 0, name_length = 0, email_length = 0;
    printf("======================================= RECORDED BLOOD DONORS =======================================\n");
    printf("ID\tNAME\t\t\t\t\t\t\tBLOOD\tEMAIL\t\t\t\t\t\t\tDONATIONS\tLAST DONATION\n");
    printf("\t\t\t\t\t\t\t\t\tTYPE\n");

    while (1) {
        if (!donor_list[i].name[0]) {
            break;
        }
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

        if (!is_valid_email(donor_list[i].email, 1))
        {
            printf("\t\t\t\t\t\t\t\t\t\t\tINVALID EMAIL ADDRESS!!!\n");
        }

        if (!is_valid_date(donor_list[i].last_donate_at, 1))
        {
            printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tINVALID LAST DONATION DATE!!!\n");
        }
        i++;
    }

    printf("\n\n");
}