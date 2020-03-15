/*
** EPITECH PROJECT, 2018
** utils2.c
** File description:
** utils2
*/

#include "utils.h"

int my_strcmp(char *s1, char *s2)
{
	int i;
	int len1;
	int len2;

	if (s1 == NULL || s2 == NULL)
		return (0);
	len1 = my_strlen(s1);
	len2 = my_strlen(s2);
	if (len1 != len2)
		return (0);
	for (i = 0; s1[i]; i++)
		if (s1[i] != s2[i])
			return (0);
	return (1);
}

int nb_args(char *str)
{
	int nbr_args = 1;

	for (int i = 0; str[i]; i++)
		if (str[i] == ' ')
			nbr_args++;
	return (nbr_args);
}

char **my_str_to_word_array(char *str)
{
	int nbr_args = nb_args(str);
	char **interact = malloc(sizeof(char *) * (nbr_args + 1));
	int i;
	int j = 0;
	int k = 0;

	for (i = 0; i < nbr_args + 1; i++)
		interact[i] = malloc(sizeof(char) * (my_strlen(str) + 1));
	for (i = 0; str[i]; i++) {
		if (str[i] == ' ' || str[i] == '\n') {
			interact[j][k] = '\0';
			j++;
			k = 0;
		} else {
			interact[j][k] = str[i];
			k++;
		}
	}
	interact[j + 1] = NULL;
	return (interact);
}
