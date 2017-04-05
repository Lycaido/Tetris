/*
** rotation.c for rotation in /home/mistralaix/delivery/project/tetris/PSU_2016_tetris
** 
** Made by cyril chaillan
** Login   <mistralaix@epitech.net>
** 
** Started on  Thu Mar  2 15:41:53 2017 cyril chaillan
** Last update Sun Mar 19 16:57:43 2017 cyril chaillan
*/

#include "include/tetris.h"

int	**copy_tab(int **tab, int size)
{
  int	l;
  int	c;
  int	**arr;

  arr = malloc(sizeof(int*) * (size));
  l = -1;
  while (++l < size)
    {
      arr[l] = malloc(sizeof(int) * (size));
      c = -1;
      while (++c < size)
	arr[l][c] = tab[l][c];
    }
  return (arr);
}

void	swap_size(t_tetri_list *tetriminos)
{
  int	i;
  int	j;
  char	*y_size_char;
  char	*x_size_char;

  i = 0;
  j = 0;
  if ((y_size_char = malloc(sizeof(char) * 3)) == NULL)
    exit(84);
  if ((x_size_char = malloc(sizeof(char) * 3)) == NULL)
    exit(84);
  while (tetriminos->tetri_size[i] != '*')
    x_size_char[j++] = tetriminos->tetri_size[i++];
  j = 0;
  while (tetriminos->tetri_size[++i] != '\0')
    y_size_char[j++] = tetriminos->tetri_size[i];
  i = -1;
  j = -1;
  while (y_size_char[++i] != '\0')
    tetriminos->tetri_size[i] = y_size_char[i];
  while (x_size_char[++j] != '\0')
    tetriminos->tetri_size[++i] = x_size_char[j];
}

int	**rotate(int **tab, int size)
{
  int	l;
  int	c;
  int	nl;
  int	nc;
  int	**arr;

  arr = copy_tab(tab, size);
  c = size;
  nl = -1;
  while (--c > -1)
    {
      l = -1;
      ++nl;
      nc = -1;
      while (++l < size)
	tab[l][c] = arr[nl][++nc];
    }
  return (tab);
}
