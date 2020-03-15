/*
** EPITECH PROJECT, 2018
** display.c
** File description:
** display
*/

#include "main.h"

void draw_scene(screen_t *screen, scene_t *scene)
{
	int i;

	sfRenderWindow_clear(screen->win, sfBlack);
	for (i = 0; i < scene->nb_objs; i++) {
		if (scene->objs[i].visible == 1)
			sfRenderWindow_drawSprite(
				screen->win, scene->objs[i].sprite, NULL);
	}
	for (i = 0; i < scene->nb_buttons; i++) {
		if (scene->buttons[i].visible == 1)
			sfRenderWindow_drawRectangleShape(
				screen->win, scene->buttons[i].rect, NULL);
	}
	if (screen->num_scene > 3)
		for (i = 0; i < 3; i++)
			sfRenderWindow_drawText(
				screen->win, screen->text[i], NULL);
	else if (screen->num_scene == 0 || screen->num_scene == 3)
		sfRenderWindow_drawText(screen->win, screen->text[0], NULL);
	sfRenderWindow_display(screen->win);
}

void all_principal(screen_t *screen, scene_t *scene, recipe_t *recipe, sfVector2f posText)
{
	if (screen->num_scene > 4) {
		clock_time(screen, &scene[screen->num_scene], recipe);
		timer(screen, posText);
		recipe->nb_rand++;
		if (recipe->nb_rand >= 2147483647)
			recipe->nb_rand = 0;
	} else if (screen->num_scene == 0)
		sold_recipe(recipe, &scene[3]);
	if (screen->score == 0) {
		screen->num_scene = 3;
		sfText_setPosition(screen->text[0], posText);
	}
	mouse_button(screen, &scene[screen->num_scene], recipe);
	draw_scene(screen, &scene[screen->num_scene]);
}

void display_recipe(scene_t *scene)
{
	int i = 0;

	for (i = 0; i < scene->nb_objs; i++)
		if (scene->objs[i].id >= 1 && scene->objs[i].id <= 3) {
			if (scene->objs[i].visible == 0)
				scene->objs[i].visible = 1;
			else
				scene->objs[i].visible = 0;
		}
	for (i = 0; scene->buttons[i].id > 100; i++) {
		if (scene->buttons[i].visible == 0)
			scene->buttons[i].visible = 1;
		else
			scene->buttons[i].visible = 0;
	}
	for (i = 0; scene->buttons[i].id != 5; i++);
	if (scene->buttons[i].visible == 0)
		scene->buttons[i].visible = 1;
	else
		scene->buttons[i].visible = 0;
}
