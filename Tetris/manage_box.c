/*
** manage_box.c for tetris in /home/Rev/PSU_2016_tetris/test_tetris_ncurses
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Tue Feb	28 17:04:50 2017 Roméo Nahon
** Last update	Tue Feb	28 17:04:50 2017 Roméo Nahon
*/

#include "include/tetris.h"

void	create_cool_box(t_tetris *tt)
{
  tt->window->level = subwin(stdscr, 5, 20, 11, 72);
  box(tt->window->level, ACS_VLINE, ACS_HLINE);
  tt->window->hscore = subwin(stdscr, 5, 20, 20, 72);
  box(tt->window->hscore, ACS_VLINE, ACS_HLINE);
  tt->window->score = subwin(stdscr, 5, 24, 29, 70);
  box(tt->window->score, ACS_VLINE, ACS_HLINE);
  tt->window->next = subwin(stdscr, 15, 32, 11, 140);
  box(tt->window->next, ACS_VLINE, ACS_HLINE);
  tt->window->timer = subwin(stdscr, 5, 20, 27, 146);
  box(tt->window->timer, ACS_VLINE, ACS_HLINE);
  tt->window->lines = subwin(stdscr, 5, 20, 33, 146);
  box(tt->window->lines, ACS_VLINE, ACS_HLINE);
}

void		create_box(t_tetris *tt)
{
  tt->window->frame_game_box = subwin(stdscr, LINES / 2 + 5,
				      COLS / 2 - 10,
				      LINES / 4 - (6 / 2), COLS / 4 + 6);
  wborder(tt->window->frame_game_box,
	  '|', '|', '-', '-', '+', '+', '+', '+');
  tt->window->name_box = subwin(stdscr, LINES / 2 - 15,
				COLS / 2 - 10, 0, COLS / 4 + 6);
  wborder(tt->window->name_box,
	  '|', '|', '-', '-', '+', '+', '+', '+');
  tt->window->key_box = subwin(stdscr, LINES / 4 - 1,
			       COLS / 2 - 10, LINES / 2 + 14, COLS / 4 + 6);
  wborder(tt->window->key_box, '|', '|',
	  '-', '-', '+', '+', '+', '+');
  tt->window->game_box = subwin(stdscr, (LINES / 2 + 5) - tt->map->w_gb_x,
				(COLS / 2 - 78) -
				tt->map->w_gb_y, (LINES / 4 - 3)
				+ tt->map->gb_x,
				(COLS / 4 + 39) + tt->map->gb_y);
  wborder(tt->window->game_box, '|', '|', '-', '-',
	  '+', '+', '+', '+');
  tt->window->joystick_box = subwin(stdscr, (LINES / 4 - 3),
				    (COLS / 2 + 20) / 2,
				    (LINES / 2 + 14), (COLS / 4 + 18));
  create_cool_box(tt);
}

void		display_box_color(t_tetris* tetris, int i, int ch)
{
  display_game_box(tetris->window->game_box, i, tetris->count->a);
  display_frame_game_box(tetris->window->frame_game_box,
			 i, tetris->count->a);
  display_name_box(tetris->window->name_box, i, tetris->count->a);
  display_joysticks(tetris, ch);
  display_button(tetris, ch);
  display_key_box(tetris->window->key_box, i, tetris->count->a);
  wrefresh(tetris->window->hscore);
  wrefresh(tetris->window->level);
  wrefresh(tetris->window->score);
  wrefresh(tetris->window->next);
  wrefresh(tetris->window->lines);
  if (i == tetris->count->a + 55)
    tetris->count->a = i;
}
