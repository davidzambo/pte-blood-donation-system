//
// Created by zdavid on 10/11/18.
//

#include "structs/donor.h"
#include <stdio.h>
#include <string.h>

void list_donors(DONOR *donor_list) {
    int i = 0;

    printf("=================== RECORDED BLOOD DONORS ==================\n");
    printf("ID\tNAME\t\t\tBLOOD\tEMAIL\tDONATIONS\tLAST\n");
    printf("\t\t\t\t\tTYPE\t\t\t\t\t\tDONATION\n\n");

    while (1) {
        if (donor_list[i].id == 0) {
            break;
        }

        // FORMAT THE NAME VIEW
        if (strlen(donor_list[i].name) < 12) {
            strcat(donor_list[i].name, "\t");
        }

        if (strlen(donor_list[i].name) < 8) {
            strcat(donor_list[i].name, "\t");
        }

        if (strlen(donor_list[i].name) <= 5) {
            strcat(donor_list[i].name, "\t");
        }

        // FORMAT THE EMAIL VIEW
        if (strlen(donor_list[i].email) < 12) {
            strcat(donor_list[i].email, "\t");
        }

        if (strlen(donor_list[i].email) < 8) {
            strcat(donor_list[i].email, "\t");
        }

        if (strlen(donor_list[i].email) <= 4) {
            strcat(donor_list[i].email, "\t");
        }


        printf("#%d\t%s\t%s\t\t%s\t%d\t%s\n",
               donor_list[i].id,
               donor_list[i].name,
               donor_list[i].blood_type,
               donor_list[i].email,
               donor_list[i].blood_donations,
               donor_list[i].last_donate_at);

        i++;
    }

    printf("\n\n");
}