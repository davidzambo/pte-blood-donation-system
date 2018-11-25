//
// Created by zdavid on 02/10/18.
//

#include "initializer.h"
#include "lib/filereader.h"
#include "lib/filehelper.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <malloc.h>
#include "structs/donor.h"
#include "lib/strhelper.h"

DONOR *initializer(int argc, char args[]) {
    char *FILENAME;
    char line[255];
    int length = 0;
    FILE *file;
    FILENAME = args;

    printf("=========== WELCOME TO OUR BLOOD DONATION SYSTEM ===========\n");

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

    DONOR *donors = malloc(sizeof(DONOR));
    DONOR *actual_donor = donors;

    while (fgets(line, 255, file)) {
        donors = realloc(donors, (length + 1) * sizeof(DONOR));
//        printf("\nlength %d | donors size: %d | DONOR size: %d", length, malloc_usable_size(donors), sizeof(DONOR));

        actual_donor = donors + length;
        prepare_record(line, (actual_donor));
//        printf("\nDETAILS: #%d | name: %s | blood type: %s | email: %s | donations: %d | last: %s",
//               actual_donor->id,
//               actual_donor->name,
//               actual_donor->blood_type,
//               actual_donor->email,
//               actual_donor->blood_donations,
//               actual_donor->last_donate_at);

//        printf("actual: %s", donors[length]->name);
//        printf("content: %s", &donors->name);
        length++;
    }

    fclose(file);

    printf("\n- Number of recorded donors initialized: %d", length);
    printf("\n- List of the donors is scanned into the memory!\n\n");

    return donors;
}
