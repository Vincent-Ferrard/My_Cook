/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "main.h"
#include "init.h"

int button_is_clicked(button_t *button, sfVector2i clickPos)
{
	return (clickPos.x < sfRectangleShape_getPosition(button->rect).x +
		sfRectangleShape_getSize(button->rect).x &&
		clickPos.x > sfRectangleShape_getPosition(button->rect).x &&
		clickPos.y < sfRectangleShape_getPosition(button->rect).y +
		sfRectangleShape_getSize(button->rect).y &&
		clickPos.y > sfRectangleShape_getPosition(button->rect).y);
}

int nb_element(char *s, int nb_scene)
{
	FILE *file = fopen("utils/files/file1", "r");
	int nb_elem = 0;
	char *line = NULL;
	char *s2 = my_strcat("<Scene", int_to_char(nb_scene));
	size_t n;

	while (my_strncmp(line, s2) != 1)
		getline(&line, &n, file);
	while (my_strncmp(line, s) != 1)
		getline(&line, &n, file);
	while (my_strncmp(line, s) == 1) {
		getline(&line, &n, file);
		nb_elem++;
	}
	fclose(file);
	return (nb_elem);
}

int nb_scene_element(void)
{
	FILE *file = fopen("utils/files/file1", "r");
	int nb_scene = 0;
	char *line = NULL;
	size_t n;

	while (getline(&line, &n, file) != -1)
		if (my_strncmp(line, "<Scene") == 1)
			nb_scene += 1;
	return (nb_scene);
}

int main()
{
	scene_t *scene;
	screen_t screen;
	recipe_t recipe;
	int nb_scene = nb_scene_element();
	sfVector2f posText = {580, 620};
	sfMusic *music = sfMusic_createFromFile(
		"utils/music/Bossfight_-_The_Maze_Of_Mayonnaise.ogg");

	screen = init_screen(posText);
	scene = malloc(sizeof(scene_t) * nb_scene);
	init_recipes(&recipe, scene[2].nb_buttons);
	init_all_scene(scene, nb_scene);
	sfMusic_play(music);
	sfMusic_setLoop(music, 1);
	while (sfRenderWindow_isOpen(screen.win))
		all_principal(&screen, scene, &recipe, posText);
	sfMusic_destroy(music);
	destroy_all(scene, &screen, nb_scene);
	return (0);
}
