//
// Created by zdavid on 02/10/18.
//

#include "initializer.h"
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

bool initializer(int argc, char args[])
{
    char *FILENAME;
    char exit_or_continue = 'y';
    FILENAME = args;

    printf("========== WELCOME TO OUR BLOOD DONATION SYSTEM ==========\n\n");

    if (argc < 2)
    {
        printf("ERROR: Missing donor list file name!\n");
        return false;
    }

    if (argc > 2)
    {
        printf("WARNING: Too many arguments!\n");
    }

    if (access(FILENAME, F_OK))
    {
        printf("ERROR: Given file not found!\n");
        return false;
    }

    if (access(FILENAME, W_OK))
    {
        printf("ERROR: Given file is not writeable\n");
        return false;
    }


    do
    {
        printf("\nContinue? (y/n) : ");
        scanf("%1c", &exit_or_continue);

        if (exit_or_continue == 'n') {
            return false;
        }

        if (exit_or_continue == 'y') {
            return true;
        }
        
    } while (!(exit_or_continue == 'n' || exit_or_continue == 'y'));

}
