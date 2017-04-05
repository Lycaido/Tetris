/*
** main.c for main in /home/mistralaix/delivery/project/tetris/PSU_2016_tetris
** 
** Made by cyril chaillan
** Login   <mistralaix@epitech.net>
** 
** Started on  Thu Feb 23 14:18:59 2017 cyril chaillan
** Last update Wed Mar 22 23:29:45 2017 cyril chaillan
*/

#include "include/tetris.h"
#include <curses.h>
#include <term.h>

struct termios	init_ioctl()
{
  struct termios	term;
  struct termios	old;

  if (ioctl(0, TCGETS, &old) != 0)
    exit(84);
  term = old;
  term.c_lflag &= ~(ECHO | ICANON);
  term.c_cc[VMIN] = 1;
  term.c_cc[VTIME] = 0;
  if (ioctl(0, TCSETS, &term) != 0)
    exit(84);
  return (old);
}

char	*my_term(char **env)
{
  int	i;
  int	j;

  i = -1;
  j = -1;
  while (env[++i])
    {
      if ((my_strmod(env[i], "TERM=")) == 0)
	{
	  while (env[i][++j] != '=');
	  return (&env[i][j + 1]);
	}
    }
  return (NULL);
}

char	**recup_touche(char **env)
{
  int	lol;
  char	*term;
  char	**arr;

  arr = malloc(sizeof(char*) * 5);
  term = my_term(env);
  if ((setupterm(term, 0, &lol)) == ERR)
    exit(84);
  arr[0] = tigetstr("kcuu1");
  arr[1] = tigetstr("kcub1");
  arr[2] = tigetstr("kcuf1");
  arr[3] = tigetstr("kcud1");
  arr[4] = NULL;
  return (arr);
}

void	go_ncurses(t_tetris *tetris)
{
  initscr();
  start_color();
  init_my_color();
  curs_set(0);
  keypad(stdscr, TRUE);
  cbreak();
  play_tetris(tetris);
  refresh();
  endwin();
}

int			main(int ac, char **av, char **env)
{
  t_tetris		*tetris;
  struct termios	old;
  char			**arr;
  char			c[1];

  if ((tetris = malloc(sizeof(*tetris))) == NULL)
    return (84);
  if ((init_struct(tetris, env)) == 84)
    return (84);
  tetris->list = tri_list(redimension_tab(list_tetriminos(tetris), tetris));
  get_key_base(tetris);
  tetris->key->debug = 0;
  arr = recup_touche(env);
  my_key(arr, tetris);
  if (my_parsing(ac, av, tetris) == 84)
    return (84);
  if (tetris->key->debug == 1 && tetris->doub[9] == 0)
    {
      old = init_ioctl();
      read(0, c, 1);
      if (ioctl(0, TCSETS, &old) != 0)
	exit(84);
    }
  if (tetris->list)
    go_ncurses(tetris);
  return (0);
}
