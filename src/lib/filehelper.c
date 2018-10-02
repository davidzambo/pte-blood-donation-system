//
// Created by zdavid on 02/10/18.
//

#include "filehelper.h"
#include "../structs/donor.h"
#include <stdio.h>

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

    return length;
}

Donor prepare_record(char *line)
{

}
