/*
** EPITECH PROJECT, 2018
** file.c
** File description:
** file
*/

#include "main.h"

char *read_only()
{
	char *s = malloc(sizeof(char) * 10);
	int fd;
	int i = 0;

	fd = open("utils/files/score", O_RDONLY);
	while (read(fd, &s[i], 1) != 0)
		i++;
	s[i] = '\0';
	close(fd);
	return (s);
}

void write_only(char *s)
{
	int fd;

	fd = open("utils/files/score", O_WRONLY | O_TRUNC | O_CREAT);
	write(fd, s, my_strlen(s));
	close(fd);
}
