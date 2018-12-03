//
// Created by zdavid on 02/10/18.
//

#ifndef BLOOD_DONATION_SYSTEM_FILEHELPER_H
#define BLOOD_DONATION_SYSTEM_FILEHELPER_H

#include "../structs/donor.h"

int get_record_length(char *file);

int prepare_record(char *line, DONOR *donor);

#endif //BLOOD_DONATION_SYSTEM_FILEHELPER_H
