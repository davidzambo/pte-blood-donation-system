//
// Created by zdavid on 03/10/18.
//

#include <stdio.h>
#include "showdonors.h"
#include "lib/filehelper.h"

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
    int i;
    FILE *file;
    int length = 0;
    char *line[255];

    file = fopen(filename, "r");
    length = get_record_length(filename);
    Donor Donors[length];
    printf("%d\n", sizeof(Donors));

    for (i = 0; i < 1; i++)
    {
        fgets(line, 255, file);
        prepare_record(&Donors[i], line);
    }
    printf("donor 2 name: %s", Donors[1].name );
    printf("filesize: %d\n", length);
    fclose(file);
    return 1;
}