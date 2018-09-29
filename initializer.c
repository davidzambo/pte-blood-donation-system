#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

bool initializer(int argc, char args[])
{
    if (argc < 2)
    {
        printf("Whoops!!! Missing donor list file name!\n");
        return false;
    }

    if (argc > 2)
    {
        printf("Whoops!!! Too many arguments!\n");
        return false;
    }

    if (access(args[0], F_OK) != -1)
    {

    }

    return true;
}