/*
** EPITECH PROJECT, 2018
** all_actions.c
** File description:
** all_actions
*/

#include "main.h"

void action(screen_t *screen, button_t *buttons, scene_t *scene, recipe_t *recipe)
{
	sfVector2f posText = {580, 620};

	if (buttons->visible != 0)
		switch (buttons->id) {
		case 0:
			sfRenderWindow_close(screen->win);
			break;
		case 1:
			change_recipe(recipe, screen);
			sfText_setString(
				screen->text[0], int_to_char(screen->score));
			break;
		case 3:
			finish_score(screen, posText);
			break;
		default:
			action2(screen, buttons, scene, recipe);
		}
}

void action2(screen_t *screen, button_t *buttons, scene_t *scene, recipe_t *recipe)
{
	switch (buttons->id) {
        case 2:
		screen->num_scene = 1;
		break;
	case 4:
		screen->num_scene = 2;
		break;
	case 5:
		valid_recipe(recipe, scene, screen);
		break;
	case 6:
		screen->num_scene = 4;
		break;
	case 7:
		display_recipe(scene);
		break;
	default:
		other_action(screen, buttons, scene, recipe);
	}
}

void other_action(screen_t *screen, button_t *buttons, scene_t *scene, recipe_t *recipe)
{
	if (screen->num_scene == 4)
		buy_recipe(buttons, scene, screen, recipe);
	else
		action_recipe(buttons, recipe, scene);
}
