/*
** get_score.c for get_sphere in /home/mistralaix/delivery/project/tetris/PSU_2016_tetris
** 
** Made by cyril chaillan
** Login   <mistralaix@epitech.net>
** 
** Started on  Sat Mar 18 20:36:43 2017 cyril chaillan
** Last update Sun Mar 19 17:16:26 2017 cyril chaillan
*/

#include "include/tetris.h"

char	*i_score(char *str, int *nb)
{
  int	i;

  i = -1;
  while (str[++i] != ':');
  *nb = my_getnbr(&str[i + 1]);
  str[i] = 0;
  return (str);
}

void	get_score(t_tetris *tetris)
{
  tetris->score->fd = open("score.tetris", O_RDWR);
  tetris->score->play = 0;
  while ((tetris->score->name = get_next_line(tetris->score->fd)))
    {
      tetris->score->name = i_score(tetris->score->name, &tetris->score->high);
      if (tetris->score->high > tetris->score->play)
        {
          tetris->score->play = tetris->score->high;
          tetris->score->file = tetris->score->name;
        }
    }
  tetris->score->high = tetris->score->play;
  tetris->score->name = my_strdup("Random");
}

int	init_struct(t_tetris *tetris, char **env)
{
  if (!env[0])
    return (exit_err("Error : Setup terminal\n"));
  if ((tetris->key = malloc(sizeof(*tetris->key))) == NULL)
    return (84);
  if ((tetris->window = malloc(sizeof(*tetris->window))) == NULL)
    return (84);
  if ((tetris->count = malloc(sizeof(*tetris->count))) == NULL)
    return (84);
  if ((tetris->score = malloc(sizeof(*tetris->score))) == NULL)
    return (84);
  get_score(tetris);
  return (0);
}
