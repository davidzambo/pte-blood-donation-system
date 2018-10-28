//
// Created by zdavid on 02/10/18.
//

#include "filehelper.h"
#include "../structs/donor.h"
#include <stdio.h>
#include <string.h>

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

void prepare_record(Donor *donor, char *line)
{
    char tmp[64];
    int i = 0;
    int key = 0;
    int key_char = 0;
    char data[5][64];

    printf("run\n");
    printf("line %s\n", line);

    for (i = 0; i < 255; i++)
    {
//        printf("%d : %c\n", i, line[i]);
//        printf("%d \n", line[i]);
//        printf("key: %d; key_char: %d\n", key, key_char);
        data[key][key_char] = line[i];

        if ((int) line[i] == 9) {
            printf("data[%d][%d]: %s \n", key, key_char, data[key] );
            key++;
            key_char = 0;
        }
        key_char ++;
        if ((int) line[i] == "\n") {
            break;
        }
    }

    strcpy(donor->name, data[0]);
    strcpy(donor->blood_type, data[1]);
    strcpy(donor->email, data[2]);
    strcpy(donor->blood_donations, data[3]);
    strcpy(donor->last_donate_at, data[4]);

    printf("name: %s \n", donor->name);
}
