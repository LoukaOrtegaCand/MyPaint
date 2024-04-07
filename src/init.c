/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** init for my_paint
*/

#include "my_paint.h"
#include <stdlib.h>

static const sprite_val_t s_val[] = {
    {"assets/pencils/p_black.png", 1.5, 1730, 65, 0, 0, 26, 26, 0, 0},
    {"assets/eraser.png", 2, 1726, 118, 0, 0, 24, 24, 0, 0},
    {"assets/colors.png", 3, 1827, 120, 16, 0, 16, 16, 0, 0},
    {"assets/colors.png", 3, 1827, 180, 32, 0, 16, 16, 0, 0},
    {"assets/colors.png", 3, 1827, 240, 48, 0, 16, 16, 0, 0},
    {"assets/colors.png", 3, 1827, 300, 0, 16, 16, 16, 0, 0},
    {"assets/colors.png", 3, 1827, 360, 16, 16, 16, 16, 0, 0},
    {"assets/colors.png", 3, 1827, 420, 32, 16, 16, 16, 0, 0},
    {"assets/colors.png", 3, 1827, 480, 48, 16, 16, 16, 0, 0},
    {"assets/colors.png", 3, 1827, 540, 0, 32, 16, 16, 0, 0},
    {"assets/colors.png", 3, 1827, 600, 16, 32, 16, 16, 0, 0},
    {"assets/colors.png", 3, 1827, 660, 32, 32, 16, 16, 0, 0},
    {"assets/colors.png", 3, 1827, 720, 48, 32, 16, 16, 0, 0},
    {"assets/colors.png", 3, 1827, 780, 0, 48, 16, 16, 0, 0},
    {"assets/colors.png", 3, 1827, 840, 16, 48, 16, 16, 0, 0},
    {"assets/square.png", 1.7, 1728, 183, 0, 0, 26, 26, 0, 0},
    {"assets/circle.png", 2, 1724, 239, 0, 0, 26, 26, 0, 0},
    {"assets/tools.png", 0.78, 1850, 25, 0, 0, 64, 64, 0, 0},
    {"assets/file.png", 1, 22, 26, 0, 0, 48, 48, 0, 0},
    {"assets/plus.png", 2, 37, 108, 0, 0, 24, 24, 0, 0},
    {"assets/import.png", 1.9, 103, 40, 0, 0, 26, 26, 0, 0},
    {"assets/export.png", 1.9, 103, 107, 0, 0, 26, 26, 0, 0},
};

static const rect_val_t r_val[] = {
    {200, 900, 224, 192, 2, 1700, 25},
    {50, 50, 192, 160, 2, 1850, 25},
    {50, 50, 192, 160, 2, 1825, 120},
    {50, 50, 192, 160, 2, 1825, 180},
    {50, 50, 192, 160, 2, 1825, 240},
    {50, 50, 192, 160, 2, 1825, 300},
    {50, 50, 192, 160, 2, 1825, 360},
    {50, 50, 192, 160, 2, 1825, 420},
    {50, 50, 192, 160, 2, 1825, 480},
    {50, 50, 192, 160, 2, 1825, 540},
    {50, 50, 192, 160, 2, 1825, 600},
    {50, 50, 192, 160, 2, 1825, 660},
    {50, 50, 192, 160, 2, 1825, 720},
    {50, 50, 192, 160, 2, 1825, 780},
    {50, 50, 192, 160, 2, 1825, 840},
    {50, 50, 192, 160, 2, 1725, 60},
    {50, 50, 192, 160, 2, 1725, 120},
    {50, 50, 192, 160, 2, 1725, 180},
    {50, 50, 192, 160, 2, 1725, 240},
    {50, 50, 192, 160, 2, 1725, 300},
    {50, 50, 192, 160, 2, 1725, 360},
    {50, 50, 192, 160, 2, 1725, 420},
    {50, 50, 192, 160, 2, 1725, 480},
    {50, 50, 192, 160, 2, 1725, 540},
    {50, 50, 192, 160, 2, 1725, 600},
    {50, 50, 192, 160, 2, 1725, 660},
    {50, 50, 192, 160, 2, 1725, 720},
    {50, 50, 192, 160, 2, 20, 25},
    {50, 50, 192, 160, 2, 20, 940},
    {150, 150, 192, 160, 2, 20, 25},
    {50, 50, 192, 160, 2, 36, 107},
    {50, 50, 192, 160, 2, 103, 40},
    {50, 50, 192, 160, 2, 103, 107},
    {960, 480, 224, 192, 2, 480, 270},
};

static const text_val_t t_val[] = {
    {"?", "assets/timer.otf", 45, 34, 931, 0, 0, 1},
    {"XXS", "assets/timer.otf", 20, 1730, 310, 0, 0, 1},
    {"XS", "assets/timer.otf", 25, 1734, 366, 0, 0, 1},
    {"S", "assets/timer.otf", 30, 1740, 425, 0, 0, 1},
    {"M", "assets/timer.otf", 30, 1738, 485, 0, 0, 1},
    {"L", "assets/timer.otf", 30, 1742, 545, 0, 0, 1},
    {"XL", "assets/timer.otf", 25, 1734, 606, 0, 0, 1},
    {"XXL", "assets/timer.otf", 20, 1731, 670, 0, 0, 1},
    {"XXXL", "assets/timer.otf", 15, 1731, 734, 0, 0, 1},
    {"my_paint", "assets/timer.otf", 50, 847, 280, 0, 0, 2},
    {"a paint reproduction", "assets/timer.otf", 30, 815, 360, 0, 0, 1},
    {"using the tools on the top-right corner,", "assets/timer.otf",
        30, 675, 410, 0, 0, 1},
    {"you will be able to pick a pencil or an eraser", "assets/timer.otf",
        30, 635, 460, 0, 0, 1},
    {"and you will be able to pick a form and a size. ", "assets/timer.otf",
        30, 625, 510, 0, 0, 1},
    {"Press 'q' to leave", "assets/timer.otf", 30, 835, 575, 0, 0, 1},
    {"./my_paint -h for more help", "assets/timer.otf", 30, 750, 625, 0, 0, 1},
    {"user : ", "assets/timer.otf", 30, 870, 680, 0, 0, 1},
};

static void create_obj(my_paint_t *all, int i)
{
    all->sprite[i].sprite = SFCR;
    all->sprite[i].texture = SFCF(s_val[i].path, NULL);
    all->sprite[i].scale.x = s_val[i].size;
    all->sprite[i].scale.y = s_val[i].size;
    all->sprite[i].pos.x = s_val[i].posx;
    all->sprite[i].pos.y = s_val[i].posy;
    all->sprite[i].rect.top = s_val[i].rtop;
    all->sprite[i].rect.left = s_val[i].rleft;
    all->sprite[i].rect.width = s_val[i].rwidth;
    all->sprite[i].rect.height = s_val[i].rheight;
    all->sprite[i].ori.x = s_val[i].orix;
    all->sprite[i].ori.y = s_val[i].oriy;
}

static void create_rect(my_paint_t *all, int i)
{
    all->rect[i].rect = sfRectangleShape_create();
    all->rect[i].size.x = r_val[i].size_x;
    all->rect[i].size.y = r_val[i].size_y;
    all->rect[i].fill_color = RGB(r_val[i].fill_color);
    all->rect[i].line_color = RGB(r_val[i].line_color);
    all->rect[i].thickness = r_val[i].thickness;
    all->rect[i].pos.x = r_val[i].posx;
    all->rect[i].pos.y = r_val[i].posy;
}

static void create_text(my_paint_t *all, int i)
{
    all->txt[i].str = t_val[i].str;
    all->txt[i].font = sfFont_createFromFile(t_val[i].font);
    all->txt[i].size = t_val[i].size;
    all->txt[i].pos.x = t_val[i].posx;
    all->txt[i].pos.y = t_val[i].posy;
    all->txt[i].fcolor = RGB(t_val[i].fcolor);
    all->txt[i].ocolor = RGB(t_val[i].ocolor);
    all->txt[i].thickness = t_val[i].thickness;
}

static void apply_texts(my_paint_t *all)
{
    for (int j = 0; j < TEXT_NBR; j++) {
        all->txt[j].txt = sfText_create();
        sfText_setString(all->txt[j].txt, all->txt[j].str);
        sfText_setFont(all->txt[j].txt, all->txt[j].font);
        sfText_setCharacterSize(all->txt[j].txt, all->txt[j].size);
        sfText_setPosition(all->txt[j].txt, all->txt[j].pos);
        sfText_setFillColor(all->txt[j].txt, all->txt[j].fcolor);
        sfText_setOutlineColor(all->txt[j].txt, all->txt[j].ocolor);
        sfText_setOutlineThickness(all->txt[j].txt, all->txt[j].thickness);
    }
}

static void apply(my_paint_t *all)
{
    for (int j = 0; j < SPRITE_NBR; j++) {
        SFST(all->sprite[j].sprite, all->sprite[j].texture, sfFalse);
        sfSprite_setScale(all->sprite[j].sprite, all->sprite[j].scale);
        sfSprite_setPosition(all->sprite[j].sprite, all->sprite[j].pos);
        sfSprite_setTextureRect(all->sprite[j].sprite, all->sprite[j].rect);
    }
    for (int j = 0; j < RECT_NBR; j++) {
        sfRectangleShape_setSize(all->rect[j].rect, all->rect[j].size);
        sfRectangleShape_setPosition(all->rect[j].rect, all->rect[j].pos);
        SRFC(all->rect[j].rect, all->rect[j].fill_color);
        SROC(all->rect[j].rect, all->rect[j].line_color);
        SROT(all->rect[j].rect, all->rect[j].thickness);
    }
    apply_texts(all);
    all->layout = sfSprite_create();
}

static void link_colors(my_paint_t *all)
{
    all->color = malloc(sizeof(sfColor) * 13);
    all->color[0] = sfColor_fromRGB(228, 92, 16);
    all->color[1] = sfColor_fromRGB(0, 252, 252);
    all->color[2] = sfColor_fromRGB(247, 150, 23);
    all->color[3] = sfColor_fromRGB(88, 216, 84);
    all->color[4] = sfColor_fromRGB(248, 144, 225);
    all->color[5] = sfColor_fromRGB(116, 110, 110);
    all->color[6] = sfColor_fromRGB(176, 166, 166);
    all->color[7] = sfColor_fromRGB(0, 203, 203);
    all->color[8] = sfColor_fromRGB(170, 102, 248);
    all->color[9] = sfColor_fromRGB(0, 120, 248);
    all->color[10] = sfColor_fromRGB(139, 83, 0);
    all->color[11] = sfColor_fromRGB(218, 49, 0);
    all->color[12] = sfColor_fromRGB(0, 0, 0);
}

static void set_default(my_paint_t *all)
{
    all->tools_dropdown = false;
    all->file_dropdown = false;
    all->help_dropdown = false;
    all->pencil = BLACK;
    all->shape = SQUARE;
    all->tool = PENCIL;
    all->size = XS;
    all->drawing = false;
}

static void set_pencils_textures(my_paint_t *all)
{
    all->pencil_texture[0] = SFCF("assets/pencils/p_orange.png", NULL);
    all->pencil_texture[1] = SFCF("assets/pencils/p_light_blue.png", NULL);
    all->pencil_texture[2] = SFCF("assets/pencils/p_yellow.png", NULL);
    all->pencil_texture[3] = SFCF("assets/pencils/p_green.png", NULL);
    all->pencil_texture[4] = SFCF("assets/pencils/p_pink.png", NULL);
    all->pencil_texture[5] = SFCF("assets/pencils/p_light_grey.png", NULL);
    all->pencil_texture[6] = SFCF("assets/pencils/p_grey.png", NULL);
    all->pencil_texture[7] = SFCF("assets/pencils/p_cyan.png", NULL);
    all->pencil_texture[8] = SFCF("assets/pencils/p_purple.png", NULL);
    all->pencil_texture[9] = SFCF("assets/pencils/p_blue.png", NULL);
    all->pencil_texture[10] = SFCF("assets/pencils/p_brown.png", NULL);
    all->pencil_texture[11] = SFCF("assets/pencils/p_red.png", NULL);
    all->pencil_texture[12] = SFCF("assets/pencils/p_black.png", NULL);
}

void create_cursor(my_paint_t *all)
{
    all->crosshair.sprite = sfSprite_create();
    all->eraser.sprite = sfSprite_create();
    all->crosshair.texture = sfTexture_createFromFile(
                    "./assets/pencils/p_black.png", NULL);
    all->eraser.texture = sfTexture_createFromFile(
                    "./assets/eraser.png", NULL);
    sfSprite_setTexture(all->crosshair.sprite, all->crosshair.texture, sfTrue);
    sfSprite_setTexture(all->eraser.sprite, all->eraser.texture, sfTrue);
    sfSprite_setPosition(all->crosshair.sprite, (sfVector2f){0, 0});
    sfSprite_setPosition(all->eraser.sprite, (sfVector2f){0, 0});
    sfSprite_setOrigin(all->crosshair.sprite, (sfVector2f){0, 24});
    sfSprite_setOrigin(all->eraser.sprite, (sfVector2f){0, 24});
}

void init(my_paint_t *all)
{
    all->sprite = malloc(SPRITE_NBR * sizeof(sprite_t));
    all->rect = malloc(RECT_NBR * sizeof(rect_t));
    all->txt = malloc(TEXT_NBR * sizeof(text_t));
    all->pencil_texture = malloc(PENCIL_NBR * sizeof(sfTexture *));
    for (int i = 0; i < SPRITE_NBR; i++)
        create_obj(all, i);
    for (int i = 0; i < RECT_NBR; i++)
        create_rect(all, i);
    for (int i = 0; i < TEXT_NBR; i++)
        create_text(all, i);
    create_cursor(all);
    apply(all);
    set_default(all);
    link_colors(all);
    set_pencils_textures(all);
    all->image = sfImage_createFromColor(1920, 1080, sfWhite);
    all->texture = sfTexture_createFromImage(all->image, NULL);
    sfSprite_setTexture(all->layout, all->texture, sfTrue);
}
