/*
** draw_tetris_name.c for tetris in /home/Rev/PSU_2016_tetris/test_tetris_ncurses
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Mon Feb	27 18:09:24 2017 Roméo Nahon
** Last update	Mon Feb	27 18:09:24 2017 Roméo Nahon
*/

#include "include/tetris.h"

void	s_patern(WINDOW *name_box)
{
  wattron(name_box, COLOR_PAIR(10));
  mvwprintw(name_box, 2, 85, " ********");
  mvwprintw(name_box, 3, 85, "*");
  mvwprintw(name_box, 4, 85, " ********");
  mvwprintw(name_box, 5, 93, "*");
  mvwprintw(name_box, 6, 85, " ********");
  wattroff(name_box, COLOR_PAIR(10));
}

void	r_patern(WINDOW *name_box)
{
  wattron(name_box, COLOR_PAIR(14));
  mvwprintw(name_box, 2, 55, "**********");
  mvwprintw(name_box, 3, 56, "**");
  mvwprintw(name_box, 3, 62, "***");
  mvwprintw(name_box, 4, 56, "**");
  mvwprintw(name_box, 4, 62, "***");
  mvwprintw(name_box, 5, 56, "*******");
  mvwprintw(name_box, 6, 55, "****");
  mvwprintw(name_box, 6, 62, "***");
  wattroff(name_box, COLOR_PAIR(14));
}

void	i_patern(WINDOW *name_box)
{
  wattron(name_box, COLOR_PAIR(11));
  mvwprintw(name_box, 2, 73, "****");
  mvwprintw(name_box, 3, 74, "**");
  mvwprintw(name_box, 4, 74, "**");
  mvwprintw(name_box, 5, 74, "**");
  mvwprintw(name_box, 6, 73, "****");
  wattroff(name_box, COLOR_PAIR(11));
}

void	e_patern(WINDOW *name_box)
{
  wattron(name_box, COLOR_PAIR(12));
  mvwprintw(name_box, 2, 25, "**********");
  mvwprintw(name_box, 3, 25, "***");
  mvwprintw(name_box, 4, 25, "**********");
  mvwprintw(name_box, 5, 25, "***");
  mvwprintw(name_box, 6, 25, "**********");
  wattroff(name_box, COLOR_PAIR(12));
}

void		tetris_patern(WINDOW *name_box)
{
  wattron(name_box, COLOR_PAIR(9));
  mvwprintw(name_box, 2, 10, "**********");
  mvwprintw(name_box, 3, 14, "**");
  mvwprintw(name_box, 4, 14, "**");
  mvwprintw(name_box, 5, 14, "**");
  mvwprintw(name_box, 6, 14, "**");
  wattroff(name_box, COLOR_PAIR(9));
  e_patern(name_box);
  wattron(name_box, COLOR_PAIR(13));
  mvwprintw(name_box, 2, 40, "**********");
  mvwprintw(name_box, 3, 44, "**");
  mvwprintw(name_box, 4, 44, "**");
  mvwprintw(name_box, 5, 44, "**");
  mvwprintw(name_box, 6, 44, "**");
  wattroff(name_box, COLOR_PAIR(13));
  r_patern(name_box);
  i_patern(name_box);
  s_patern(name_box);
}
