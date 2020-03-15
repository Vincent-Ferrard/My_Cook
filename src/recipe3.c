/*
** EPITECH PROJECT, 2018
** recipe3.c
** File description:
** recipe3
*/

#include "main.h"

void display_finish_recipe(recipe_t *recipe, scene_t *scene, screen_t *screen)
{
	int i = 0;

	if (check_recipe(recipe) == 1) {
		for (i = 0; scene->objs[i].id != 4; i++);
		scene->objs[i].visible = 1;
		for (i = 0; scene->objs[i].id != 2; i++);
		scene->objs[i].visible = 0;
		scene->objs[i + 1].visible = 0;
		time_finish_recipe(screen, scene);
		for (i = 0; scene->objs[i].id != 4; i++);
		scene->objs[i].visible = 0;
		for (i = 0; scene->objs[i].id != 2; i++);
		scene->objs[i].visible = 1;
		scene->objs[i + 1].visible = 1;
		change_score(recipe, screen);
	} else
		screen->score -= 30;
}

void time_finish_recipe(screen_t *screen, scene_t *scene)
{
	sfClock *clock = sfClock_create();
	sfTime time = sfClock_getElapsedTime(clock);
	float seconds = time.microseconds / 1000000.0;

	while (seconds < 1) {
		time = sfClock_getElapsedTime(clock);
		seconds = time.microseconds / 1000000;
		draw_scene(screen, scene);
	}
}
