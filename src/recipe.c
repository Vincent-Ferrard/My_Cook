/*
** EPITECH PROJECT, 2018
** recipe.c
** File description:
** recipe
*/

#include "main.h"

int check_recipe(recipe_t *recipe)
{
	int i;
	int j;

	for (i = 0; recipe->choose[i] != -1; i++);
	for (j = 0; recipe->recipes[recipe->nb_recipe][j] != -1; j++);
	if (i != j)
		return (0);
	for (i = 0; recipe->choose[i] != -1; i++)
		if (recipe->choose[i] != recipe->recipes[recipe->nb_recipe][i])
			return (0);
	return (1);
}

void set_ingredient(button_t *buttons, recipe_t *recipe)
{
	int j;

	for (j = 0; recipe->choose[j] != -1; j++);
	recipe->choose[j] = buttons->id;
	recipe->choose[j + 1] = -1;
}

int unset_ingredient(button_t *buttons, recipe_t *recipe)
{
	int j;

	for (j = 0; recipe->choose[j] != -1; j++);
	if (j > 0) {
		if (recipe->choose[j - 1] == buttons->id) {
			recipe->choose[j - 1] = -1;
			return (1);
		}
	}
	return (0);
}

void valid_recipe(recipe_t *recipe, scene_t *scene, screen_t *screen)
{
	int i;

	for (i = 0; scene->buttons[i].id != 7; i++);
	scene->buttons[i].pos[0].x = 0;
	scene->buttons[i].pos[1].x = -15;
	scene->objs[3].vector.x = 40;
	for (i = 0; i < scene->nb_buttons; i++)
		sfRectangleShape_setFillColor(scene->buttons[i].rect, sfWhite);
	for (i = 0; i < scene->nb_objs; i++)
		if (scene->objs[i].id < 106 && scene->objs[i].id > 100)
			scene->objs[i].visible = 0;
	display_finish_recipe(recipe, scene, screen);
	if (screen->score < 0)
		screen->score = 0;
	sfText_setString(screen->text[0], int_to_char(screen->score));
	recipe->nb_recipe = recipe->nb_rand % recipe->recipe_max;
	change_recipe(recipe, screen);
	for (i = 0; recipe->choose[i] != -1; i++)
		recipe->choose[i] = -1;
	display_recipe(scene);
}

void change_recipe(recipe_t *recipe, screen_t *screen)
{
	sfVector2f posText = {0, 0};

	sfText_setPosition(screen->text[0], posText);
	switch (recipe->nb_recipe) {
	case 0:
		screen->num_scene = 5;
		break;
	case 1:
		screen->num_scene = 6;
		break;
	case 2:
		screen->num_scene = 7;
		break;
	case 3:
		screen->num_scene = 8;
		break;
	}
}
