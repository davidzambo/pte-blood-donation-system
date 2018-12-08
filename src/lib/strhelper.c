//
// Created by zdavid on 04/11/18.
//

#include <stdio.h>

/**
 * Returns the length of string
 *
 * @param str
 * @return
 */
int strlength(char *str) {
    int length = 0;
    int i = 0;

    while (*(str + i) != '\0') {
        i++;
    }
    return i;
}

/**
 * Copy a string
 *
 * @param to
 * @param from
 * @return
 */
int strcopy(char *to, char *from) {
    int i = 0;

    while(*(from + i) != '\0') {
        *(to + i) = *(from + i);
        i++;
    }

    *(to + i) = '\0';

    return 0;
}

/**
 * Convert a string array to int
 *
 * @param str
 * @return
 */
int strtoint(char *str) {
    int i;
    int result = 0;

    for (i = 0; i < strlength(str); i++) {
        /*
         * Checks, if letter is a number
         */
        if ((str[i] < '0' || str[i] > '9')) {
            printf("\nInvalid string to integer conversion!");
            return -1;
        }
        result *= 10;
        result += ((int) str[i]) - 48;
    }

    return result;
}

/**
 * Concat two strings
 *
 * @param to
 * @param str
 * @return
 */
int strconcat(char *to, char *str) {
    int i = strlength(to), j = 0;

    while (*(str + j) != '\0') {
        *(to + i + j) = *(str + j);
        j++;
    }

    *(to + i + j) = '\0';

    return 0;
}

/**
 * Compare two strings
 *
 * @param what
 * @param with
 * @return
 */
int strcompare(char *what, char *with)
{
    int i = 0;

    /*
     * If the two string is not the same length
     * it fails
     */
    if (strlength(what) != strlength(with)) {
        return 0;
    }

    /*
     * From char to char compare the whole string
     */
    for (i = 0; i < strlength(what); i++)
    {
        if (what[i] != with[i]) {
            return 0;
        }
    }

    return 1;
}
