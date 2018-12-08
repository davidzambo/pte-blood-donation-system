//
// Created by zdavid on 02/10/18.
//

#include "filehelper.h"
#include "../structs/donor.h"
#include "strhelper.h"
#include <stdio.h>
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
 * @param donor
 * @returns int
 */
int prepare_record(char *line, DONOR *donor)
{
    char lineBuffer[100];
    int i, c = 0, items = 0;


    for (i = 0; i < MAX_LINE_LENGTH; i++) {

        lineBuffer[c] = *(line + i);

//        printf("\nLINE: char: %c, int: %d", *(line + i), *(line + i));
        /*
         * Starts to read from the beginning of the line until '\n'
         * If it founds a '\t', it means, that it is a new property of the donor
         * so we should increase the 'item' number
         *
         * items:
         * 0: id
         * 1: name
         * 2: blood_type
         * 3: email
         * 4. sum donations before
         * 5. last donated at
         */
        if (*(line + i) == '\t' || *(line + i) == '\n') {
            lineBuffer[c] = '\0';

            switch (items) {
                case 0:
                    donor->id = (unsigned) strtoint(lineBuffer);
                    break;
                case 1:
                    strcopy(donor->name, lineBuffer);
                    break;
                case 2:
                    strcopy(donor->blood_type, lineBuffer);
                    break;
                case 3:
                    strcopy(donor->email, lineBuffer);
                    break;
                case 4:
                    donor->blood_donations = (unsigned) strtoint(lineBuffer);
                    break;
                case 5:
                    strcopy(donor->last_donate_at, lineBuffer);
                    break;
                default:
                    break;
            }
            c = -1;
            items++;
        }
        c++;

        if (*(line + i) == '\n') {
            break;
        }
    }

    return 0;
}
