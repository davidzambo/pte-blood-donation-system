//
// Created by zdavid on 02/10/18.
//

#ifndef BLOOD_DONATION_SYSTEM_DONOR_H
#define BLOOD_DONATION_SYSTEM_DONOR_H

typedef struct
{
    int id;
    char name[33];
    char blood_type[5];
    char email[33];
    int blood_donations;
    char last_donate_at[12];
} DONOR;

#endif //BLOOD_DONATION_SYSTEM_DONOR_H
