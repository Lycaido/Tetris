/*
** menu_next_2.c for tetris in /home/Rev/PSU_2016_tetris/test_tetris_ncurses
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Fri Mar	10 11:39:11 2017 Roméo Nahon
** Last update	Fri Mar	10 11:39:11 2017 Roméo Nahon
*/

#include "include/tetris.h"

void	display_quit(t_tetris *tetris)
{
	wattron(GAME_BOX, COLOR_PAIR(10));
	mvwprintw(GAME_BOX, 24, 14, "***");
	mvwprintw(GAME_BOX, 25, 14, "***");
	mvwprintw(GAME_BOX, 26, 16, "*");
	wattron(GAME_BOX, COLOR_PAIR(12));
	mvwprintw(GAME_BOX, 24, 18, "*");
	mvwprintw(GAME_BOX, 24, 20, "*");
	mvwprintw(GAME_BOX, 25, 18, "*");
	mvwprintw(GAME_BOX, 25, 20, "*");
	mvwprintw(GAME_BOX, 26, 18, "***");
	wattron(GAME_BOX, COLOR_PAIR(10));
	mvwprintw(GAME_BOX, 24, 22, "*");
	mvwprintw(GAME_BOX, 25, 22, "*");
	mvwprintw(GAME_BOX, 26, 22, "*");
	wattron(GAME_BOX, COLOR_PAIR(12));
	mvwprintw(GAME_BOX, 24, 24, "***");
	mvwprintw(GAME_BOX, 25, 25, "*");
	mvwprintw(GAME_BOX, 26, 25, "*");
	wattroff(GAME_BOX, COLOR_PAIR(14));
}

void	start_game_now(t_tetris *tetris, WINDOW *enter_name)
{
	erase_screen_score(tetris);
	enter_name = subwin(stdscr, 3, 30, LINES / 2 - 1, COLS / 2 - 15);
	wattron(enter_name, COLOR_PAIR(9));
	box(enter_name, 0, 0);
	wattroff(enter_name, COLOR_PAIR(9));
	echo();
	mvwprintw(enter_name, 1, 1, "%s", "Enter name: ");
	wgetnstr(enter_name, tetris->score->name, 10);
	noecho();
	refresh();
	switch_screen(tetris);
}
void	all_option(t_tetris *tetris, int ch, int i, int *start)
{
	WINDOW	*enter_name;

	if (ch == '\n')
	{
		if (i == 0)
		{
			start_game_now(tetris, enter_name);
			*start = 1;
		}
		if (i == 1)
		{
			display_score(tetris);
			wgetch(GAME_BOX);
			erase_screen_score(tetris);
			*start = 0;
		}
		if (i == 2)
		{
			switch_screen(tetris);
			endwin();
			my_printf("A très bientot !\n");
			free(tetris);
			exit(0);
		}
	}
}
