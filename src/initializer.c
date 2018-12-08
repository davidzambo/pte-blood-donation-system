//
// Created by zdavid on 02/10/18.
//

#include "initializer.h"
#include "lib/filehelper.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <malloc.h>
#include "structs/donor.h"
#include "lib/strhelper.h"

DONOR *initializer(int argc, char args[]) {
    char *FILENAME;
    char line[255];
    unsigned int length = 0;
    FILE *file;
    FILENAME = args;

    if (argc < 2) {
        printf("ERROR: Missing donor list file name!\n");
        exit(1);
    }

    if (argc > 2) {
        printf("WARNING: Too many arguments!\n");
    }

    if (access(FILENAME, F_OK)) {
        printf("ERROR: Given file not found!\n");
        exit(1);
    }

    if (access(FILENAME, W_OK)) {
        printf("ERROR: Given file is not writeable\n");
    }

    file = fopen(FILENAME, "r");

    if (!file) {
        printf("\nNO FILE!\n");
        exit(1);
    } else {
        printf("\n- Database file (%s) opened!", FILENAME);
    }

    DONOR *donors = (DONOR*) malloc(sizeof(DONOR));

    while (fgets(line, 255, file)) {
        length++;
        /*
         * Add a new empty record to be able to detect
         * the end of a while loop
         */
        donors = realloc(donors, (length + 2 ) * sizeof(DONOR));
        if (!donors) {
            printf("\nUnable to allocate memory!\n");
            return 0;
        }
        prepare_record(line, (donors + length - 1));

    }

//    printf("\n3 Donor size: %d", sizeof(DONOR));

//    donors = realloc(donors, (length + 2) * sizeof(DONOR));
//    printf("\nDonor list size: %d", (int) malloc_usable_size((donors + 0)));
    strcopy(donors[length].name, "");

    fclose(file);

    printf("\n- Number of recorded donors initialized: %d", length);
    printf("\n- List of the donors is scanned into the memory!\n\n");

    return donors;
}
