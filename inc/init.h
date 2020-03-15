/*
** EPITECH PROJECT, 2018
** init.h
** File description:
** init header
*/

#ifndef INIT_H_
#define INIT_H_

#include "struct.h"

sfRenderWindow *init_window(char *, int, int);
void init_recipes(recipe_t *, int);
screen_t init_screen(sfVector2f);
void init_screen2(screen_t *);
void init_all_scene(scene_t *, int);

void set_recipes(recipe_t *);
void set_recipes_end(int **, char *, int);

#endif
