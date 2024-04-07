/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** file menu for my_paint
*/

#include "my_paint.h"

bool file_exists(const char *path)
{
    struct stat buffer;

    if (stat(path, &buffer) == 0)
        return true;
    return false;
}

static void reset_image(my_paint_t *all)
{
    for (int y = 0; y < 1080; y++)
        for (int x = 0; x < 1920; x++)
            sfImage_setPixel(all->image, x, y, sfTransparent);
}

static void plus_file_tool(my_paint_t *all)
{
    sfFloatRect lim = sfRectangleShape_getGlobalBounds(all->rect[30].rect);

    if (sfFloatRect_contains(&lim, all->ms.x, all->ms.y)
    && all->event.type == sfEvtMouseButtonPressed) {
        reset_image(all);
        all->file_dropdown = false;
        all->drawing = false;
    }
}

static int check_ext(char *path)
{
    if (my_strendcmp(path, ".png") == 0 ||
    my_strendcmp(path, ".bmp") == 0 ||
    my_strendcmp(path, ".jpg") == 0)
        return (OK);
    return (KO);
}

static void open_file(my_paint_t *all)
{
    char *path = NULL;
    size_t len = 0;
    ssize_t read;

    my_putstr("Enter a file :\n");
    read = getline(&path, &len, stdin);
    if (read < 0)
        return;
    if (path[read - 1] == '\n')
        path[read - 1] = '\0';
    if (path == NULL || !file_exists(path) || check_ext(path) == KO)
        my_putstr("Invalid file\n");
    else {
        all->image = sfImage_createFromFile(path);
    }
}

static int import_file_tool(my_paint_t *all)
{
    sfFloatRect lim = sfRectangleShape_getGlobalBounds(all->rect[32].rect);

    if (sfFloatRect_contains(&lim, all->ms.x, all->ms.y)
    && all->event.type == sfEvtMouseButtonPressed) {
        all->file_dropdown = false;
        all->drawing = false;
        open_file(all);
    }
    return (OK);
}

static void save_file(my_paint_t *all)
{
    char *path = NULL;
    size_t len = 0;
    ssize_t read;

    my_putstr("Enter a name :\n");
    read = getline(&path, &len, stdin);
    if (read < 0)
        return;
    if (path[read - 1] == '\n')
        path[read - 1] = '\0';
    if (path == NULL || check_ext(path) == KO)
        my_putstr("Invalid name\n");
    else {
        sfImage_saveToFile(all->image, path);
    }
}

static void export_file_tool(my_paint_t *all)
{
    sfFloatRect lim = sfRectangleShape_getGlobalBounds(all->rect[31].rect);

    if (sfFloatRect_contains(&lim, all->ms.x, all->ms.y)
    && all->event.type == sfEvtMouseButtonPressed) {
        all->file_dropdown = false;
        all->drawing = false;
        save_file(all);
    }
}

void display_file_dropdown_menu(my_paint_t *all)
{
    for (int i = 29; i < 33; i++)
        SDRS(all->window, all->rect[i].rect, NULL);
    for (int i = 19; i < 22; i++)
        SFDS(all->window, all->sprite[i].sprite, NULL);
}

void file_menu_events(my_paint_t *all)
{
    sfFloatRect lim_1;
    sfFloatRect lim_2;

    plus_file_tool(all);
    import_file_tool(all);
    export_file_tool(all);
    lim_1 = sfRectangleShape_getGlobalBounds(all->rect[27].rect);
    lim_2 = sfRectangleShape_getGlobalBounds(all->rect[29].rect);
    if (all->ms.x >= lim_1.left && all->ms.x <= lim_1.left + 50 &&
        all->ms.y >= lim_1.top && all->ms.y <= lim_1.top + 50 &&
        !all->file_dropdown && all->event.type == sfEvtMouseButtonPressed) {
        all->file_dropdown = true;
        all->drawing = false;
    } else if ((all->ms.x <= lim_2.left || all->ms.x >= lim_2.left + 150
        || all->ms.y <= lim_2.top || all->ms.y >= lim_2.top + 150) ||
        (all->ms.x >= lim_1.left && all->ms.x <= lim_1.left + 50 &&
        all->ms.y >= lim_1.top && all->ms.y <= lim_1.top + 50 &&
        all->file_dropdown && all->event.type == sfEvtMouseButtonPressed)) {
        all->file_dropdown = false;
        }
}
