/*
** EPITECH PROJECT, 2018
** mouse.c
** File description:
** mouse
*/

#include "main.h"

void mouse_button(screen_t *screen, scene_t *scene, recipe_t *recipe)
{
	while (sfRenderWindow_pollEvent(screen->win, &screen->event)) {
		for (int i = 0; i < scene->nb_buttons; i++)
			button_action(
				screen, &scene->buttons[i], scene, recipe);
	}
}

void button_action(screen_t *screen, button_t *buttons, scene_t *scene, recipe_t *recipe)
{
	sfVector2f size = {200, 50};
	sfVector2f size2 = {230, 60};
	sfVector2i clickPosition = sfMouse_getPositionRenderWindow(screen->win);

	if (button_is_clicked(buttons, clickPosition)) {
		sfRectangleShape_setSize(buttons->rect, size2);
		sfRectangleShape_setPosition(
			buttons->rect, buttons->pos[1]);
		if (screen->event.type == sfEvtMouseButtonPressed)
			action(screen, buttons, scene, recipe);
	} else {
		sfRectangleShape_setSize(buttons->rect, size);
		sfRectangleShape_setPosition(
			buttons->rect, buttons->pos[0]);
	}
}

void action_recipe(button_t *buttons, recipe_t *recipe, scene_t *scene)
{
	sfColor color;
	int i;
	int count = count_green_objs(scene);

	for (i = 0; scene->objs[i].id != buttons->id; i++);
	color = sfRectangleShape_getFillColor(buttons->rect);
	if (color.g == 255 && color.r == 0 && color.b == 0) {
		if (unset_ingredient(buttons, recipe) == 1) {
			sfRectangleShape_setFillColor(buttons->rect, sfWhite);
			scene->objs[i].visible = 0;
		}
	} else {
		sfRectangleShape_setFillColor(buttons->rect, sfGreen);
		scene->objs[i].visible = 1;
		set_pos_food(recipe, scene, i, count);
		sfSprite_setPosition(
			scene->objs[i].sprite, scene->objs[i].vector);
		set_ingredient(buttons, recipe);
	}
}

void set_pos_food(recipe_t *recipe, scene_t *scene, int i, int count)
{
	if (recipe->nb_recipe < 2)
		scene->objs[i].vector.y =
			450 - 85 * count - 30 * count * recipe->nb_recipe;
	else
		scene->objs[i].vector.y =
			450 - 85 * count - 30 * count * (recipe->nb_recipe - 1);
}
