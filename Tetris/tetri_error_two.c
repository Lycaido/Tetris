/*
** tetri_error_two.c for tetri_error_two in /home/mistralaix/delivery/project/tetris/PSU_2016_tetris
** 
** Made by cyril chaillan
** Login   <mistralaix@epitech.net>
** 
** Started on  Sat Mar 18 20:02:10 2017 cyril chaillan
** Last update Sat Mar 18 20:12:18 2017 cyril chaillan
*/

#include "include/tetris.h"

void	check_s(int *x, int i, char *tetriminos)
{
  int	c;
  int	b;

  b = i - 1;
  c = 0;
  while (tetriminos[++b] != '\n' && tetriminos[b])
    if (tetriminos[b] == '*')
      c = 1;
  if (c == 1)
    *x += 1;
}
