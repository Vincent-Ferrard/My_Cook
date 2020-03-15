/*
** EPITECH PROJECT, 2018
** info.c
** File description:
** info
*/

#include "main.h"

void init_game_obj(FILE *file, char *line, scene_t *scene)
{
	size_t n;

	for (int i = 0; i < scene->nb_objs; i++) {
		scene->objs[i].id = char_to_int(info2(line, 1));
		scene->objs[i].path = info2(line, 2);
		scene->objs[i].vector.x = char_to_int(info2(line, 3));
		scene->objs[i].vector.y = char_to_int(info2(line, 4));
		scene->objs[i].visible = char_to_int(info2(line, 5));
		scene->objs[i].texture = sfTexture_createFromFile(
			scene->objs[i].path, NULL);
		scene->objs[i].sprite = sfSprite_create();
		sfSprite_setTexture(
			scene->objs[i].sprite, scene->objs[i].texture, sfTrue);
		sfSprite_setPosition(
			scene->objs[i].sprite, scene->objs[i].vector);
		init_game_obj2(line, scene, i);
		getline(&line, &n, file);
	}
}

void init_game_obj2(char *line, scene_t *scene, int i)
{
	if (info2(line, 6) != NULL) {
		scene->objs[i].rec.top = char_to_int(info2(line, 6));
		scene->objs[i].rec.left = char_to_int(info2(line, 7));
		scene->objs[i].rec.width = char_to_int(info2(line, 8));
		scene->objs[i].rec.height = char_to_int(info2(line, 9));
		sfSprite_setTextureRect(
			scene->objs[i].sprite, scene->objs[i].rec);
	}
}

void init_button_full(button_t *buttons, char *line, sfVector2f size)
{
	sfTexture *texture;

	buttons->pos = malloc(sizeof(sfVector2f) * 2);
	buttons->id = char_to_int(info2(line, 1));
	buttons->path = info2(line, 2);
	buttons->pos[0].x = char_to_int(info2(line, 3));
	buttons->pos[0].y = char_to_int(info2(line, 4));
	buttons->visible = char_to_int(info2(line, 5));
	buttons->pos[1].x = buttons->pos[0].x - 15;
	buttons->pos[1].y = buttons->pos[0].y - 10;
	texture = sfTexture_createFromFile(
		buttons->path, NULL);
	buttons->rect = sfRectangleShape_create();
	sfRectangleShape_setSize(buttons->rect, size);
	sfRectangleShape_setPosition(
		buttons->rect, buttons->pos[0]);
	sfRectangleShape_setTexture(
		buttons->rect, texture, sfTrue);
}

void init_button(FILE *file, char *line, scene_t *scene)
{
	sfVector2f size = {200, 50};
	size_t n;

	for (int i = 0; i < scene->nb_buttons; i++) {
		init_button_full(&scene->buttons[i], line, size);
		scene->buttons[i].rec.top = char_to_int(info2(line, 6));
		scene->buttons[i].rec.left = char_to_int(info2(line, 7));
		scene->buttons[i].rec.width = char_to_int(info2(line, 8));
		scene->buttons[i].rec.height = char_to_int(info2(line, 9));
		sfRectangleShape_setTextureRect(
			scene->buttons[i].rect, scene->buttons[i].rec);
		getline(&line, &n, file);
	}
}

void info(scene_t *scene, int nb_scene)
{
	char *line = NULL;
	char *line2 = my_strcat("<Scene", int_to_char(nb_scene));
	FILE *file = fopen("utils/files/file1", "r");
	size_t n = 0;

	scene->objs = malloc(sizeof(game_object_t) * scene->nb_objs);
	scene->buttons = malloc(sizeof(button_t) * scene->nb_buttons);
	while (my_strncmp(line, line2) != 1)
		getline(&line, &n, file);
	getline(&line, &n, file);
	init_game_obj(file, line, scene);
	init_button(file, line, scene);
	fclose(file);
}
