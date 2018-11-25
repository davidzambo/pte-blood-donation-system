//
// Created by zdavid on 10/11/18.
//

#include "structs/donor.h"
#include <stdio.h>

void list_donors(DONOR donors[])
{
    printf("=================== RECORDED BLOOD DONORS ==================\n");
    printf("ID\tNAME\tBLOOD TYPE\tEMAIL\tDONATIONS\tLAST DONATION AT\n");

//    printf("\nDETAILS: #%d | name: %s | blood type: %s | email: %s | donations: %d | last: %s",
//               actual_donor->id,
//               actual_donor->name,
//               actual_donor->blood_type,
//               actual_donor->email,
//               actual_donor->blood_donations,
//               actual_donor->last_donate_at);
//    printf("donor: %s", donor[0].name);

    printf("donor: %s", *(donors + 1)->name);
}