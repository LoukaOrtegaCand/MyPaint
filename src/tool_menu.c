/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** tools menu for my_paint
*/

#include "my_paint.h"

static void colors_selection(my_paint_t *all)
{
    sfFloatRect lim;

    for (int i = 2; i < 15; i++) {
        lim = sfRectangleShape_getGlobalBounds(all->rect[i].rect);
        if (sfFloatRect_contains(&lim, all->ms.x, all->ms.y)
        && all->tools_dropdown && all->event.type == sfEvtMouseButtonPressed)
            all->pencil = i - 2;
    }
}

static void tools_selection(my_paint_t *all)
{
    sfFloatRect lim;

    for (int i = 15; i < 17; i++) {
        lim = sfRectangleShape_getGlobalBounds(all->rect[i].rect);
        if (sfFloatRect_contains(&lim, all->ms.x, all->ms.y)
        && all->tools_dropdown && all->event.type == sfEvtMouseButtonPressed)
            all->tool = i - 15;
    }
}

static void shapes_selection(my_paint_t *all)
{
    sfFloatRect lim;

    for (int i = 17; i < 19; i++) {
        lim = sfRectangleShape_getGlobalBounds(all->rect[i].rect);
        if (sfFloatRect_contains(&lim, all->ms.x, all->ms.y)
        && all->tools_dropdown && all->event.type == sfEvtMouseButtonPressed)
            all->shape = i - 17;
    }
}

static void sizes_selection(my_paint_t *all)
{
    sfFloatRect lim;

    for (int i = 19; i < 27; i++) {
        lim = sfRectangleShape_getGlobalBounds(all->rect[i].rect);
        if (sfFloatRect_contains(&lim, all->ms.x, all->ms.y)
        && all->tools_dropdown && all->event.type == sfEvtMouseButtonPressed)
            all->size = i - 19;
    }
}

void tools_menu_events(my_paint_t *all)
{
    sfFloatRect lim_1;
    sfFloatRect lim_2;

    colors_selection(all);
    tools_selection(all);
    shapes_selection(all);
    sizes_selection(all);
    lim_1 = sfRectangleShape_getGlobalBounds(all->rect[1].rect);
    lim_2 = sfRectangleShape_getGlobalBounds(all->rect[0].rect);
    if (sfFloatRect_contains(&lim_1, all->ms.x, all->ms.y) &&
        !all->tools_dropdown && all->event.type == sfEvtMouseButtonPressed) {
        all->tools_dropdown = true;
        all->drawing = false;
    } else if (!sfFloatRect_contains(&lim_2, all->ms.x, all->ms.y) ||
        (sfFloatRect_contains(&lim_1, all->ms.x, all->ms.y) &&
        all->tools_dropdown && all->event.type == sfEvtMouseButtonPressed)) {
        all->tools_dropdown = false;
    }
}

void display_tools_dropdown_menu(my_paint_t *all)
{
    SDRS(all->window, all->rect[0].rect, NULL);
    SDRS(all->window, all->rect[all->pencil + 2].rect, NULL);
    SDRS(all->window, all->rect[all->tool + 15].rect, NULL);
    SDRS(all->window, all->rect[all->shape + 17].rect, NULL);
    SDRS(all->window, all->rect[all->size + 19].rect, NULL);
    for (int i = 0; i < 17; i++)
        SFDS(all->window, all->sprite[i].sprite, NULL);
    for (int i = 1; i < 9; i++)
        sfRenderWindow_drawText(all->window, all->txt[i].txt, NULL);
}
