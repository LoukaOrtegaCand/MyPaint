/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** help
*/

#include "my_paint.h"

void create_logname(my_paint_t *all)
{
    sfFont *font = sfFont_createFromFile("./assets/timer.otf");
    sfText *txt = sfText_create();

    sfText_setString(txt, all->logname);
    sfText_setFont(txt, font);
    sfText_setCharacterSize(txt, 30);
    sfText_setFillColor(txt, sfBlack);
    sfText_setPosition(txt, (sfVector2f) {975, 680});
    sfText_setOutlineColor(txt, sfBlack);
    sfText_setOutlineThickness(txt, 1);
    sfRenderWindow_drawText(all->window, txt, NULL);
}

void display_dropdown_help(my_paint_t *all)
{
    SDRS(all->window, all->rect[33].rect, NULL);
    sfRenderWindow_drawText(all->window, all->txt[9].txt, NULL);
    sfRenderWindow_drawText(all->window, all->txt[10].txt, NULL);
    sfRenderWindow_drawText(all->window, all->txt[11].txt, NULL);
    sfRenderWindow_drawText(all->window, all->txt[12].txt, NULL);
    sfRenderWindow_drawText(all->window, all->txt[13].txt, NULL);
    sfRenderWindow_drawText(all->window, all->txt[14].txt, NULL);
    sfRenderWindow_drawText(all->window, all->txt[15].txt, NULL);
    sfRenderWindow_drawText(all->window, all->txt[16].txt, NULL);
    create_logname(all);
}
