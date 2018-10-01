#include <stdio.h>
#include "donor.h"

int create_new_donor()
{
    Donor donor;

    printf("\nRegister a new donor: \n");
    printf("====================\n");
    printf("Name: ");
    scanf("%s", &donor.name);
    printf("Blood group: ");
    scanf("%s", &donor.blood_type);
    printf("Email: ");
    scanf("%s", &donor.email);
    printf("Blood donations before: ");
    scanf("%i", &donor.blood_donations);
    printf("Date of last donation: ");
    scanf("%s", &donor.last_donate_at);

    printf("data: %s, %s, %s, %i, %s/n", donor.name, donor.blood_type, donor.email, donor.blood_donations,
           donor.last_donate_at);
    return 0;
}