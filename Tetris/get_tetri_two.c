/*
** get_tetri_two.c for get_tetri_two in /home/mistralaix/delivery/project/tetris/PSU_2016_tetris
** 
** Made by cyril chaillan
** Login   <mistralaix@epitech.net>
** 
** Started on  Sat Mar 18 21:08:31 2017 cyril chaillan
** Last update Sun Mar 19 17:16:52 2017 cyril chaillan
*/

#include "include/tetris.h"

int	**get_tetri_forme(char *tetriminos, char *tetri_mension,
			  int *tetri_size)
{
  char	**tab;
  int	**tetri_forme;
  int	width;
  int	height;
  int	i;

  parse_tetri_mension(tetri_mension, &width, &height);
  while (width < height)
    width++;
  while (height < width)
    height++;
  tab = my_str_to_wordtab(tetriminos);
  if ((tetri_forme = malloc(sizeof(int *) * (width + 1))) == NULL)
    exit(84);
  tetri_forme = get_my_form(tetriminos, tetri_forme, width, height);
  *tetri_size = width;
  i = -1;
  while (tab[++i])
    free(tab[i]);
  free(tab);
  return (tetri_forme);
}

void	get_end_tab(int y, int j, int width, int **tab)
{
  while (++y < width)
    {
      j = -1;
      if ((tab[y] = malloc(sizeof(int) * width)) == NULL)
        exit(84);
      while (++j < width)
        tab[y][j] = 0;
    }
}
