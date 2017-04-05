/*
** destroy_line.c for tetris in /home/Rev/PSU_2016_tetris/test_tetris_ncurses
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Wed Mar	8 19:15:42 2017 Roméo Nahon
** Last update	Wed Mar	8 19:15:42 2017 Roméo Nahon
*/

#include "include/tetris.h"

char	*get_size(t_tetri_list *tetriminos)
{
  int	i;
  int j;
  char *size_to_get;

  if ((size_to_get = malloc(sizeof(char) * 3)) == NULL)
    exit(84);
  size_to_get = my_memset(size_to_get, '\0', 3);
  i = -1;
  j = 0;
  while (tetriminos->tetri_size[++i] != '*');
  while (tetriminos->tetri_size[++i] != '\0')
    {
      size_to_get[j] = tetriminos->tetri_size[i];
      j += 1;
    }
  return (size_to_get);
}

void	erase_line(t_tetris *tetris, t_tetri_list *tetriminos, int y)
{
  int pos_y;
  int pos_x;
  int color;
  char *size_to_get;

  size_to_get = get_size(tetriminos);
  pos_y = tetris->count->y + y;
  while ((pos_y) > 1)
    {
      pos_x = 0;
      while (++pos_x <= MAX_SIZE_X)
	{
	  color = (mvwinch(GAME_BOX, pos_y - 1, pos_x) & A_COLOR);
	  wattron(GAME_BOX, color);
	  mvwprintw(GAME_BOX, pos_y, pos_x, "%c",
		    (mvwinch(GAME_BOX, pos_y - 1, pos_x)));
	  wattroff(GAME_BOX, color);
	}
      pos_y--;
    }
  free(size_to_get);
}

void		start_erase(t_tetris *tetris, t_tetri_list *tetriminos,
			    int erase, int y)
{
  static int nb_line_erase = 1;

  if (erase == 0)
    {
      erase_line(tetris, tetriminos, y);
      if (nb_line_erase == 10)
	{
	  nb_line_erase = 1;
	  tetris->count->speed -= 1;
	}
      nb_line_erase += 1;
      if (tetris->count->speed <= 1)
	{
	  tetris->count->speed = 1;
	  nb_line_erase = 1;
	}
      ++tetris->score->lines;
      completed_lines(tetris);
      tetris->score->play += 100;
    }
}

int		check_line(t_tetris *tetris, t_tetri_list *tetriminos)
{
  int		pos;
  int		y;
  int		erase;
  char	*size_to_get;

  size_to_get = get_size(tetriminos);
  y = -1;
  while (++y < tetriminos->size)
    {
      pos = 2;
      erase = 0;
      while (pos <= MAX_SIZE_X)
	{
	  if ((mvwinch(GAME_BOX, y + tetris->count->y, pos) & A_CHARTEXT) != 'O')
	    erase = 1;
	  pos++;
	}
      start_erase(tetris, tetriminos, erase, y);
    }
  free(size_to_get);
  return (0);
}

void	destroy_line(t_tetris *tetris, t_tetri_list *tetriminos)
{
  check_line(tetris, tetriminos);
}
