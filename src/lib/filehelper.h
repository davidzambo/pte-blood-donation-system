//
// Created by zdavid on 02/10/18.
//

#ifndef BLOOD_DONATION_SYSTEM_FILEHELPER_H
#define BLOOD_DONATION_SYSTEM_FILEHELPER_H

#include "../structs/donor.h"

int get_record_length(char *filename);

Donor prepare_record(char *line);

#endif //BLOOD_DONATION_SYSTEM_FILEHELPER_H
