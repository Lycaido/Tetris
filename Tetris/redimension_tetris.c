/*
** redimension_tetris.c for redimension_tetris in /home/mistralaix/delivery/project/tetris/PSU_2016_tetris
** 
** Made by cyril chaillan
** Login   <mistralaix@epitech.net>
** 
** Started on  Sat Mar 11 11:44:44 2017 cyril chaillan
** Last update Sat Mar 18 22:20:13 2017 cyril chaillan
*/

#include "include/tetris.h"

void	end_tab(int l, int *size, int c, int **cp)
{
  while (l < *size)
    {
      if ((cp[l] = malloc(sizeof(int) * (*size))) == NULL)
	exit(84);
      c = -1;
      while (++c < *size)
	cp[l][c] = 0;
      ++l;
    }
}

int	**create_int(int **tab, int *size, int old_size)
{
  int	**cp;
  int	l;
  int	c;
  int	nc;

  *size = old_size * 2;
  if ((cp = malloc(sizeof(int*) * (*size))) == NULL)
    exit(84);
  l = -1;
  while (++l < old_size)
    {
      c = -1;
      nc = -1;
      if ((cp[l] = malloc(sizeof(int) * (*size))) == NULL)
	exit(84);
      while (++c < old_size)
	{
	  cp[l][++nc] = tab[l][c];
	  cp[l][++nc] = tab[l][c];
	}
    }
  end_tab(l, size, c, cp);
  return (cp);
}

void	get_wid_hei_tetri(t_tetri_list *list)
{
  int	i;

  i = -1;
  if (list->tetri_error == 0)
    {
      while (list->tetri_size[++i] != '*');
      list->width = my_getnbr(list->tetri_size);
      list->height = my_getnbr(&list->tetri_size[i]);
    }
  else
    {
      list->width = 0;
      list->height = 0;
    }
}

t_tetri_first_list	*redimension_tab(t_tetri_first_list *tetris,
					 t_tetris *tt)
{
  t_tetri_list	*list;
  t_tetri_list	*stock;
  int	i;

  if (tetris == NULL || tetris->first == NULL)
    return (NULL);
  list = tetris->first;
  stock = list;
  i = -1;
  while (++i < tt->nbr)
    {
      if (list->tetri_error == 0)
	{
	  get_wid_hei_tetri(list);
	  list->jeu = create_int(list->tetri_forme, &list->size,
				 list->tetri_size_only);
	}
      if (list->next != NULL)
	list = list->next;
    }
  list->next = NULL;
  get_wid_hei_tetri(list);
  tetris->first = stock;
  return (tetris);
}

int	check_size_tetris(t_tetris *tetris)
{
  t_tetri_list	*list;

  if (tetris->list == NULL)
    return (0);
  list = tetris->list->first;
  while (list)
    {
      if (list->tetri_error == 0)
	{
	  if (list->width > tetris->key->width)
	    list->tetri_error = 1;
	  if (list->height > tetris->key->height)
	    list->tetri_error = 1;
	}
      list = list->next;
    }
  return (0);
}
