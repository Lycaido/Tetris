/*
** tetri_error.c for tetris in /home/Rev/PSU_2016_tetris
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Fri Feb	24 10:49:58 2017 Roméo Nahon
** Last update	Fri Feb	24 10:49:58 2017 Roméo Nahon
*/

#include "include/tetris.h"

int	get_tetri_size_ap_av(t_tetri_list tetri_value, char *second_nb,
			     int *tetri_size_av, int *tetri_size_ap)
{
  int	i;
  int	j;

  i = -1;
  j = 0;
  if (!(tetri_value.tetri_size))
    return (1);
  while (tetri_value.tetri_size[++i])
    {
      *tetri_size_av = my_getnbr(tetri_value.tetri_size);
      while (tetri_value.tetri_size[i++] != '*' &&
	     tetri_value.tetri_size[i]);
      while (tetri_value.tetri_size[i] >= '0' &&
	     tetri_value.tetri_size[i] <= '9' && tetri_value.tetri_size[i])
	second_nb[j++] = tetri_value.tetri_size[i++];
      *tetri_size_ap = my_getnbr(second_nb);
    }
  return (0);
}
int	check_first_line(char *tetriminos, int height)
{
  int i;
  int nb;

  i = -1;
  nb = 0;
  while (tetriminos[++i] && nb <= height)
    {
      if (!('0' <= tetriminos[i] && tetriminos[i] <= '9') && tetriminos[i]
	  != ' ' && tetriminos[i] != '\n' && tetriminos[i] != '*')
	return (1);
      if (tetriminos[i] == '\n') ++nb;
    }
  nb = 0;
  i = -1;
  while (tetriminos[++i] != '\n' && tetriminos[i])
    {
      while (tetriminos[i] >= '0' && tetriminos[i] <= '9' && tetriminos[i])
	i += 1;
      if (i > 0 && tetriminos[i - 1] >= '0' && tetriminos[i - 1] <= '9')
	nb += 1;
    }
  return (nb == 3 ? 0 : 1);
}

int	check_size_and_form(char *tetriminos, int tetri_size_ap,
			    int tetri_size_av)
{
  int	i;
  int	x;
  int	y;
  int	nb_x;

  i = -1;
  x = y = nb_x = 0;
  while (tetriminos[++i] != '\n');
  if (tetriminos[i + 1] == '*' && tetriminos[i + 2] == 0)
    return (0);
  while (tetriminos[++i] != '\0' && y <= tetri_size_ap)
    {
      tetriminos[i] == '*' ? (x += 1) : check_s(&x, i, tetriminos);
      if (tetriminos[i] == '\n' || (tetriminos[i + 1] == 0 && x > 0))
	{
	  y += 1;
	  if (nb_x < x) nb_x = x;
	  x = 0;
	}
    }
  if (nb_x != tetri_size_av)
    return (1);
  return (0);
}

int		tetri_forme_error(t_tetri_list tetri_value, char *tetriminos)
{
  char *second_nb;
  int	tetri_size_av;
  int tetri_size_ap;
  int	i;

  tetri_size_ap = 0;
  tetri_size_av = 0;
  if ((second_nb = malloc(sizeof(char) * 30)) == NULL)
    exit(84);
  second_nb = my_memset(second_nb, 0, 30);
  if ((get_tetri_size_ap_av(tetri_value,
			    second_nb, &tetri_size_av, &tetri_size_ap)) == 1)
    return (1);
  if (check_first_line(tetriminos, tetri_size_ap) == 1)
    return (1);
  if (check_size_and_form(tetriminos, tetri_size_ap, tetri_size_av) == 1)
    return (1);
  if (tetri_value.tetri_color > 7)
    return (1);
  i = -1;
  while (tetriminos[++i] && tetriminos[i] != '\n');
  if (tetri_value.tetri_size_only == 1 && tetriminos[++i]
      && tetriminos[i] != '*')
    return (1);
  return (0);
}

int		check_name_of_file(char *tetri_file)
{
  int		i;

  i = my_strlen(tetri_file) - 1;
  while (tetri_file[--i] != '.' && i > -1)
    if (i > 70)
      return (1);
  if (my_strcmp(&tetri_file[++i], "tetrimino") == 0)
    return (0);
  return (1);
}
