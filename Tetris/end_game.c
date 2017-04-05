/*
** end_game.c for tetris in /home/Rev/PSU_2016_tetris/test_tetris_ncurses
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Fri Mar	10 16:09:36 2017 Roméo Nahon
** Last update	Fri Mar	10 16:09:36 2017 Roméo Nahon
*/

#include "include/tetris.h"

void	disp_up_down(t_tetris *tetris, int i, int x, int r, int y)
{
	int j;

	j = r - 1;
	wattron(GAME_BOX, COLOR_PAIR(rand() % (1 - 8) + 1));
	while (++j < x)
	{
		mvwprintw(GAME_BOX, i - 2, j, "0");
		wrefresh(GAME_BOX);
		usleep(1000);
	}
	wattroff(GAME_BOX, COLOR_PAIR(rand() % (1 - 8) + 1));
	j = r - 1;
	wattron(GAME_BOX, COLOR_PAIR(rand() % (1 - 8) + 1));
	while (++j < x + 1)
	{
		mvwprintw(GAME_BOX, y, j, "0");
		wrefresh(GAME_BOX);
		usleep(1000);
	}
	wattroff(GAME_BOX, COLOR_PAIR(rand() % 8));
}

void	disp_right_down(t_tetris *tetris, int i, int x, int r, int y)
{
	int	j;

	j = r - 1;
	wattron(GAME_BOX, COLOR_PAIR(rand() % (1 - 8) + 1));
	while (++j < y)
	{
		mvwprintw(GAME_BOX, j, i - 1, "0");
		wrefresh(GAME_BOX);
		usleep(1000);
	}
	wattroff(GAME_BOX, COLOR_PAIR(4));
	j = r - 2;
	wattron(GAME_BOX, COLOR_PAIR(rand() % (1 - 8) + 1));
	while (++j <= y)
	{
		mvwprintw(GAME_BOX, j, x, "0");
		wrefresh(GAME_BOX);
		usleep(1000);
	}
	wattroff(GAME_BOX, COLOR_PAIR(4));
}
void	lost_screen(t_tetris *tetris)
{
	int x;
	int	y;
	int i;
	int	r;

	getmaxyx(GAME_BOX, y, x);
	i = 0;
	r = 0;
	while (++i <= y + 2)
	{
		disp_up_down(tetris, i, x, r, y);
		disp_right_down(tetris, i, x, r, y);
		r += 1;
		y -= 1;
		x -= 1;
	}
	erase_lost_screen(tetris);
}

void	erase_up_down(t_tetris *tetris, t_count count)
{
	int j;

	j = count.c - 1;
	while (++j < count.x)
	{
		wattroff(GAME_BOX, COLOR_PAIR(1));
		mvwprintw(GAME_BOX, count.i - 2, j, " ");
		wrefresh(GAME_BOX);
		usleep(1000);
	}
	j = count.c - 1;
	while (++j < count.x + 1)
	{
		wattroff(GAME_BOX, COLOR_PAIR(1));
		mvwprintw(GAME_BOX, count.y, j, " ");
		wrefresh(GAME_BOX);
		usleep(1000);
	}
}

void	erase_right_down(t_tetris *tetris, t_count count)
{
	int	j;

	j = count.c - 1;
	while (++j < count.y)
	{
		wattroff(GAME_BOX, COLOR_PAIR(4));
		mvwprintw(GAME_BOX, j, count.i - 1, " ");
		wrefresh(GAME_BOX);
		usleep(1000);
	}
	j = count.c - 2;
	while (++j <= count.y)
	{
		wattroff(GAME_BOX, COLOR_PAIR(4));
		mvwprintw(GAME_BOX, j, count.x, " ");
		wrefresh(GAME_BOX);
		usleep(1000);
	}
}

void	erase_lost_screen(t_tetris* tetris)
{
	t_count count;

	getmaxyx(GAME_BOX, count.y, count.x);
	count.i = 0;
	count.c = 0;
	while (++(count.i) <= count.y + 2)
	{
		erase_up_down(tetris, count);
		erase_right_down(tetris, count);
		count.c += 1;
		count.y -= 1;
		count.x -= 1;
	}
}
