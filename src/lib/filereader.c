//
// Created by zdavid on 02/10/18.
//

#include "filereader.h"
#include "filehelper.h"
#include <stdio.h>
#include <stdbool.h>
#include "../structs/donor.h"

bool file_reader(char *FILENAME){
    int i;
    FILE *file;
    char buff[255];
    int tmp;
    unsigned int length;
    Donor donors[20];
    char data[30];
    char *actual;

    file = fopen(FILENAME, "r");

    length = get_record_length(FILENAME);
    Donor Donors[length];
    printf("Memory have been allocated for %d record", length);
    printf("length: %d\n", length);
    for (i = 0; i < length; i ++)
    {

    }

    // read from line from line
    // pass it to an extractor
    //
//     read every line
    while (tmp != EOF)
    {
        // read every char in line
        do
        {
            // read every char until a TAB
            i = 0;
            do
            {
                tmp = fgetc(file);
                data[i] = tmp;
                i++;
            } while (tmp == 9);
            printf("%s", data);

            // TODO: SOLVE WINDOW AND MAC NEW LINE
        } while (!((tmp == 10) || (tmp == EOF)));
        printf("\nTHAT WAS A LINE\n");
        tmp = EOF;
    }
    printf("\nTHAT WAS ALL\n");

    fclose(file);
}
