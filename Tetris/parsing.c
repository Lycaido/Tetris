/*
** parsing.c for parsing in /home/mistralaix/delivery/project/tetris/PSU_2016_tetris
** 
** Made by cyril chaillan
** Login   <mistralaix@epitech.net>
** 
** Started on  Mon Feb 27 19:01:08 2017 cyril chaillan
** Last update Sun Mar 19 16:53:11 2017 cyril chaillan
*/

#include "include/tetris.h"

int	check_key(t_tetris *tt)
{
  int	i;
  int	j;

  i = -1;
  j = -1;
  while (++j < 6)
    {
      while (++i < 6)
	if (i != j && tt->key->touches[j][0] == tt->key->touches[i][0] &&
	    tt->key->touches[j][1] == tt->key->touches[i][1]
	    && tt->key->touches[j][0] != 27 && tt->key->touches[i][0] != 27)
	  {
	    write(2, "Invalid keys : '", 16);
	    my_putkey(tt->key->touches[j], 2);
	    write(2, "' <--> '", 8);
	    my_putkey(tt->key->touches[i], 2);
	    write(2, "'\n", 2);
	    return (84);
	  }
    }
  return (0);
}

int	check_map_size(t_tetris *tetris)
{
  int	i;
  int	r;
  char	*str;

  i = -1;
  r = 0;
  str = my_strdup("Error : invalid argument : '--map-size=");
  while (tetris->key->size[++i])
    r = (tetris->key->size[i] == ',' ? r + 1 : r);
  if (r != 1)
    return (exit_errd(str, tetris->key->size, "'\n"));
  tetris->key->width = my_getnbr(tetris->key->size);
  i = -1;
  while (tetris->key->size[++i] != ',');
  tetris->key->height = my_getnbr(&tetris->key->size[i]);
  if (tetris->key->width <= 0 || tetris->key->height <= 0)
    return (exit_errd(str, tetris->key->size, "'\n"));
  return (0);
}

int	check_error_key(t_tetris *tetris)
{
  int	i;

  i = -1;
  while (++i < 6)
    if (tetris->key->touches[i][0] == 0)
      return (exit_err("Invalid key : ''\n"));
  if (tetris->key->level <= 0)
    return (exit_err("Error : Invalid argument : '-l'\n"));
  if (tetris->key->size[0] == 0)
    return (exit_err("Error : Invalid argument : '--map-size='\n"));
  i = -1;
  while (++i < 9)
    if (tetris->doub[i] > 1)
      return (exit_err("Error : Multiple calls of arguments\n"));
  return (0);
}

void	init_doub(t_tetris *tetris)
{
  int	i;

  i = -1;
  tetris->doub = malloc(sizeof(int) * (10));
  while (++i < 10)
    tetris->doub[i] = 0;
}

int	my_parsing(int ac, char **av, t_tetris *tetris)
{
  int	i;

  i = 0;
  init_doub(tetris);
  while (++i < ac)
    {
      if ((i = check_opt(i, ac, av, tetris)) == 84)
	return (84);
      if ((my_strcmp(av[i], "--help") == 0) || (my_strcmp(av[i], "-h") == 0))
	return (help(av[0]));
      if (tetris->err == 0)
	return (exit_errd("Error : invalid argument : '", av[i], "'\n"));
    }
  if ((check_error_key(tetris)) == 84 || (check_key(tetris)) == 84 ||
      (check_map_size(tetris)) == 84 || check_size_tetris(tetris) == 84)
    return (84);
  if (tetris->key->debug == 1)
    debug_mode(tetris);
  return (0);
}
