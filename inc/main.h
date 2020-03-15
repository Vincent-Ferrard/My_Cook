/*
** EPITECH PROJECT, 2018
** main.h
** File description:
** main header
*/

#ifndef MAIN_H_
#define MAIN_H_

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>
#include "struct.h"
#include "clock.h"
#include "init.h"
#include "info.h"
#include "mouse.h"
#include "recipe.h"
#include "utils.h"

int button_is_clicked(button_t *, sfVector2i);
int nb_element(char *, int);
int nb_scene_element(void);
void set_recipe(recipe_t *);

void destroy_scene(scene_t *);
void destroy_all(scene_t *, screen_t *, int);

void draw_scene(screen_t *, scene_t *);
void all_principal(screen_t *, scene_t *, recipe_t *, sfVector2f);
void display_recipe(scene_t *);

char *read_only();
void write_only(char *);

#endif
