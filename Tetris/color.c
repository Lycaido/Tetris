/*
** color.c for tetris in /home/Rev/PSU_2016_tetris/test_tetris_ncurses
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Mon Feb	27 19:02:45 2017 Roméo Nahon
** Last update	Mon Feb	27 19:02:45 2017 Roméo Nahon
*/

#include "include/tetris.h"

void	init_my_color()
{
  init_pair(0, COLOR_RED, COLOR_RED);
  init_pair(1, COLOR_RED, COLOR_RED);
  init_pair(2, COLOR_CYAN, COLOR_CYAN);
  init_pair(3, COLOR_MAGENTA, COLOR_MAGENTA);
  init_pair(4, COLOR_BLUE, COLOR_BLUE);
  init_pair(5, COLOR_YELLOW, COLOR_YELLOW);
  init_pair(6, COLOR_GREEN, COLOR_GREEN);
  init_pair(7, COLOR_GREEN, COLOR_GREEN);
  init_pair(8, COLOR_BLUE, COLOR_BLUE);
  init_pair(15, COLOR_WHITE, COLOR_RED);
  init_pair(16, COLOR_WHITE, COLOR_RED);
  init_pair(17, COLOR_WHITE, COLOR_CYAN);
  init_pair(18, COLOR_WHITE, COLOR_MAGENTA);
  init_pair(19, COLOR_WHITE, COLOR_BLUE);
  init_pair(20, COLOR_WHITE, COLOR_YELLOW);
  init_pair(21, COLOR_WHITE, COLOR_GREEN);
  init_pair(22, COLOR_WHITE, COLOR_GREEN);
  init_pair(23, COLOR_WHITE, COLOR_BLUE);
  init_pair(9, COLOR_RED, COLOR_BLACK);
  init_pair(10, COLOR_CYAN, COLOR_BLACK);
  init_pair(11, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(12, COLOR_BLUE, COLOR_BLACK);
  init_pair(13, COLOR_YELLOW, COLOR_BLACK);
  init_pair(14, COLOR_GREEN, COLOR_BLACK);
}
