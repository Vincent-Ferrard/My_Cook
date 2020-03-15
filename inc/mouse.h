/*
** EPITECH PROJECT, 2018
** mouse.h
** File description:
** mouse header
*/

#ifndef MOUSE_H_
#define MOUSE_H_

void mouse_button(screen_t *, scene_t *, recipe_t *);
void button_action(screen_t *, button_t *, scene_t *, recipe_t *);
void action(screen_t *, button_t *, scene_t *, recipe_t *);
void action2(screen_t *, button_t *, scene_t *, recipe_t *);
void other_action(screen_t *, button_t *, scene_t *, recipe_t *);
void action_recipe(button_t *, recipe_t *, scene_t *);
void set_pos_food(recipe_t *, scene_t *, int, int);

#endif
