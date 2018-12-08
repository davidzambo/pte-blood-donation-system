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
int is_valid_date(char *date, int isSilent)
{
    int i = 0, c = 0, year = 0, month = 0, day = 0;
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char strBuffer[5];
    if (
            (strlength(date) != 11) ||
            !(date[0] >= '0' && date[0] <= '9') ||
            !(date[1] >= '0' && date[1] <= '9') ||
            !(date[2] >= '0' && date[2] <= '9') ||
            !(date[3] >= '0' && date[3] <= '9') ||
            !(date[5] >= '0' && date[5] <= '9') ||
            !(date[6] >= '0' && date[6] <= '9') ||
            !(date[8] >= '0' && date[8] <= '9') ||
            !(date[9] >= '0' && date[9] <= '9') ||
            (date[4] != '.') ||
            (date[7] != '.') ||
            (date[10] != '.')
        )
    {
        if (!isSilent)
        {
            printf("Inproper date format! Please enter the date as 'YYYY.MM.DD.' !\n");
        }
        return 0;
    }

    while (date[i] != '\0') {
        strBuffer[c] = date[i];

        if (date[i] == '.')
        {
            /*
             * Reset last readed character to '\0'
             */
            strBuffer[c] = '\0';
            if (i == 4) {
                year = strtoint(strBuffer);
            } else if (i == 7) {
                month = strtoint(strBuffer);
            } else {
                day = strtoint(strBuffer);
            }
            /*
             * -1, to let it increment in the end of the loop,
             * so it will be 0 to the next round
             *
             */
            c = -1;
        }
        c++;
        i++;
    }

    daysInMonth[1] += is_leap_year(year);

    if (month < 1 || month > 12) {
        if (!isSilent)
        {
            printf("Invalid date! A year has only 12 months! %d\n", month);
        }
        return 0;
    }

    if (daysInMonth[month-1] < day)
    {
        if (!isSilent)
        {
            printf("Invalid date! %d. month has only %d days!\n", month, daysInMonth[month-1]);
        }
        return 0;
    }

    return 1;
}

/**
 * Validate given name
 *
 * accepted chars: a-zA-Z\s\.\-
 * @param name
 * @return
 */
int is_valid_name(char *name)
{
    if (strlength(name) > 32) {
        printf("Length of the given name cannot be longer than 32 charachters!\n");
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
            printf("Name should start with capital letters.\n");
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
            printf("Name should contain only '-', ' ' and '.' characters and letters!\n");
            return 0;
        }

    }

    return 1;
}

/**
 * Validate the blood type
 *
 * @param bloodType
 * @return
 */
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
        printf("Invalid blood type! Only 0+, 0-, A+, A-, B+, B-, AB+, AB- are accepted!\n");
        return 0;
    }

    return 1;
}

/**
 * Validate an email address
 *
 * IMPORTANT!!!
 * This validator uses just a few of the real world email validation rules.
 * DO NOT USE IT IN PRODUCTION!!!
 *
 * @param email
 * @return
 */
int is_valid_email(char *email, int isSilent)
{
    int i, hasAt = 0, hasDot = 0, needLetterBeforeDot = 0;
    int length = strlength(email);

    /*
     * Check the length of the given string
     * min length: a@b.eu\0
     * max length: we store email addresses as 33 byte long chars
     */
    if (length < 7 || length > 33) {
        if (!isSilent)
        {
            printf("Invalid email address! Email address should be longer then 5 characters,\n"
                   "and should not be longer then 32 characters!\n");
        }
        return 0;
    }

    /**
     * Must start with letter
     */
    if ((*email < 'A') ||  (*email > 'Z' && *email < 'a') || (*email > 'z') )
    {
        if (!isSilent)
        {
            printf("Invalid email address! Email address should start with letter!\n");
        }
        return 0;
    }

    for (i = 0; i < length; i++)
    {
        /*
         * Check accepted characters
         */
        if ((*(email + i) < '0') && !( *(email + i) == '.' || *(email + i) == '-' ))
        {
            if (!isSilent)
            {
                printf("Invalid charachter in email address: %c!\n"
                       "Email address should contain only '-', '_', '@', '.' characters, letters and numbers!\n", email[i]);
            }
            return 0;
        }

        if ((*(email + i) > '9' && *(email + i) < '@'))
        {
            if (!isSilent)
            {
                printf("Invalid charachter in email address: %c!\n"
                       "Email address should contain only '-', '_', '@', '.' characters, letters and numbers!\n", email[i]);
            }
            return 0;
        }

        if ((*(email + i) > 'Z' && *(email + i) < 'a') && *(email + i) != '_' )
        {
            if (!isSilent)
            {
                printf("Invalid charachter in email address: %c!\n"
                       "Email address should contain only '-', '_', '@', '.' characters, letters and numbers!\n", email[i]);
            }
            return 0;
        }

        if ((*(email + i) < '0') && !( *(email + i) == '.' || *(email + i) == '-' ))
        {
            if (!isSilent)
            {
                printf("Invalid charachter in email address: %c!\n"
                       "Email address should contain only '-', '_', '@', '.' characters, letters and numbers!\n", email[i]);

            }
            return 0;
        }

        /*
         * check if email address has a @ in it
         */
        if (*(email + i) == '@')
        {
            hasAt = 1;
        }

        /*
         * check if email address has a '.' in it,
         * but at least one '.' should be there after
         * the '@' to determine the host
         */
        if (*(email + i) == '.')
        {
            /*
             * Take care, that after the '@' and before '.' there sould be a letter
             */
            hasDot = 1;
            if (*(email + i - 1) < 'a' || *(email + i - 1) > 'z') {
                needLetterBeforeDot = 1;
            }
        }
    }

    /*
     * Error reporting
     */
    if (hasAt == 0) {
        if (!isSilent)
        {
            printf("Invalid email address! Email address should contains '@'!\n");
        }
        return 0;
    }

    if (hasDot == 0) {
        if (!isSilent)
        {
            printf("Invalid email address! Email address should contains at least one '.'\n"
                   "after '@'!\n");
        }
        return 0;
    }

    if (needLetterBeforeDot == 1) {
        if (!isSilent)
        {
            printf("Invalid email address! Email address should contains at least one letter before '.' and after '@'!\n");
        }
        return 0;
    }

    /*
     * Email should end with a letter
     */
    if ((*(email + i - 1) < 'A') ||  (*(email + i - 1) > 'Z' && *(email + i - 1) < 'a') || (*(email + i - 1) > 'z') )
    {
        if (!isSilent)
        {
            printf("Invalid email address! Email address should end with letter!\n");
        }
        return 0;
    }

    return 1;
}

/**
 * Validate the given blood donation data
 *
 * @param donations
 * @return
 */
int is_valid_blood_donation(char *donations)
{
    int number = strtoint(donations);

    /*
     * Check str to int conversion
     */
    if (number == -1)
    {
        printf("Invalid blood donation! Please enter a number!\n");
        return 0;
    }

    if (number > 100)
    {
        printf("More than 100 blood donations seem unrealistic! Please enter a number!\n");
        return 0;
    }

    return 1;
}

/**
 * Validate leap years
 *
 * @param year
 * @return
 */
int is_leap_year(int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                return 1;
            }

            return 0;
        }

        return 1;
    }

    return 0;
}