//
// Created by zdavid on 03/10/18.
//

#include <stdio.h>
#include <stdlib.h>
#include "showdonors.h"
#include "lib/filehelper.h"
#include <string.h>

int show_donors(char *filename)
{
    int length = 0;
    int i, c, items = 0;
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

    DONOR *donor = malloc((length + 1) * sizeof(DONOR));

    while (fgets(line, 255, file)) {
        printf("\nline: ");
        donor  =  (DONOR *) realloc(donor, (length + 1 ) * sizeof(DONOR));

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
                        donor->id = (int) *lineBuffer;
                        break;
                    case 1:
                        strcpy(donor->name, lineBuffer);
                        break;
                    case 2:
                        strcpy(donor->blood_type, lineBuffer);
                        break;
                    case 3:
                        strcpy(donor->email, lineBuffer);
                        break;
                    case 4:
                        donor->blood_donations = (int) *lineBuffer;
                        break;
                    case 5:
                        strcpy(donor->last_donate_at, lineBuffer);
                        break;
                }
                items++;
            }
            c++;
        }

        printf("\nDETAILS:\n #%d | name: %s | blood type: %s | email: %s | donations: %d | last: %s", donor->id, donor->name, donor->blood_type, donor->email, donor->blood_donations, donor->last_donate_at);

        length++;
    }

    printf("length = %d\n", length);
    fclose(file);

    return 0;
}