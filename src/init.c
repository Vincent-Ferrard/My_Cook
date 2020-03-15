/*
** EPITECH PROJECT, 2018
** init.c
** File description:
** init
*/

#include "main.h"

sfRenderWindow *init_window(char *name, int width, int height)
{
	sfRenderWindow *win;
	sfVideoMode mode = {width, height, 32};

	win = sfRenderWindow_create(
		mode, name, sfResize | sfClose, NULL);
	sfRenderWindow_setFramerateLimit(win, 60);
	return (win);
}

void init_recipes(recipe_t *recipe, int nb_buttons)
{
	recipe->recipes = malloc(sizeof(int *) * 6);
	for (int i = 0; i < 6; i++)
		recipe->recipes[i] = malloc(sizeof(int) * (nb_buttons + 1));
	recipe->choose = malloc(sizeof(int) * (nb_buttons + 1));
	set_recipes(recipe);
	recipe->choose[0] = -1;
	recipe->recipe_max = 2;
	recipe->nb_recipe = 0;
	recipe->nb_rand = 0;
}

screen_t init_screen(sfVector2f posText)
{
	screen_t screen;

	screen.win = init_window("My_Cook", 1250, 710);
	screen.num_scene = 0;
	screen.font = sfFont_createFromFile("utils/police/arial.ttf");
	screen.text = malloc(sizeof(sfText *) * 3);
	for (int i = 0; i < 3; i++) {
		screen.text[i] = sfText_create();
		sfText_setFont(screen.text[i], screen.font);
		sfText_setCharacterSize(screen.text[i], 50);
		sfText_setColor(screen.text[i], sfBlack);
	}
	screen.score = 100;
	sfText_setString(screen.text[0], read_only());
	sfText_setPosition(screen.text[0], posText);
	init_screen2(&screen);
	return (screen);
}

void init_screen2(screen_t *screen)
{
	sfVector2f posTimer = {0, 100};

	sfText_setPosition(screen->text[1], posTimer);
	posTimer.x += 25;
	sfText_setPosition(screen->text[2], posTimer);
	screen->clock = sfClock_create();
	screen->timer = sfClock_create();
	screen->minT = 2;
	screen->secT = 0;
}

void init_all_scene(scene_t *scene, int nb_scene)
{
	for (int i = 0; i < nb_scene; i++) {
		scene[i].nb_objs = nb_element("<Game_Object", i);
		scene[i].nb_buttons = nb_element("<Button", i);
		info(&scene[i], i);
	}
}
