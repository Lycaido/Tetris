/*
** next_tetri.c for next_tetri in /home/mistralaix/delivery/project/tetris/PSU_2016_tetris
** 
** Made by cyril chaillan
** Login   <mistralaix@epitech.net>
** 
** Started on  Fri Mar 10 12:28:18 2017 cyril chaillan
** Last update Sat Mar 18 20:25:12 2017 cyril chaillan
*/

#include "include/tetris.h"

void	draw_next(t_tetris *tetris, t_tetri_list *tetriminos, int nx, int ny)
{
  int	y;
  int	x;

  y = -1;
  while (++y < tetriminos->size)
    {
      x = -1;
      while (++x < tetriminos->size)
	{
	  if (tetriminos->jeu[y][x] == 1)
	    {
	      wattron(tetris->window->frame_game_box,
		      COLOR_PAIR(tetriminos->tetri_color));
	      mvwprintw(tetris->window->frame_game_box, ny + y, nx + x, "*");
	      wattroff(tetris->window->frame_game_box,
		       COLOR_PAIR(tetriminos->tetri_color));
	    }
	}
    }
}

void	my_clear_next(t_tetris *tetris)
{
  int	x;
  int	y;

  y = 3;
  while (++y < 16)
    {
      x = 75;
      while (++x < 105)
	mvwprintw(tetris->window->frame_game_box, y, x, " ");
    }
}

void	aff_next(t_tetris *tetris, t_tetri_list *tetriminos)
{
  int	x;

  x = 90 - tetriminos->tetri_size_only;
  wattroff(tetris->window->frame_game_box, COLOR_PAIR(1));
  my_clear_next(tetris);
  wattron(tetris->window->frame_game_box, A_BOLD);
  mvwprintw(tetris->window->frame_game_box, 3, 88, "Next");
  wattroff(tetris->window->frame_game_box, A_BOLD);
  draw_next(tetris, tetriminos, x, 6);
  wrefresh(tetris->window->frame_game_box);
}

void	aff_level(t_tetris *tetris)
{
  int	r;

  r = 6 - tetris->count->speed;
  wattroff(tetris->window->frame_game_box, COLOR_PAIR(1));
  mvwprintw(tetris->window->frame_game_box, 5, 13, " ");
  wattron(tetris->window->frame_game_box, A_BOLD);
  mvwprintw(tetris->window->frame_game_box, 3, 14, "Level");
  mvwprintw(tetris->window->frame_game_box, 5, 16, "%d", r);
  wattroff(tetris->window->frame_game_box, A_BOLD);
  wrefresh(tetris->window->frame_game_box);
}

void	aff_score(t_tetris *tetris)
{
  int	x;

  x = 8;
  wattroff(tetris->window->frame_game_box, COLOR_PAIR(1));
  while (++x < 15)
    mvwprintw(tetris->window->frame_game_box, 16, x, " ");
  x = 6;
  while (++x < 15)
    mvwprintw(tetris->window->frame_game_box, 18, x, " ");
  wattron(tetris->window->frame_game_box, A_BOLD);
  mvwprintw(tetris->window->frame_game_box, 12, 10,
	    "Score : %s", tetris->score->name);
  mvwprintw(tetris->window->frame_game_box, 14, 17,
	    "%d", tetris->score->play);
  mvwprintw(tetris->window->frame_game_box, 21, 7,
	    "High Score : %s", tetris->score->file);
  mvwprintw(tetris->window->frame_game_box, 23, 15, "%d",
	    tetris->score->high);
  wattroff(tetris->window->frame_game_box, A_BOLD);
  wrefresh(tetris->window->frame_game_box);
}
