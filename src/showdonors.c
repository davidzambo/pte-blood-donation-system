//
// Created by zdavid on 03/10/18.
//

#include <stdio.h>
#include <stdlib.h>
#include "showdonors.h"
#include "lib/filehelper.h"
#include <string.h>

struct DONOR
{
    int id;
    char name[64];
    char blood_type[4];
    char email[32];
    int blood_donations;
    char last_donate_at[11];
};

int show_donors(char *filename)
{
    int length = 0;
    int i, c, items = 0;
    Donor *donor = NULL;
    FILE *file;
    char line[255];
    char lineBuffer[100];

    file = fopen(filename, "r");

    if (!file) {
        printf("\nNO FILE!\n");
        return 1;
    } else {
        printf("\nFILE OK!\n");
    }

    printf("Sizeof donor: %d\n", sizeof(struct Donor));

//    donor =  malloc(sizeof(Donor));

    while (fgets(line, 255, file)) {
        printf("\nline: ");
        *donor  =  malloc(10* sizeof( **(struct DONOR)));

        c = 0;
        for (i = 0; (i < 255) && ( *(line + i) != '\n'); i++) {
            printf("%c", *(line + i));
            lineBuffer[c] = *(line + i);
            if (*(line + i) == '\t' || *(line + i) == '\n') {
                lineBuffer[c] = '\0';
//                printf("\nlineBuffer : %s\n", lineBuffer);
                c = -1;

                switch (items) {
                    case 0:
                        (*donor)[i].id = (int) *lineBuffer;
                        break;
                    case 1:
                        strcpy((*donor)[i].name, lineBuffer);
                        break;
                    case 2:
                        strcpy((*donor)[i].blood_type, lineBuffer);
                        break;
                    case 3:
                        strcpy((*donor)[i].email, lineBuffer);
                        break;
                    case 4:
                        (*donor)[i].blood_donations = (int) *lineBuffer;
                        break;
                    case 5:
                        strcpy((*donor)[i].last_donate_at, lineBuffer);
                        break;
                }
                items++;
            }
            c++;


//            printf("%c", (line + i));
//            for (c = 0; *(line + c) != '\t'; c++) {
//                printf("%c", *(line + c));
//            }
//            printf("\nname: ");
//            for (;*(line + c) != '\t'; c++ ) {
//                printf("%c", *(line + c));
//            }
        }

        printf("\nDETAILS:\n #%d | name: %s | blood type: %s | email: %s | donations: %d | last: %s", (*donor)[i].id, (*donor)[i].name, (*donor)[i].blood_type, (*donor)[i].email, (*donor)[i].blood_donations, (*donor)[i].last_donate_at);

        length++;
    }

    printf("length = %d\n", length);
    fclose(file);

    exit(0);
}