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

int initializer(int argc, char args[])
{
    char *FILENAME;
    char exit_or_continue;
    FILENAME = args;

    printf("========== WELCOME TO OUR BLOOD DONATION SYSTEM ==========\n");

    if (argc < 2)
    {
        printf("ERROR: Missing donor list file name!\n");
        exit(1);
    }

    if (argc > 2)
    {
        printf("WARNING: Too many arguments!\n");
    }

    if (access(FILENAME, F_OK))
    {
        printf("ERROR: Given file not found!\n");
        exit(1);
    }

    if (access(FILENAME, W_OK))
    {
        printf("ERROR: Given file is not writeable\n");
        exit(1);
    }

    printf("\n- Database file (%s) opened!", FILENAME);
    printf("\n- Number of recorded donors initialized: %d", get_record_length(FILENAME));
    printf("\n- List of the donors is scanned into the memory!\n\n");
    file_reader(FILENAME);

    while (!(exit_or_continue == 'n' || exit_or_continue == 'y'))
    {
        printf("Continue? (y/n): ");
        scanf("%s[^\n]", &exit_or_continue);

        if (exit_or_continue == 'n') {
            printf("\nExit...\n");
            exit(0);
        }

        if (exit_or_continue == 'y') {
            return 1;
        }
    }
}
