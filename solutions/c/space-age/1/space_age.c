#include "space_age.h"
float age(planet_t planet, int64_t seconds){
    float earthage = seconds/31557600;
    //seconds to earth years
    float planetage = earthage;
    switch(planet){
        case MERCURY:
            planetage /= 0.2408467;
            break;
        case VENUS:
            planetage /= 0.61519726;
            break;
        case EARTH:
            break;
        case MARS:
            planetage /= 1.8808158;
            break;
        case JUPITER:
            planetage /= 11.862615;
            break;
        case SATURN:
            planetage /= 29.447498;
            break;
        case URANUS:
            planetage /= 84.016846;
            break;
        case NEPTUNE:
            planetage /= 164.79132;
            break;
        default:
            return -1;
            break;
    }
    return planetage;
}