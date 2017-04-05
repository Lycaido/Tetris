/*
** blink_next.c for tetris in /home/Rev/PSU_2016_tetris
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Tue Mar	14 15:20:17 2017 Roméo Nahon
** Last update	Tue Mar	14 15:20:17 2017 Roméo Nahon
*/

#include "include/tetris.h"

void	key_box_next(WINDOW *key_box, int color)
{
  wattron(key_box, COLOR_PAIR(color) | A_BOLD);
  wborder(key_box, '|', '|', '-', '-', '+', '+', '+', '+');
  mvwprintw(key_box, 9, 50, "-----------------------------------");
  mvwprintw(key_box, 9, 20, "------------------------------");
  mvwprintw(key_box, 1, 1, "-");
  mvwprintw(key_box, 2, 3, "-");
  mvwprintw(key_box, 3, 5, "-");
  mvwprintw(key_box, 4, 7, "-");
  mvwprintw(key_box, 5, 9, "-");
  mvwprintw(key_box, 6, 11, "-");
  mvwprintw(key_box, 7, 13, "-");
  mvwprintw(key_box, 8, 15, "-");
  mvwprintw(key_box, 9, 17, "---");
  mvwprintw(key_box, 1, 107, "-");
  mvwprintw(key_box, 2, 105, "-");
  mvwprintw(key_box, 3, 103, "-");
  mvwprintw(key_box, 4, 101, "-");
  mvwprintw(key_box, 5, 99, "-");
  mvwprintw(key_box, 6, 97, "-");
  mvwprintw(key_box, 7, 95, "-");
  mvwprintw(key_box, 8, 93, "-");
  mvwprintw(key_box, 9, 84, "---------");
  wrefresh(key_box);
}

void	draw_two(int y, int x)
{
  y = -1;
  while (++y < 80)
    {
      x = 173;
      while (++x < 253)
	{
	  if ((rand() % 15) == 1)
	    {
	      attron(COLOR_PAIR(rand() % (9 - 14) + 9) | A_BOLD);
	      mvprintw(y, x, "-");
	      attroff(COLOR_PAIR(rand() % (9 - 14) + 9) | A_BOLD);
	    }
	}
    }
}

void		draw_everywhere(void)
{
  int		x;
  int		y;
  time_t	t;

  srand((unsigned) time(&t));
  y = -1;
  while (++y < 80)
    {
      x = -1;
      while (++x < 65)
	{
	  if ((rand() % 15) == 1)
	    {
	      attron(COLOR_PAIR(rand() % (9 - 14) + 9) | A_BOLD);
	      mvprintw(y, x, "-");
	      attroff(COLOR_PAIR(rand() % (9 - 14) + 9) | A_BOLD);
	    }
	}
    }
  draw_two(y, x);
}
