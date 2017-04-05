/*
** parsing.c for parsing in /home/mistralaix/delivery/project/tetris/PSU_2016_tetris
** 
** Made by cyril chaillan
** Login   <mistralaix@epitech.net>
** 
** Started on  Mon Feb 27 19:01:08 2017 cyril chaillan
** Last update Sun Mar 19 16:53:36 2017 cyril chaillan
*/

#include "include/tetris.h"

int	bs_options_one(int i, int ac, char **av, t_tetris *tetris)
{
  if (my_strcmp(av[i], "-kt") == 0)
    {
      tetris->doub[2] = tetris->doub[2] + 1;
      tetris->err = 1;
      if (i + 1 < ac)
	{
	  free(tetris->key->touches[2]);
	  tetris->key->touches[2] = my_strdup(av[++i]);
	}
      else
	return (exit_err("Error : invalid argument : '-kt'\n"));
    }
  return (i);
}

int	basic_options_one(int i, int ac, char **av, t_tetris *tetris)
{
  if (my_strcmp(av[i], "-kl") == 0)
    {
      tetris->err = 1;
      tetris->doub[0] = tetris->doub[0] + 1;
      if (i + 1 < ac)
	tetris->key->touches[0] = my_strdup(av[++i]);
      else
	return (exit_err("Error : invalid argument : '-kl'\n"));
    }
  else if (my_strcmp(av[i], "-kr") == 0)
    {
      tetris->doub[1] = tetris->doub[1] + 1;
      tetris->err = 1;
      if (i + 1 < ac)
	tetris->key->touches[1] = my_strdup(av[++i]);
      else
	return (exit_err("Error : invalid argument : '-kr'\n"));
    }
  else if (my_strcmp(av[i], "-kt") == 0)
    if ((i = bs_options_one(i, ac, av, tetris)) == 84)
      return (84);
  return (i);
}

int	bs_options(int i, int ac, char **av, t_tetris *tetris)
{
  if (my_strcmp(av[i], "-kp") == 0)
    {
      tetris->doub[5] = tetris->doub[5] + 1;
      tetris->err = 1;
      if (i + 1 < ac)
	{
	  free(tetris->key->touches[5]);
	  tetris->key->touches[5] = my_strdup(av[++i]);
	}
      else
	return (exit_err("Error : invalid argument : '-kp'\n"));
    }
  else if (my_strcmp(av[i], "-l") == 0)
    {
      tetris->doub[6] = tetris->doub[6] + 1;
      tetris->err = 1;
      if (i + 1 < ac)
	tetris->key->level = my_getnbr(av[++i]);
      else
	return (exit_err("Error : invalid argument : '-l'\n"));
    }
  return (i);
}

int	basic_options_two(int i, int ac, char **av, t_tetris *tetris)
{
  if (my_strcmp(av[i], "-kd") == 0)
    {
      tetris->doub[3] = tetris->doub[3] + 1;
      tetris->err = 1;
      if (i + 1 < ac)
	tetris->key->touches[3] = my_strdup(av[++i]);
      else
	return (exit_err("Error : invalid argument : '-kd'\n"));
    }
  else if (my_strcmp(av[i], "-kq") == 0)
    {
      tetris->doub[4] = tetris->doub[4] + 1;
      tetris->err = 1;
      if (i + 1 < ac)
	tetris->key->touches[4] = my_strdup(av[++i]);
      else
	return (exit_err("Error : invalid argument : '-kq'\n"));
    }
  else if (my_strcmp(av[i], "-kp") == 0 || my_strcmp(av[i], "-l") == 0)
    if ((i = bs_options(i, ac, av, tetris)) == 84)
      return (84);
  return (i);
}

int	basic_options_three(int i, char **av, t_tetris *tetris)
{
  if (my_strcmp(av[i], "-w") == 0)
    {
      tetris->doub[7] = tetris->doub[7] + 1;
      tetris->err = 1;
      tetris->key->next = 0;
    }
  else if ((my_strcmp(av[i], "-d") == 0) || (my_strcmp(av[i], "--debug") == 0))
    {
      tetris->err = 1;
      tetris->key->debug = 1;
    }
  return (0);
}
