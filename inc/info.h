/*
** EPITECH PROJECT, 2018
** info.h
** File description:
** info header
*/

#ifndef INFO_H_
#define INFO_H_

void info(scene_t *, int);
void init_button_full(button_t *, char *, sfVector2f);
void init_button(FILE *, char *, scene_t *);
void init_game_obj(FILE *, char *, scene_t *);
void init_game_obj2(char *, scene_t *, int);
char *info2(char *, int);

#endif
