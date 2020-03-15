/*
** EPITECH PROJECT, 2018
** clock.h
** File description:
** clock
*/

#ifndef CLOCK_H_
#define CLOCK_H_

void clock_time(screen_t *, scene_t *, recipe_t *);
void set_button_recipe(scene_t *, screen_t *, recipe_t *, int);
void timer(screen_t *, sfVector2f);
void set_timer(screen_t *);
void finish_score(screen_t *, sfVector2f);

#endif
