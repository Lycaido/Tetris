/*
** aff_list.c for aff_list in /home/mistralaix/delivery/project/tetris/PSU_2016_tetris
** 
** Made by cyril chaillan
** Login   <mistralaix@epitech.net>
** 
** Started on  Fri Feb 24 17:46:10 2017 cyril chaillan
** Last update Sun Mar 19 21:53:51 2017 cyril chaillan
*/

#include "include/tetris.h"

int	my_count_elem(t_tetri_first_list *list)
{
  t_tetri_list	*element;
  int		i;

  i = 0;
  element = list->first;
  while (element)
    {
      ++i;
      element = element->next;
    }
  return (i);
}

void	check_end_line(int j, t_tetri_list *element, int i)
{
  int	b;
  int	c;

  b = j;
  c = 0;
  while (++b < element->tetri_size_only)
    if (element->tetri_forme[i][b] == 1)
      c = 1;
  if (c == 1)
    my_printf(" ");
}

void	beg_aff(t_tetri_list *element, int *i, int *a)
{
  my_printf("Tetriminos : Name %s", element->tetri_name);
  my_printf(" : Size %s : ", element->tetri_size);
  my_printf("Color %d :\n", element->tetri_color);
  *i = 0;
  *a = -1;
  while (element->tetri_size[++(*a)] != '*');
  *a = my_getnbr(&element->tetri_size[*a + 1]);
}

void	in_bouc(t_tetri_list *element, int *i)
{
  int	j;

  j = -1;
  while (++j < element->tetri_size_only)
    {
      if (element->tetri_forme[*i][j] == 1)
	my_printf("*");
      else
	check_end_line(j, element, *i);
    }
  *i += 1;
  my_printf("\n");
}

void	aff_list_tetrimino(t_tetri_first_list *list)
{
  t_tetri_list	*element;
  int		i;
  int		a;

  if (!(list))
    {
      my_printf("Tetriminos : 0\n");
      return ;
    }
  element = list->first;
  my_printf("Tetriminos : %d\n", my_count_elem(list));
  while (element)
    {
      if (element->tetri_error == 0)
	{
	  beg_aff(element, &i, &a);
	  while (i < a)
	    in_bouc(element, &i);
	}
      else
	my_printf("Tetriminos : Name %s : Error\n", element->tetri_name);
      element = element->next;
    }
}
