/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** display screen for my_paint
*/

#include "my_paint.h"

static void button_states(my_paint_t *all, int i)
{
    sfFloatRect lim;

    lim = sfRectangleShape_getGlobalBounds(all->rect[i].rect);
    if (sfFloatRect_contains(&lim, all->ms.x, all->ms.y) &&
    all->event.type != sfEvtMouseButtonPressed) {
        SROC(all->rect[i].rect, RGB(140));
        SRFC(all->rect[i].rect, RGB(172));
    } else if (sfFloatRect_contains(&lim, all->ms.x, all->ms.y) &&
    all->event.type == sfEvtMouseButtonPressed){
        SROC(all->rect[i].rect, RGB(80));
        SRFC(all->rect[i].rect, RGB(112));
    } else {
        SROC(all->rect[i].rect, RGB(160));
        SRFC(all->rect[i].rect, RGB(192));
    }
}

void display_cursor(my_paint_t *all)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(all->window);

    sfRenderWindow_setMouseCursorVisible(all->window, 0);
    sfMouse_getPositionRenderWindow(all->window);
    if (all->tool == PENCIL) {
        sfSprite_setPosition(all->crosshair.sprite,
        (sfVector2f){mouse.x, mouse.y});
        sfRenderWindow_drawSprite(all->window, all->crosshair.sprite, NULL);
    } else if (all->tool == ERASER) {
        sfSprite_setPosition(all->eraser.sprite,
        (sfVector2f){mouse.x, mouse.y});
        sfRenderWindow_drawSprite(all->window, all->eraser.sprite, NULL);
    }
}

static void help_events(my_paint_t *all)
{
    sfFloatRect lim;

    lim = sfRectangleShape_getGlobalBounds(all->rect[28].rect);
    if (all->ms.x >= lim.left && all->ms.x <= lim.left + 50 &&
        all->ms.y >= lim.top && all->ms.y <= lim.top + 50 &&
        !all->help_dropdown && all->event.type == sfEvtMouseButtonPressed) {
        all->help_dropdown = true;
    } else if ((all->ms.x >= lim.left && all->ms.x <= lim.left + 50 &&
        all->ms.y >= lim.top && all->ms.y <= lim.top + 50 &&
        all->help_dropdown && all->event.type == sfEvtMouseButtonPressed))
        all->help_dropdown = false;
}

static void manage_pressed(my_paint_t *all)
{
    if (all->tools_dropdown) {
        SROC(all->rect[1].rect, RGB(120));
        SRFC(all->rect[1].rect, RGB(152));
    }
    if (all->file_dropdown) {
        SROC(all->rect[27].rect, RGB(120));
        SRFC(all->rect[27].rect, RGB(152));
    }
    if (all->help_dropdown) {
        SROC(all->rect[28].rect, RGB(120));
        SRFC(all->rect[28].rect, RGB(152));
    }
}

static void analyse_events(my_paint_t *all)
{
    button_states(all, 1);
    button_states(all, 27);
    button_states(all, 28);
    manage_pressed(all);
    if (!all->tools_dropdown && !all->file_dropdown && !all->help_dropdown &&
    all->event.type == sfEvtMouseButtonPressed)
        all->drawing = true;
    if (all->event.type == sfEvtMouseButtonReleased)
        all->drawing = false;
    tools_menu_events(all);
    file_menu_events(all);
    help_events(all);
    if (all->event.type == sfEvtClosed || all->event.key.code == sfKeyQ)
        sfRenderWindow_close(all->window);
}

static void drawscreen(my_paint_t *all)
{
    SFDS(all->window, all->layout, NULL);
    if (all->tools_dropdown)
        display_tools_dropdown_menu(all);
    if (all->file_dropdown)
        display_file_dropdown_menu(all);
    if (all->help_dropdown)
        display_dropdown_help(all);
    SDRS(all->window, all->rect[1].rect, NULL);
    SDRS(all->window, all->rect[27].rect, NULL);
    SDRS(all->window, all->rect[28].rect, NULL);
    SFDS(all->window, all->sprite[17].sprite, NULL);
    SFDS(all->window, all->sprite[18].sprite, NULL);
    sfRenderWindow_drawText(all->window, all->txt[0].txt, NULL);
    display_cursor(all);
}

void setwindow(my_paint_t *all)
{
    if (all == NULL)
        return;
    while (sfRenderWindow_isOpen(all->window)) {
        all->ms = sfRenderWindow_mapPixelToCoords(all->window,
        sfMouse_getPositionRenderWindow(all->window),
        sfRenderWindow_getView(all->window));
        while (sfRenderWindow_pollEvent(all->window, &all->event))
            analyse_events(all);
        if (all->drawing)
            draw(all);
        sfRenderWindow_clear(all->window, sfWhite);
        drawscreen(all);
        sfRenderWindow_display(all->window);
        SFST(all->sprite[0].sprite, all->pencil_texture[all->pencil], sfFalse);
        SFST(all->crosshair.sprite, all->pencil_texture[all->pencil], sfFalse);
    }
}
