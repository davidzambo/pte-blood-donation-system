//
// Created by zdavid on 04/11/18.
//

/**
 * Returns the length of string
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
    *(from + i -1) = '\0';
    return 0;
}
