/*
** EPITECH PROJECT, 2018
** init2.c
** File description:
** init2
*/

#include "main.h"

void set_recipes(recipe_t *recipe)
{
	int fd = open("utils/files/recipe", O_RDONLY);
	char *s = malloc(sizeof(char) * 4);

	set_recipes_end(recipe->recipes, s, fd);
}

void set_recipes_end(int **recipe, char *s, int fd)
{
	int j = 0;
	int k = 0;

	for (int i = 0; j < 4; i++) {
		read(fd, &s[i], 1);
		if (s[i - 1] == ' ') {
			s[i - 1] = '\0';
			recipe[j][k] = char_to_int(s);
			k++;
			i = 0;
		} else if (s[i - 1] == '\n') {
			s[i - 1] = '\0';
			recipe[j][k] = char_to_int(s);
			recipe[j][k + 1] = -1;
			j++;
			k = 0;
			i = 0;
		}
	}
}
