/*
** EPITECH PROJECT, 2018
** utils.c
** File description:
** utils
*/

#include "utils.h"

int my_strlen(char *s)
{
	int i;

	if (s == NULL)
		return (0);
	for (i = 0; s[i]; i++);
	return (i);
}

int my_strncmp(char *s1, char *s2)
{
	int i = 0;
	int j = 0;

	if (s1 == NULL || s2 == NULL)
		return (0);
	while (s1[i] == ' ')
		i++;
	for (j = 0; s2[j]; j++) {
		if (s1[i] != s2[j])
			return (0);
		i++;
	}
	return (1);
}

char *my_strcat(char *s1, char *s2)
{
	int i;
	int j;
	int len1 = my_strlen(s1);
	int len2 = my_strlen(s2);
	char *dest = malloc(sizeof(char) * (len1 + len2 + 1));

	for (i = 0; s1[i]; i++)
		dest[i] = s1[i];
	for (j = 0; s2[j]; j++) {
		dest[i] = s2[j];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
