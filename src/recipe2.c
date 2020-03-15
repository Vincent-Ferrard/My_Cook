/*
** EPITECH PROJECT, 2018
** recipe2.c
** File description:
** recipe2
*/

#include "main.h"

void change_score(recipe_t *recipe, screen_t *screen)
{
	if (recipe->nb_recipe == 0 || recipe->nb_recipe == 1)
		screen->score += 30;
	else if (recipe->nb_recipe == 2)
		screen->score += 50;
	else if (recipe->nb_recipe == 3)
		screen->score += 70;
}

void buy_recipe(button_t *buttons, scene_t *scene, screen_t *screen, recipe_t *recipe)
{
	int i;

	for (i = 0; scene->buttons[i].id != buttons->id; i++);
	if (screen->score >= 100 * (i + 1)) {
		if (scene->nb_buttons - 1 == i + 1) {
			buttons->visible = 0;
			scene->objs[i + 1].visible = 0;
			screen->score -= 100 * (i + 1);
			recipe->recipe_max += 1;
		} else
			if (screen->score >= 100 * (i + 1)) {
				buttons->visible = 0;
				buy_recipe2(screen, scene, recipe, i);
			}
	}
	if (screen->score < 0)
		screen->score = 0;
	sfText_setString(screen->text[0], int_to_char(screen->score));
}

void buy_recipe2(screen_t *screen, scene_t *scene, recipe_t *recipe, int i)
{
	scene->buttons[i + 1].visible = 1;
	scene->objs[i + 1].visible = 0;
	scene->objs[i + 2].visible = 1;
	screen->score -= 100 * (i + 1);
	recipe->recipe_max += 1;
}

void sold_recipe(recipe_t *recipe, scene_t *scene)
{
	int i;

	scene->buttons[0].visible = 1;
	scene->objs[1].visible = 1;
	for (i = 1; i < scene->nb_buttons - 1; i++) {
		scene->buttons[i].visible = 0;
		scene->objs[i + 1].visible = 0;
	}
	recipe->recipe_max = 2;
}

int count_green_objs(scene_t *scene)
{
	sfColor color;
	int count = 0;

	for (int j = 0; j < scene->nb_buttons; j++) {
		color = sfRectangleShape_getFillColor(scene->buttons[j].rect);
		if (color.g == 255 && color.r == 0 && color.b == 0)
			count++;
	}
	return (count);
}
