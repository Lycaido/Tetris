/*
** menu.c for tetris in /home/Rev/PSU_2016_tetris/test_tetris_ncurses
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Thu Mar	9 18:52:28 2017 Roméo Nahon
** Last update	Thu Mar	9 18:52:28 2017 Roméo Nahon
*/

#include "include/tetris.h"

void	display_option(t_tetris *tetris)
{
	wattroff(GAME_BOX, COLOR_PAIR(1));
	display_play(tetris);
	display_high_score(tetris);
	display_quit(tetris);
	wrefresh(GAME_BOX);
}

void	key_up(int *x, int *x2, int *i, t_tetris *tetris)
{
	*x -= 10;
	*x2 -= 10;
	mvwprintw(GAME_BOX, *x, 5, "->");
	mvwprintw(GAME_BOX, *x2, 34, "<-");
	mvwprintw(GAME_BOX, *x + 10, 5, "  ");
	mvwprintw(GAME_BOX, *x2 + 10, 34, "  ");
	*i -= 1;
}
void	key_down(int *x, int *x2, int *i, t_tetris *tetris)
{
	*x += 10;
	*x2 += 10;
	mvwprintw(GAME_BOX, *x, 5, "->");
	mvwprintw(GAME_BOX, *x2, 34, "<-");
	mvwprintw(GAME_BOX, *x - 10, 5, "  ");
	mvwprintw(GAME_BOX, *x2 - 10, 34, "  ");
	*i += 1;
}
void	switch_screen(t_tetris *tetris)
{
	int x;
	int y;
	int i;
	int j;
	int c;

	i = c = 0;
	getmaxyx(GAME_BOX, y, x);
	while (++i < y - 1)
	{
		j = 0;
		while (++j < x - 1)
		{
			display_menu_case(tetris, c, i, j);
			usleep(1000);
			c += 1;
		}
	}
	erase_screen(tetris);
}

void	main_menu(t_tetris *tetris)
{
	int	start;
	int	i;
	int ch;
	int x;
	int x2;
	int appear;

	appear = start = i = 0;
	x = x2 = 5;
	while (start == 0)
	{
		display_option(tetris);
		if (appear++ == 0)
		{
			mvwprintw(GAME_BOX, 5, 5, "->");
			mvwprintw(GAME_BOX, 5, 34, "<-");
		}
		ch = getch();
		all_option(tetris, ch, i, &start);
		if (ch == KEY_UP && i != 0)
			key_up(&x, &x2, &i, tetris);
		else if (ch == KEY_DOWN && i != 2)
			key_down(&x, &x2, &i, tetris);
	}
}