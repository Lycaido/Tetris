/*
** menu_next.c for tetris in /home/Rev/PSU_2016_tetris/test_tetris_ncurses
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Fri Mar	10 10:12:05 2017 Roméo Nahon
** Last update	Fri Mar	10 10:12:05 2017 Roméo Nahon
*/

#include "include/tetris.h"

void	display_menu_case(t_tetris *tetris, int c, int i, int j)
{
	if ((c % 2) == 1)
	{
		wattron(GAME_BOX, COLOR_PAIR(1));
		mvwprintw(GAME_BOX, i, j, "0");
		wattroff(GAME_BOX, COLOR_PAIR(1));
		wrefresh(GAME_BOX);
	}
	else
	{
		wattron(GAME_BOX, COLOR_PAIR(4));
		mvwprintw(GAME_BOX, i, j, "0");
		wattroff(GAME_BOX, COLOR_PAIR(4));
		wrefresh(GAME_BOX);
	}
}

void	erase_screen(t_tetris *tetris)
{
	int x;
	int y;
	int i;
	int j;

	getmaxyx(GAME_BOX, y, x);
	wattroff(GAME_BOX, COLOR_PAIR(1));
	i = 0;
	while (++i < y - 1)
	{
		j = 0;
		while (++j < x - 1)
		{
			mvwprintw(GAME_BOX, i, j, " ");
			wrefresh(GAME_BOX);
			usleep(1000);
		}
	}
}

void	display_play(t_tetris *tetris)
{
	wattron(GAME_BOX, COLOR_PAIR(10));
	mvwprintw(GAME_BOX, 4, 11, "***");
	mvwprintw(GAME_BOX, 5, 12, "*");
	mvwprintw(GAME_BOX, 6, 10, "***");
	wattron(GAME_BOX, COLOR_PAIR(12));
	mvwprintw(GAME_BOX, 4, 15, "***");
	mvwprintw(GAME_BOX, 5, 15, "*");
	mvwprintw(GAME_BOX, 5, 17, "*");
	mvwprintw(GAME_BOX, 6, 15, "***");
	wattron(GAME_BOX, COLOR_PAIR(10));
	mvwprintw(GAME_BOX, 4, 19, "*");
	mvwprintw(GAME_BOX, 4, 21, "*");
	mvwprintw(GAME_BOX, 5, 19, "*");
	mvwprintw(GAME_BOX, 5, 21, "*");
	mvwprintw(GAME_BOX, 6, 19, "***");
	wattron(GAME_BOX, COLOR_PAIR(12));
	mvwprintw(GAME_BOX, 4, 23, "***");
	mvwprintw(GAME_BOX, 5, 23, "**");
	mvwprintw(GAME_BOX, 6, 23, "***");
	wattron(GAME_BOX, COLOR_PAIR(10));
	mvwprintw(GAME_BOX, 4, 27, "***");
	mvwprintw(GAME_BOX, 5, 27, "***");
	mvwprintw(GAME_BOX, 6, 27, "*");
	mvwprintw(GAME_BOX, 6, 29, "**");
	wattroff(GAME_BOX, COLOR_PAIR(14));
}

void	display_high_score_next(t_tetris *tetris)
{
	mvwprintw(GAME_BOX, 17, 12, "*");
	mvwprintw(GAME_BOX, 18, 10, "***");
	wattron(GAME_BOX, COLOR_PAIR(10));
	mvwprintw(GAME_BOX, 16, 16, "***");
	mvwprintw(GAME_BOX, 17, 16, "*");
	mvwprintw(GAME_BOX, 18, 16, "***");
	wattron(GAME_BOX, COLOR_PAIR(12));
	mvwprintw(GAME_BOX, 16, 20, "***");
	mvwprintw(GAME_BOX, 17, 20, "*");
	mvwprintw(GAME_BOX, 17, 22, "*");
	mvwprintw(GAME_BOX, 18, 20, "***");
	wattron(GAME_BOX, COLOR_PAIR(12));
	mvwprintw(GAME_BOX, 16, 20, "***");
	mvwprintw(GAME_BOX, 17, 20, "*");
	mvwprintw(GAME_BOX, 17, 22, "*");
	mvwprintw(GAME_BOX, 18, 20, "***");
	wattron(GAME_BOX, COLOR_PAIR(10));
	mvwprintw(GAME_BOX, 16, 24, "***");
	mvwprintw(GAME_BOX, 17, 24, "***");
	mvwprintw(GAME_BOX, 18, 24, "*");
	mvwprintw(GAME_BOX, 18, 26, "**");
	mvwprintw(GAME_BOX, 16, 24, "***");
	mvwprintw(GAME_BOX, 17, 24, "***");
	mvwprintw(GAME_BOX, 18, 24, "*");
	mvwprintw(GAME_BOX, 18, 26, "**");
	wattron(GAME_BOX, COLOR_PAIR(12));
	mvwprintw(GAME_BOX, 16, 29, "***");
	mvwprintw(GAME_BOX, 17, 29, "**");
	mvwprintw(GAME_BOX, 18, 29, "***");
}

void	display_high_score(t_tetris *tetris)
{
	wattron(GAME_BOX, COLOR_PAIR(10));
	mvwprintw(GAME_BOX, 12, 11, "*");
	mvwprintw(GAME_BOX, 12, 13, "*");
	mvwprintw(GAME_BOX, 13, 11, "***");
	mvwprintw(GAME_BOX, 14, 11, "*");
	mvwprintw(GAME_BOX, 14, 13, "*");
	wattron(GAME_BOX, COLOR_PAIR(12));
	mvwprintw(GAME_BOX, 12, 16, "*");
	mvwprintw(GAME_BOX, 13, 16, "*");
	mvwprintw(GAME_BOX, 14, 16, "*");
	wattron(GAME_BOX, COLOR_PAIR(10));
	mvwprintw(GAME_BOX, 12, 18, "***");
	mvwprintw(GAME_BOX, 13, 18, "*");
	mvwprintw(GAME_BOX, 13, 21, "*");
	mvwprintw(GAME_BOX, 14, 18, "****");
	wattron(GAME_BOX, COLOR_PAIR(12));
	mvwprintw(GAME_BOX, 12, 24, "*");
	mvwprintw(GAME_BOX, 12, 26, "*");
	mvwprintw(GAME_BOX, 13, 24, "***");
	mvwprintw(GAME_BOX, 14, 24, "*");
	mvwprintw(GAME_BOX, 14, 26, "*");
	wattron(GAME_BOX, COLOR_PAIR(10));
	mvwprintw(GAME_BOX, 12, 28, "***");
	mvwprintw(GAME_BOX, 13, 29, "*");
	mvwprintw(GAME_BOX, 14, 29, "*");
	wattron(GAME_BOX, COLOR_PAIR(12));
	mvwprintw(GAME_BOX, 16, 12, "***");
	display_high_score_next(tetris);
	wattroff(GAME_BOX, COLOR_PAIR(14));
}