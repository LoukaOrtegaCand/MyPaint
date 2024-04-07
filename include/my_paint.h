/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** header file for my_paint
*/

#ifndef MY_PAINT
    #define MY_PAINT

    #include "my.h"
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <errno.h>

typedef struct sprite_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
    sfVector2f pos;
    sfIntRect rect;
    sfVector2f ori;
} sprite_t;

typedef struct rect_s {
    sfRectangleShape *rect;
    sfVector2f size;
    sfColor fill_color;
    sfColor line_color;
    int thickness;
    sfVector2f pos;
} rect_t;

typedef struct text_s {
    sfText *txt;
    char *str;
    sfFont *font;
    int size;
    sfVector2f pos;
    sfColor fcolor;
    sfColor ocolor;
    int thickness;
} text_t;

typedef struct sprite_val_s {
    char *path;
    float size;
    int posx;
    int posy;
    int rleft;
    int rtop;
    int rwidth;
    int rheight;
    int orix;
    int oriy;
} sprite_val_t;

typedef struct rect_val_s {
    int size_x;
    int size_y;
    int fill_color;
    int line_color;
    int thickness;
    int posx;
    int posy;
} rect_val_t;

typedef struct text_val_s {
    char *str;
    char *font;
    int size;
    int posx;
    int posy;
    int fcolor;
    int ocolor;
    int thickness;
} text_val_t;

typedef struct crosshair_s {
    sfSprite *sprite;
    sfTexture *texture;
} crosshair_t;

enum pencils {
    ORANGE,
    LIGHT_BLUE,
    YELLOW,
    GREEN,
    PINK,
    GREY,
    LIGHT_GREY,
    CYAN,
    PURPLE,
    BLUE,
    BROWN,
    RED,
    BLACK,
};

enum shapes {
    SQUARE,
    CIRCLE,
};

enum tools {
    PENCIL,
    ERASER,
};

enum size {
    XS,
    S,
    M,
    L,
    XL,
    XXL,
    XXXL,
};

typedef struct my_paint_s {
    char *logname;
    sprite_t *sprite;
    rect_t *rect;
    text_t *txt;
    sfEvent event;
    sfVector2f ms;
    sfRenderWindow *window;
    sfImage *image;
    sfSprite *layout;
    sfTexture *texture;
    crosshair_t crosshair;
    crosshair_t eraser;
    bool drawing;
    bool tools_dropdown;
    bool file_dropdown;
    bool help_dropdown;
    sfColor *color;
    enum pencils pencil;
    enum shapes shape;
    enum tools tool;
    enum size size;
    sfTexture **pencil_texture;
} my_paint_t;

void display_dropdown_help(my_paint_t *all);
int errors(int argc, char **argv, char **envp, my_paint_t *all);
int help(char **argv);
void setwindow(my_paint_t *all);
void init(my_paint_t *all);
void draw(my_paint_t *all);
void tools_menu_events(my_paint_t *all);
void file_menu_events(my_paint_t *all);
void display_file_dropdown_menu(my_paint_t *all);
void display_tools_dropdown_menu(my_paint_t *all);

    #define SFWC sfRenderWindow_create
    #define SFCR sfSprite_create()
    #define SFCF sfTexture_createFromFile
    #define SFST sfSprite_setTexture
    #define SDRS sfRenderWindow_drawRectangleShape
    #define SFDS sfRenderWindow_drawSprite
    #define SRFC sfRectangleShape_setFillColor
    #define SROC sfRectangleShape_setOutlineColor
    #define SROT sfRectangleShape_setOutlineThickness
    #define SISP sfImage_setPixel
    #define RGB(val) sfColor_fromRGB(val, val, val)
    #define TO_DEG(x) ((x) * 180 / 3.14)
    #define SPRITE_NBR 22
    #define RECT_NBR 34
    #define TEXT_NBR 17
    #define PENCIL_NBR 13

    #define KO 84
    #define OK 0
    #define ERR -1
    #define UNUSED __attribute__((unused))

#endif
