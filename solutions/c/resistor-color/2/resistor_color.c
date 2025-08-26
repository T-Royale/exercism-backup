#include "resistor_color.h"

resistor_band_t color_code(resistor_band_t color) {
    return color;
}
const resistor_band_t *colors() {
    static resistor_band_t color_sequence[] = {
        BLACK, BROWN, RED, ORANGE, YELLOW,
        GREEN, BLUE, VIOLET, GREY, WHITE
    };
    return color_sequence;
}