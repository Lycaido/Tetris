/*
** tetri_in_game.c for tetris in /home/Rev/PSU_2016_tetris/test_tetris_ncurses
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Tue Feb	28 17:18:56 2017 Roméo Nahon
** Last update	Wed Mar	1 11:47:19 2017 Roméo Nahon
*/

#include "include/tetris.h"

void	transform_forme(t_tetris* tetris, t_tetri_list *tetriminos)
{
  int	x;
  int	y;

  y = -1;
  while (++y < tetriminos->size)
    {
      x = -1;
      while (++x < tetriminos->size)
	{
	  if (tetriminos->jeu[y][x] == 1)
	    {
	      if (CHECK_Y == '-' || CHECK_Y == 'O' ||
		  mvwinch(GAME_BOX, tetris->count->y + y + 1,
			  tetris->count->x + x) == '-' ||
		  tetris->count->y + y + 1 == 29)
		{
		  replace_start(tetriminos, tetris);
		  x = tetriminos->size;
		  y = tetriminos->size;
		  tetris->count->collision = 1;
		}
	    }
	}
    }
}

void	tetri_collision(t_tetris *tetris, t_tetri_list *tetriminos)
{
  transform_forme(tetris, tetriminos);
  if (tetris->count->y == 29 || tetris->count->collision == 1)
    {
      if (tetris->count->y == 1)
	{
	  recup_score(tetris);
	  lost_screen(tetris);
	  play_tetris(tetris);
	}
      destroy_line(tetris, tetriminos);
      tetris->count->x = rand() % (MAX_SIZE_X - 1) + 1;
      tetris->count->y = 1;
      tetris->count->i = 0;
      tetris->count->a = 0;
      tetris->count->c = 0;
      tetris->count->start = 1;
      tetris->count->collision = 0;
    }
}

t_tetri_list	*select_tetrimino_to_disp(t_tetris *tetris)
{
  t_tetri_list	*elem;
  t_tetri_list	*selected;
  int		nb_elem;
  int		random_select;
  time_t	time_;

  srand((unsigned)time(&time_));
  nb_elem = 0;
  tetris->count->sel = -1;
  elem = tetris->list->first;
  while (elem)
    {
      elem = elem->next;
      nb_elem += 1;
    }
  random_select = rand() % nb_elem;
  elem = tetris->list->first;
  while (++tetris->count->sel <= random_select && elem->next != NULL)
    {
      elem = elem->next;
      if (elem->tetri_error == 0)
	selected = elem;
    }
  check_size_to_disp(tetris, elem);
  return (selected);
}

void	display_tetri_in_game(t_tetris *tetris, t_tetri_list *tetriminos)
{
  wattroff(tetris->window->game_box, COLOR_PAIR(1));
  erase_forme(tetris, tetriminos);
  draw_forme(tetris, tetriminos);
  drop(tetris, tetriminos, 2);
  drop(tetris, tetriminos, 3);
}

t_tetri_list	*create_tetrimino_in_game(t_tetris *tetris,
					  t_tetri_list *tetriminos, int ch)
{
  if (tetris->count->start == 1)
    {
      tetriminos = tetris->stock;
      tetris->stock = select_tetrimino_to_disp(tetris);
      aff_next(tetris, tetris->stock);
      aff_level(tetris);
      aff_score(tetris);
      tetris->count->start = 0;
    }
  tetri_move(tetriminos, ch, tetris);
  display_tetri_in_game(tetris, tetriminos);
  tetri_collision(tetris, tetriminos);
  return (tetriminos);
}
