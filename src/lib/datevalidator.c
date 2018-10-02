//
// Created by zdavid on 02/10/18.
//

#include "datevalidator.h"

#include <string.h>
#include <stdbool.h>

bool is_valid_date(char *date)
{
    if (strlen(date) != 11)
    {
        return false;
    }
    else
    {
        return true;
    }
}
