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
    int length;
    char data[30];
    char *actual;
    char action;
    bool repeat = false;
    char new[] = "../../db.txt";
    file = fopen(new, "r");

    length = get_record_length(new);
    DONOR Donors[length];
    printf("Memory have been allocated for %d record\n", length);
    printf("length: %d\n", length);

    printf("\nfilename: %s", FILENAME);
    return true;

    for (i = 0; i < length; i ++)
    {
        fscanf(file, "%s", buff);
//        Donors[i] = prepare_record(buff);
    }

    fclose(file);

    do
    {
        printf("\nBack to menu (N) or exit (Y)?\n");
        scanf("%c", &action);

        switch (action) {
            case 'N':
            case 'n':
                return 1;
            case 'Y':
            case 'y':
                return -1;
            default:
                repeat = true;
        }
    } while (repeat);
}
