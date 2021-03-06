//
// Created by zdavid on 02/10/18.
//

#ifndef BLOOD_DONATION_SYSTEM_DATEVALIDATOR_H
#define BLOOD_DONATION_SYSTEM_DATEVALIDATOR_H

int is_valid_date(char *date, int isSilent);

int is_valid_name(char *name);

int is_valid_blood_type(char *bloodType);

int is_valid_email(char *email, int isSilent);

int is_valid_blood_donation(char *donations);

int is_leap_year(int year);

#endif //BLOOD_DONATION_SYSTEM_DATEVALIDATOR_H
