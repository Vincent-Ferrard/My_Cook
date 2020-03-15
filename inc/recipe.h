/*
** EPITECH PROJECT, 2018
** recipe.h
** File description:
** recipe header
*/

#ifndef RECIPE_H_
#define RECIPE_H_

int check_recipe(recipe_t *);
void set_ingredient(button_t *, recipe_t *);
int unset_ingredient(button_t *, recipe_t *);
void valid_recipe(recipe_t *, scene_t *, screen_t *);
void change_score(recipe_t *, screen_t *);

void change_recipe(recipe_t *, screen_t *);
void buy_recipe(button_t *, scene_t *, screen_t *, recipe_t *);
void buy_recipe2(screen_t *, scene_t *, recipe_t *, int);
void sold_recipe(recipe_t *, scene_t *);
int count_green_objs(scene_t *);

void display_finish_recipe(recipe_t *, scene_t *, screen_t *);
void time_finish_recipe(screen_t *, scene_t *);

#endif
