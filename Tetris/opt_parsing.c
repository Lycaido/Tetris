/*
** parsing.c for parsing in /home/mistralaix/delivery/project/tetris/PSU_2016_tetris
** 
** Made by cyril chaillan
** Login   <mistralaix@epitech.net>
** 
** Started on  Mon Feb 27 19:01:08 2017 cyril chaillan
** Last update Sun Mar 19 16:55:19 2017 cyril chaillan
*/

#include "include/tetris.h"

int	my_strmod(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] && s2[i])
    ++i;
  if (s2[i] == 0)
    return (0);
  return (s1[i] - s2[i]);
}

void	opt_four(int i, char **av, t_tetris *tetris)
{
  int	a;

  a = -1;
  if (my_strmod(av[i], "--key-left=") == 0)
    {
      tetris->doub[0] = tetris->doub[0] + 1;
      tetris->err = 1;
      while (av[i][++a] != '=');
      free(tetris->key->touches[0]);
      tetris->key->touches[0] = my_strdup(&av[i][a + 1]);
    }
  else if (my_strmod(av[i], "--key-drop=") == 0)
    {
      tetris->doub[3] = tetris->doub[3] + 1;
      tetris->err = 1;
      while (av[i][++a] != '=');
      free(tetris->key->touches[3]);
      tetris->key->touches[3] = my_strdup(&av[i][a + 1]);
    }
}

void	options_one(int i, char **av, t_tetris *tetris)
{
  int	a;

  a = -1;
  if (my_strmod(av[i], "--key-right=") == 0)
    {
      tetris->doub[1] = tetris->doub[1] + 1;
      tetris->err = 1;
      while (av[i][++a] != '=');
      free(tetris->key->touches[1]);
      tetris->key->touches[1] = my_strdup(&av[i][a + 1]);
    }
  else if (my_strmod(av[i], "--key-turn=") == 0)
    {
      tetris->doub[2] = tetris->doub[2] + 1;
      tetris->err = 1;
      while (av[i][++a] != '=');
      free(tetris->key->touches[2]);
      tetris->key->touches[2] = my_strdup(&av[i][a + 1]);
    }
}

void	options_two(int i, char **av, t_tetris *tetris)
{
  int	a;

  a = -1;
  if (my_strmod(av[i], "--key-quit=") == 0)
    {
      tetris->doub[4] = tetris->doub[4] + 1;
      tetris->err = 1;
      while (av[i][++a] != '=');
      free(tetris->key->touches[4]);
      tetris->key->touches[4] = my_strdup(&av[i][a + 1]);
    }
  else if (my_strmod(av[i], "--key-pause=") == 0)
    {
      tetris->doub[5] = tetris->doub[5] + 1;
      tetris->err = 1;
      while (av[i][++a] != '=');
      free(tetris->key->touches[5]);
      tetris->key->touches[5] = my_strdup(&av[i][a + 1]);
    }
}

void	options_three(int i, char **av, t_tetris *tetris)
{
  int	a;

  a = -1;
  if (my_strmod(av[i], "--level=") == 0)
    {
      tetris->doub[6] = tetris->doub[6] + 1;
      tetris->err = 1;
      while (av[i][++a] != '=');
      tetris->key->level = my_getnbr(&av[i][a + 1]);
    }
  else if (my_strmod(av[i], "--without-next=") == 0)
    {
      tetris->doub[7] = tetris->doub[7] + 1;
      tetris->err = 1;
      while (av[i][++a] != '=');
      tetris->key->next = 0;
    }
  else if (my_strmod(av[i], "--map-size=") == 0)
    {
      tetris->doub[8] = tetris->doub[8] + 1;
      tetris->err = 1;
      while (av[i][++a] != '=');
      free(tetris->key->size);
      tetris->key->size = my_strdup(&av[i][a + 1]);
    }
}
