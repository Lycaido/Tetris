/*
** add_line.c for tetris in /home/Rev/PSU_2016_tetris/bonus
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Sat Mar	18 15:10:01 2017 Roméo Nahon
** Last update	Sat Mar	18 15:10:01 2017 Roméo Nahon
*/

#include "include/tetris.h"

void	erase_line_(t_tetris *tetris, t_tetri_list *tetriminos, int y)
{
	int pos_y;
	int pos_x;
	int color;

	pos_y = y;
	while ((pos_y) > 1) /*pour aller tout en haut - 1*/
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
}

int		start_erase_(t_tetris *tetris, t_tetri_list *tetriminos, int erase, int y)
{
	static int nb_line_erase = 1;

	if (erase == 0)
	{
		erase_line_(tetris, tetriminos, y);
		if (nb_line_erase == 10)
			tetris->count->speed -= 1;
		nb_line_erase += 1;
		if (tetris->count->speed <= 1)
		{
			tetris->count->speed = 1;
			nb_line_erase = 1;
		}
		tetris->score->play += 100;
	}
}

int		check_line_(t_tetris *tetris, t_tetri_list *tetriminos, int y_pos)
{
	int		pos;
	int		y;
	int		erase;
	char	*size_to_get;

	y = -1;
	while (++y < tetriminos->size)
	{
		pos = 2;
		erase = 0;
		while (pos <= MAX_SIZE_X)
		{
			if ((mvwinch(GAME_BOX, y + y_pos, pos) & A_CHARTEXT) != 'O')
				erase = 1;
			pos++;
		}
		start_erase_(tetris, tetriminos, erase, y_pos);
	}
	return (0);
}

/*fonction pour reseau*/
/*line sert a envoyer plusieurs ligne en fonction du nombre de ligne retiré en même temps*/
int		create_line_reseau(t_tetris *tetris, t_tetri_list *tetriminos, int line)
{
  int x;
  int y;

  if (line == 0)
    return (1);
  while (line > 0)
    {
      x = 1;
      while (++x <= 39)
	{
	  y = 1;
	  while ((mvwinch(GAME_BOX, y, x) & A_CHARTEXT) != 'O' && y < 30)
	    {
	      if ((mvwinch(GAME_BOX, y + 1, x) & A_CHARTEXT) == 'O' || y == 28)
		{
		  wattron(GAME_BOX, COLOR_PAIR(1));
		  mvwprintw(GAME_BOX, y, x, "O");
		  wattroff(GAME_BOX, COLOR_PAIR(1));
		}
	       check_line_(tetris, tetriminos, y);
	      y += 1;
	    }
	}
      line -= 1;
    }
  return (0);
}
/*fin fonction pour reseau*/
