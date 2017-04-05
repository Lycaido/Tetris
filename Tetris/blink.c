/*
** blink.c for tetris in /home/Rev/PSU_2016_tetris/test_tetris_ncurses
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Mon Feb	27 16:38:30 2017 Roméo Nahon
** Last update	Mon Feb	27 16:38:30 2017 Roméo Nahon
*/

#include "include/tetris.h"

void	display_frame_game_box(WINDOW *frame_game_box, int i, int a)
{
  if (i == a + 1)
    {
      wattron(frame_game_box, COLOR_PAIR(9) | A_BOLD);
      wborder(frame_game_box, '|', '|', '-', '-', '+', '+', '+', '+');
    }
  else if (i == a + 15)
    {
      wattron(frame_game_box, COLOR_PAIR(10) | A_BOLD);
      wborder(frame_game_box, '|', '|', '-', '-', '+', '+', '+', '+');
    }
  else if (i == a + 30)
    {
      wattron(frame_game_box, COLOR_PAIR(11) | A_BOLD);
      wborder(frame_game_box, '|', '|', '-', '-', '+', '+', '+', '+');
    }
  else
    {
      wattron(frame_game_box, COLOR_PAIR(12) | A_BOLD);
      wborder(frame_game_box, '|', '|', '-', '-', '+', '+', '+', '+');
    }
  wattroff(frame_game_box, COLOR_PAIR(12) | A_BOLD);
  wrefresh(frame_game_box);
}

void	display_name_box(WINDOW *name_box, int i, int a)
{
  tetris_patern(name_box);
  if (i == a + 1)
    {
      wattron(name_box, COLOR_PAIR(9) | A_BOLD);
      wborder(name_box, '|', '|', '-', '-', '+', '+', '+', '+');
    }
  else if (i == a + 15)
    {
      wattron(name_box, COLOR_PAIR(10) | A_BOLD);
      wborder(name_box, '|', '|', '-', '-', '+', '+', '+', '+');
    }
  else if (i == a + 30)
    {
      wattron(name_box, COLOR_PAIR(11) | A_BOLD);
      wborder(name_box, '|', '|', '-', '-', '+', '+', '+', '+');
    }
  else
    {
      wattron(name_box, COLOR_PAIR(12) | A_BOLD);
      wborder(name_box, '|', '|', '-', '-', '+', '+', '+', '+');
    }
  wattroff(name_box, COLOR_PAIR(12) | A_BOLD);
  wrefresh(name_box);
}

void	display_key_box(WINDOW* key_box, int i, int a)
{
  if (i == a + 1)
    key_box_next(key_box, 9);
  else if (i == a + 15)
    key_box_next(key_box, 10);
  else if (i == a + 30)
    key_box_next(key_box, 11);
  else
    key_box_next(key_box, 12);
  wattroff(key_box, COLOR_PAIR(12) | A_BOLD);
}

void	display_game_box(WINDOW	*game_box, int i, int a)
{
  if (i == a + 1)
    {
      wattron(game_box, COLOR_PAIR(9) | A_BOLD);
      wborder(game_box, '|', '|', '-', '-', '+', '+', '+', '+');
    }
  else if (i == a + 15)
    {
      wattron(game_box, COLOR_PAIR(10) | A_BOLD);
      wborder(game_box, '|', '|', '-', '-', '+', '+', '+', '+');
    }
  else if (i == a + 30)
    {
      wattron(game_box, COLOR_PAIR(11) | A_BOLD);
      wborder(game_box, '|', '|', '-', '-', '+', '+', '+', '+');
    }
  else
    {
      wattron(game_box, COLOR_PAIR(12) | A_BOLD);
      wborder(game_box, '|', '|', '-', '-', '+', '+', '+', '+');
    }
  wattroff(game_box, COLOR_PAIR(12) | A_BOLD);
  wrefresh(game_box);
}
