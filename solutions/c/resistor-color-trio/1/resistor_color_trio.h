#ifndef RESISTOR_COLOR_TRIO_H
#define RESISTOR_COLOR_TRIO_H
typedef enum{
    BLACK,
    BROWN,
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    VIOLET,
    GREY,
    WHITE,
} resistor_band_t;

#define OHMS 1
#define KILOOHMS 3
#define MEGAOHMS 6
#define GIGAOHMS 9
typedef struct{
    int value;
    int unit;
} resistor_value_t;

resistor_value_t color_code(resistor_band_t resistor[]);

int unidades(resistor_band_t color, int *resto);
#endif
