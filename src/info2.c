/*
** EPITECH PROJECT, 2018
** info2.c
** File description:
** info2
*/

#include "main.h"

char *info2(char *line, int nb_info)
{
	int i;
	int j = 0;
	int check = 0;
	char *name = NULL;

	for (i = 0; line[i] && check < nb_info; i++)
		if (line[i] == '=')
			check += 1;
	if (check < nb_info)
		return (NULL);
	check = i;
	for (i = i + 1; line[i] != '\"'; i++)
		j++;
	name = malloc(sizeof(char) * (j + 1));
	j = 0;
	for (i = check + 1; line[i] != '\"'; i++) {
		name[j] = line[i];
		j++;
	}
	name[j] = '\0';
	return (name);
}
