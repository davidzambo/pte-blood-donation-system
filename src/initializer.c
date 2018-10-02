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
    FILENAME = args;

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

    return true;
}
