//
// Created by zdavid on 02/10/18.
//

#include "filehelper.h"
#include "../structs/donor.h"
#include "strhelper.h"
#include <stdio.h>
#include <string.h>
#define  MAX_LINE_LENGTH 255

int get_record_length(char *filename)
{
    int length = 0;
    char buffer[255];
    FILE *file;

    file = fopen(filename, "r");

    while (fgets(buffer, 255, file))
    {
        length++;
    }

    fclose(file);

    return length;
}

/**
 * Prepare data and create Donor from line
 *
 * @param line
 *
 */
DONOR *prepare_record(char *line, DONOR *donor)
{
    char lineBuffer[100];
    int i, c = 0, items = 0;

    /*
     * Starts to read from the beginning of the line until '\n'
     */
    for (i = 0; (i < MAX_LINE_LENGTH) && ( *(line + i) != '\n'); i++) {

        lineBuffer[c] = *(line + i);

        if (*(line + i) == '\t' || *(line + i) == '\n') {
            lineBuffer[c] = '\0';

            c = -1;
            switch (items) {
                case 0:
                    donor->id = strtoint(lineBuffer);
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
                    donor->blood_donations = strtoint(lineBuffer);
                    break;
                case 5:
                    strcpy(donor->last_donate_at, lineBuffer);
                    break;
            }
            items++;
        }
        c++;
    }

//    printf("\nDETAILS: #%d | name: %s | blood type: %s | email: %s | donations: %d", donor->id, donor->name, donor->blood_type, donor->email, donor->blood_donations, donor->last_donate_at);
    return donor;
}
