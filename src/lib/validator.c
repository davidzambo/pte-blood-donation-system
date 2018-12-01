//
// Created by zdavid on 02/10/18.
//

#include <stdio.h>
#include "validator.h"
#include "strhelper.h"

/**
 * Validate date
 *
 * @param date
 * @return
 */
int is_valid_date(char *date)
{
    if (strlength(date) != 11)
    {
        printf("\nInproper date format! Please enter the date as 'YYYY.MM.DD.' !");
        return 0;
    }
    else
    {
        return 1;
    }
}

/**
 * isValidName
 *
 * accepted chars: a-zA-Z\s\.\-
 * @param name
 * @return
 */
int is_valid_name(char *name)
{
    if (strlength(name) > 32) {
        printf("\nLength of the given name cannot be longer than 32 charachters!\n");
        return 0;
    }

    int i;
    char actualLetter;

    for (i = 0; i <= strlength(name) - 1; i++)
    {
        actualLetter = *(name + i);

        /**
         * Take care of the capital letters!
         */
        if ((i == 0 || *(name + i - 1) == ' ') && (actualLetter < 'A' || actualLetter > 'Z')) {
            printf("\nName should start with capital letters.\n");
            return 0;
        }

        /*
         * Take care of the enabled characters.
         */
        if (
                ( (actualLetter < 'A') && !( actualLetter == '.' || actualLetter == '-' || actualLetter == ' ' ) ) ||
                (actualLetter > 'Z' && actualLetter < 'a') ||
                (actualLetter > 'z')
            )
        {
            printf("\nName should contain only '-', ' ' and '.' characters and letters!\n\n");
            return 0;
        }

    }

    return 1;
}

int is_valid_blood_type(char *bloodType)
{
    int hasError = 0;
    int bloodTypeLength = strlength(bloodType);

    // INVESTIGATE THE LENGTH OF THE DATA
    // ONLY 2 AND 3 LENGTH DATA IS ACCEPTED
    if (bloodTypeLength == 2)
    {
        // FIRST LETTER MUST BE '0', 'A' OR 'B' ELSE IT FAILS
        switch (*(bloodType))
        {
            case '0':
            case 'A':
            case 'B':
                // SECOND LETTER MUST BE '+' OR '-'
                if (!(*(bloodType + 1) == '+' || *(bloodType + 1) == '-'))
                {
                    hasError = 1;
                }
                break;
            default:
                hasError = 1;
        }
    } else if (bloodTypeLength == 3) {

        // IF DATA IS 3 CHAR LONG, THE FIRST MUST BE 'A' AND THE SECOND
        // MUST BE 'B'
        if (!(*(bloodType) == 'A' && *(bloodType + 1) == 'B'))
        {
            hasError = 1;
        }

        // THIRD CHAR MUST BE '+' OR '-'
        if (!(*(bloodType + 2) == '+' || *(bloodType + 2) == '-'))
        {
            hasError = 1;
        }
    } else {
        hasError = 1;
    }

    if (hasError == 1) {
        printf("\nInvalid blood type! Only 0+, 0-, A+, A-, B+, B-, AB+, AB- are accepted!\n");
        return 0;
    }

    return 1;
}

int is_valid_email(char *email)
{

}
