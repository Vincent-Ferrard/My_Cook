/*
** EPITECH PROJECT, 2018
** destroy.c
** File description:
** destroy
*/

#include "main.h"

void destroy_scene(scene_t *scene)
{
	int i;

	for (i = 0; i < scene->nb_objs; i++) {
		sfSprite_destroy(scene->objs[i].sprite);
		sfTexture_destroy(scene->objs[i].texture);
	}
	for (i = 0; i < scene->nb_buttons; i++)
		sfRectangleShape_destroy(scene->buttons[i].rect);
}

void destroy_all(scene_t *scene, screen_t *screen, int nb_scene)
{
	int i;

	for (i = 0; i < nb_scene; i++)
		destroy_scene(&scene[i]);
	for (i = 0; i < 3; i++)
		sfText_destroy(screen->text[i]);
	sfClock_destroy(screen->clock);
	sfClock_destroy(screen->timer);
	sfRenderWindow_destroy(screen->win);
}
