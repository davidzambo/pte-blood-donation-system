#include <stdio.h>
#include <stdbool.h>

typedef struct Donors
{
    unsigned int id;
    char name[64];
    char blood_type[4];
    char email[32];
    unsigned int blood_donations;
    char last_donate_at[11];
} Donor;

bool file_reader(char *FILENAME) {
    int i;
    FILE *file;
    char buff[255];
    int tmp;
    Donor donors[20];
    char data[30];
    char *actual;

    file = fopen(FILENAME, "r");

    // read every line
    while (tmp != EOF)
    {
        // read every char in line
        do
        {
            // read every char until a TAB
            i = 0; 
            do
            {
                tmp = fgetc(file);
                data[i] = tmp;
                i++;
            } while (tmp == 9);
            printf("%s", data);
            
            // TODO: SOLVE WINDOW AND MAC NEW LINE
        } while (!((tmp == 10) || (tmp == EOF)));
        printf("\nTHAT WAS A LINE\n");
        tmp = EOF;
    }
    printf("\nTHAT WAS ALL\n");

    fclose(file);
}
