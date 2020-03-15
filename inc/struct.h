/*
** EPITECH PROJECT, 2018
** struct.h
** File description:
** struct header
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <SFML/Graphics.h>

typedef struct game_object_s {
	sfTexture *texture;
	sfSprite *sprite;
	sfIntRect rec;
	sfVector2f vector;
	char *path;
	int id;
	int visible;
} game_object_t;

typedef struct button_s {
	sfRectangleShape *rect;
	sfIntRect rec;
	sfVector2f *pos;
	char *path;
	int id;
	int visible;
} button_t;

typedef struct scene_s {
	game_object_t *objs;
	button_t *buttons;
	int nb_objs;
	int nb_buttons;
} scene_t;

typedef struct screen_s {
	sfRenderWindow *win;
	sfEvent event;
	sfText **text;
	sfFont *font;
	sfClock *clock;
	sfClock *timer;
	int num_scene;
	int score;
	int minT;
	int secT;
} screen_t;

typedef struct recipe_s {
	int **recipes;
	int *choose;
	int nb_recipe;
	int recipe_max;
	int nb_rand;
} recipe_t;

#endif
