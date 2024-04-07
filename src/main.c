/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** main file for my_paint
*/

#include "my_paint.h"

void destroy_all(my_paint_t *all)
{
    for (size_t i = 0; i < SPRITE_NBR; i++) {
        sfSprite_destroy(all->sprite[i].sprite);
        sfTexture_destroy(all->sprite[i].texture);
    }
    for (size_t i = 0; i < RECT_NBR; i++)
        sfRectangleShape_destroy(all->rect[i].rect);
    for (size_t i = 0; i < TEXT_NBR; i++) {
        sfText_destroy(all->txt[i].txt);
        sfFont_destroy(all->txt[i].font);
    }
    sfSprite_destroy(all->crosshair.sprite);
    sfSprite_destroy(all->eraser.sprite);
    sfTexture_destroy(all->crosshair.texture);
    sfTexture_destroy(all->eraser.texture);
    sfRenderWindow_destroy(all->window);
    sfImage_destroy(all->image);
}

void free_all(my_paint_t *all)
{
    free(all->color);
    free(all->sprite);
    free(all->rect);
    free(all->txt);
    free(all->pencil_texture);
}

void wash(my_paint_t *all)
{
    destroy_all(all);
    free_all(all);
}

int main(int argc, char **argv, char **envp)
{
    my_paint_t all;
    sfVideoMode video_mode = {1920, 1080, 32};

    if (argv == NULL || envp == NULL)
        return KO;
    if (errors(argc, argv, envp, &all) == KO)
        return (KO);
    if (help(argv) == ERR)
        return (OK);
    init(&all);
    all.window = SFWC(video_mode, "MyPaint", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(all.window, 200);
    setwindow(&all);
    wash(&all);
    return (OK);
}
