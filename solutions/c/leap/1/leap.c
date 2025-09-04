#include "leap.h"
bool leap_year(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true; // Es bisiesto
        }
    else {
        return false; // No lo es
    }
}