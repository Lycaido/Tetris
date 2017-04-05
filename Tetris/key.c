/*
** key.c for key in /home/mistralaix/delivery/project/tetris/PSU_2016_tetris
**
** Made by cyril chaillan
** Login   <mistralaix@epitech.net>
** 
** Started on  Mon Feb 27 17:19:12 2017 cyril chaillan
** Last update Sat Mar 18 21:07:20 2017 cyril chaillan
*/

#include "include/tetris.h"

void	my_putkey(char *str, int sortie)
{
  int	i;

  i = -1;
  while (str[++i])
    {
      if (str[i] == ' ')
	write(sortie, "(space)", 7);
      else if (str[i] == 27)
	write(sortie, "^E", 2);
      else if (str[i] == 31)
	write(sortie, "US", 2);
      else if (str[i] == 30)
	write(sortie, "RS", 2);
      else if ((20 <= str[i] && str[i] <= 26) ||
	       str[i] == 28 || str[i] == 29)
	spec_key_two(str, i, sortie);
      else if (4 <= str[i] && str[i] <= 13)
	spec_key(str, i, sortie);
      else if ((0 <= str[i] && str[i] <= 3) ||
	       (14 <= str[i] && str[i] <= 19))
	spec_key_three(str, i, sortie);
      else
	write(sortie, &str[i], 1);
    }
  sortie == 1 ? write(sortie, "\n", 1) : 0;
}

void	init_arrow(t_tetris *tetris)
{
  int	i;

  i = -1;
  tetris->key->touches = malloc(sizeof(char*) * (7));
  while (++i < 6)
    tetris->key->touches[i] = malloc(sizeof(char) * (5));
  tetris->key->touches[6] = NULL;
}

void	my_key(char **arr, t_tetris *tetris)
{
  int	i;
  int	j;

  i = -1;
  while (arr[++i])
    {
      j = -1;
      if (i == 0)
	{
	  while (arr[i][++j])
	    tetris->key->touches[2][j] = arr[i][j];
	  tetris->key->touches[2][j++] = 0;
	}
      else if (1 <= i && i <= 3)
	j = get_key(i, j, tetris, arr);
    }
}

void	get_key_base(t_tetris *tetris)
{
  init_arrow(tetris);
  tetris->key->touches[4] = my_strdup("q");
  tetris->key->touches[5] = my_strdup(" ");
  tetris->key->next = 1;
  tetris->key->level = 1;
  tetris->key->size = my_strdup("20,10");
  tetris->key->width = 20;
  tetris->key->height = 10;
}

void	debug_mode(t_tetris *tetris)
{
  my_printf("*** DEBUG MODE ***\n");
  my_printf("Key Left : ");
  my_putkey(tetris->key->touches[0], 1);
  my_printf("Key Right : ");
  my_putkey(tetris->key->touches[1], 1);
  my_printf("Key Turn : ");
  my_putkey(tetris->key->touches[2], 1);
  my_printf("Key Drop : ");
  my_putkey(tetris->key->touches[3], 1);
  my_printf("Key Quit : ");
  my_putkey(tetris->key->touches[4], 1);
  my_printf("Key Pause : ");
  my_putkey(tetris->key->touches[5], 1);
  if (tetris->key->next == 1)
    my_printf("Next : Yes\n");
  else
    my_printf("Next : No\n");
  my_printf("Level : %d\n", tetris->key->level);
  my_printf("Size : %d*%d\n", tetris->key->width, tetris->key->height);
  aff_list_tetrimino(tetris->list);
  my_printf("Press any key to start Tetris\n");
}
