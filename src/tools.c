/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** tools functs for my_paint
*/

#include "my_paint.h"

static void draw_pixel_square(my_paint_t *all, int x, int y)
{
    if (x > 0 && x < 1920 && y > 0 && y < 1080)
        switch (all->tool) {
        case PENCIL:
            sfImage_setPixel(all->image, x, y, all->color[all->pencil]);
            break;
        case ERASER:
            sfImage_setPixel(all->image, x, y, sfTransparent);
            break;
        }
}

static void draw_square(my_paint_t *all)
{
    int size = all->size * all->size + 1;

    for (int y = -size; y <= size; y++)
        for (int x = -size; x <= size; x++)
            draw_pixel_square(all, all->ms.x + x, all->ms.y + y);
}

static void draw_pixel_circle(my_paint_t *all, int x, int y, int size)
{
    if ((all->ms.x + x > 0 && all->ms.x + x < 1920 &&
        all->ms.y + y > 0 && all->ms.y + y < 1080) &&
        x * x + y * y <= size * size) {
        x += all->ms.x;
        y += all->ms.y;
        switch (all->tool) {
        case PENCIL:
            sfImage_setPixel(all->image, x, y, all->color[all->pencil]);
            break;
        case ERASER:
            sfImage_setPixel(all->image, x, y, sfTransparent);
            break;
        }
    }
}

static void draw_circle(my_paint_t *all)
{
    int size = all->size * all->size + 1;

    for (int y = -size; y <= size; y++)
        for (int x = -size; x <= size; x++)
            draw_pixel_circle(all, x, y, size);
}

void draw(my_paint_t *all)
{
    switch (all->shape) {
    case SQUARE:
        draw_square(all);
        break;
    case CIRCLE:
        draw_circle(all);
        break;
    }
    sfTexture_updateFromImage(all->texture, all->image, 0, 0);
    sfSprite_setTexture(all->layout, all->texture, sfTrue);
}
