/*
** press.c for press in /home/mistralaix/delivery/project/tetris/PSU_2016_tetris
** 
** Made by cyril chaillan
** Login   <mistralaix@epitech.net>
** 
** Started on  Wed Mar  8 18:01:14 2017 cyril chaillan
** Last update Sun Mar 19 19:26:27 2017 Roméo Nahon
*/

#include "include/tetris.h"

void	check_size_term(void)
{
  int	x;
  int	y;

  getmaxyx(stdscr, y, x);
  while (!(48 <= y && y <= 52 && 236 <= x && x <= 250))
    {
      clear();
      mvprintw(LINES / 2, COLS / 2 - 5, "Resize terminal to 50*238 col");
      refresh();
      getmaxyx(stdscr, y, x);
    }
}

int	exit_err(char *str)
{
  write(2, str, my_strlen(str));
  return (84);
}

int	exit_errd(char *str, char *str2, char *str3)
{
  write(2, str, my_strlen(str));
  write(2, str2, my_strlen(str2));
  write(2, str3, my_strlen(str3));
  return (84);
}

void	my_press(t_tetris *tetris, int ch)
{
  if (my_strlen(tetris->press) > 10)
    tetris->pr = 0;
  if (tetris->pr == 0)
    {
      my_memset(tetris->press, 0, 29);
      tetris->idx = -1;
    }
  if (ch != -1)
    tetris->press[++tetris->idx] = ch;
}
