/*
** EPITECH PROJECT, 2018
** clock.c
** File description:
** clock
*/

#include "main.h"

void clock_time(screen_t *screen, scene_t *scene, recipe_t *recipe)
{
	int i;
	sfTime time = sfClock_getElapsedTime(screen->clock);
	float seconds = time.microseconds / 1000000.0;

	if (seconds < 0.2) {
		scene->objs[3].vector.x++;
		sfSprite_setPosition(
			scene->objs[3].sprite, scene->objs[3].vector);
	} else {
		for (i = 0; scene->buttons[i].id != 7; i++);
		scene->buttons[i].pos[0].x -= 2;
		scene->buttons[i].pos[1].x -= 2;
		scene->objs[3].rec.left += 180;
		if (scene->objs[3].rec.left > 360)
			scene->objs[3].rec.left = 0;
		sfSprite_setTextureRect(
			scene->objs[3].sprite, scene->objs[3].rec);
		set_button_recipe(scene, screen, recipe, i);
		sfClock_restart(screen->clock);
	}
}

void set_button_recipe(scene_t *scene, screen_t *screen, recipe_t *recipe, int i)
{
	if (scene->buttons[i].pos[0].x + 190 < 0)
		valid_recipe(recipe, scene, screen);
	if (sfRectangleShape_getPosition(
		    scene->buttons[i].rect).y == scene->buttons[i].pos[1].y)
		sfRectangleShape_setPosition(
			scene->buttons[i].rect, scene->buttons[i].pos[1]);
	else
		sfRectangleShape_setPosition(
			scene->buttons[i].rect, scene->buttons[i].pos[0]);
}

void timer(screen_t *screen, sfVector2f posText)
{
	sfTime time = sfClock_getElapsedTime(screen->timer);
	float seconds = time.microseconds / 1000000.0;

	if (seconds > 1) {
		if (screen->secT == 0) {
			screen->minT -= 1;
			screen->secT = 59;
			sfText_setString(
				screen->text[1], int_to_char(screen->minT));
		} else
			screen->secT--;
		set_timer(screen);
		sfClock_restart(screen->timer);
	}
	if (screen->minT <= 0 && screen->secT <= 0) {
		screen->num_scene = 3;
		if (char_to_int(read_only()) < screen->score)
			write_only(int_to_char(screen->score));
		sfText_setPosition(screen->text[0], posText);
	}
}

void set_timer(screen_t *screen)
{
	if (screen->secT < 10)
		sfText_setString(
			screen->text[2], my_strcat(
				":0", int_to_char(screen->secT)));
	else
		sfText_setString(
			screen->text[2], my_strcat(
				":", int_to_char(screen->secT)));
}

void finish_score(screen_t *screen, sfVector2f posText)
{
	sfText_setString(screen->text[0], read_only());
	sfText_setPosition(screen->text[0], posText);
	screen->score = 100;
	screen->num_scene = 0;
	screen->minT = 2;
	screen->secT = 0;
}
