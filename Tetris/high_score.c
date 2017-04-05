/*
** high_score.c for tetris in /home/Rev/PSU_2016_tetris/bonus
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Fri Mar	17 15:40:29 2017 Roméo Nahon
** Last update	Fri Mar	17 15:40:29 2017 Roméo Nahon
*/

#include "include/tetris.h"

void	erase_screen_score(t_tetris *tetris)
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
		}
	}
}

char	*score_file(t_tetris *tetris)
{
	int		fd;
	char	*buffer;

	erase_screen_score(tetris);
	if ((fd = open("score.tetris", O_RDONLY)) < 0)
		exit(84);
	if ((buffer = malloc(sizeof(char) * 200)) == NULL)
		exit(84);
	my_memset(buffer, '\0', 200);
	if ((read(fd, buffer, 200)) < 0)
		exit(84);
	return (buffer);
}

void	disp(t_tetris *tetris, int *x)
{
	wattroff(GAME_BOX, COLOR_PAIR(9) | A_BOLD);
	wrefresh(GAME_BOX);
	usleep(60000);
	*x += 1;
}

int	init_sc(int start, int *x, int *y, int i)
{
	*x = start / 2 - 5;
	*y = 2;
	i = -1;
	return (i);
}
void	display_score(t_tetris *tetris)
{
	int 	x;
	int 	y;
	int 	start;
	int 	i;
	char	*buffer;

	i = 0;
	buffer = score_file(tetris);
	getmaxyx(GAME_BOX, y, start);
	i = init_sc(start, &x, &y, i);
	wattron(GAME_BOX, A_BOLD);
	while (buffer[++i] && y < 28)
	{
		if (buffer[i] == '\n')
		{
			i += 1;
			y += 2;
			x = start / 2 - 5;
		}
		if (buffer[i] >= '0' && buffer[i] <= '9')
			wattron(GAME_BOX, COLOR_PAIR(9) | A_BOLD);
		mvwprintw(GAME_BOX, y, x, "%c", buffer[i]);
		disp(tetris, &x);
	}
	wattroff(GAME_BOX, A_BOLD);
}
