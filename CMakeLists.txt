cmake_minimum_required(VERSION 3.12)
project(blood_donation_system C)

set(CMAKE_C_STANDARD 99)

add_executable(blood_donation_system main.c src/structs/donor.h src/createdonor.c src/createdonor.h src/initializer.c src/initializer.h src/menu.c src/menu.h src/lib/validator.c src/lib/validator.h src/lib/filehelper.c src/lib/filehelper.h src/lib/strhelper.h src/lib/strhelper.c src/listdonors.h src/listdonors.c src/search.c src/search.h)