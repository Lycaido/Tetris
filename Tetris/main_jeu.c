/*
** main.c for tetris in /home/Rev/PSU_2016_tetris/test_tetris_ncurses
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Mon Feb	27 13:34:23 2017 Roméo Nahon
** Last update	Mon Feb	27 13:34:23 2017 Roméo Nahon
*/

#include "include/tetris.h"

int	g_glob = 0;

char	*get_size_map(t_tetris *tetris)
{
  int	i;
  int	j;
  char	*size_map_x;

  if ((size_map_x = malloc(sizeof(char) * 2)) == NULL)
    exit(84);
  i = -1;
  j = 0;
  while (tetris->key->size[++i] != '*');
  while (tetris->key->size[++i] != '\0')
    {
      size_map_x[j] = tetris->key->size[i];
      j = 0;
    }
  return (size_map_x);
}

void	init_value(t_tetris *tetris)
{
  if ((tetris->window = malloc(sizeof(*(tetris->window)))) == NULL)
    exit(84);
  if ((tetris->count = malloc(sizeof(*(tetris->count)))) == NULL)
    exit(84);
  if ((tetris->map = malloc(sizeof(*(tetris->map)))) == NULL)
    exit(84);
  if ((tetris->stock = malloc(sizeof(*tetris->stock))) == NULL)
    exit(84);
  tetris->map->w_gb_x = 0 - tetris->key->width + 20;
  tetris->map->w_gb_y = 0 - tetris->key->height + 10;
  tetris->map->gb_x = 0 - tetris->key->width + 20;
  tetris->map->gb_y = 0 - tetris->key->height + 10;
  tetris->pr = 0;
  tetris->score->lines = 0;
  tetris->press = malloc(sizeof(char) * (29));
  my_memset(tetris->press, 0, 29);
  tetris->stock = select_tetrimino_to_disp(tetris);
  tetris->count->speed = 6 - tetris->key->level;
  if (tetris->count->speed < 1) tetris->count->speed = 1;
  aff_level(tetris);
}

void	get_sig()
{
  g_glob = 1;
}

void	init_imp(t_tetris *tetris, int ch)
{
  time_t	time_;

  init_value(tetris);
  srand((unsigned)time(&time_));
  create_box(tetris);
  display_box_color(tetris, tetris->count->i, ch);
  draw_everywhere();
  main_menu(tetris);
  signal(SIGINT, get_sig);
  completed_lines(tetris);
  tetris->count->x = rand() % (MAX_SIZE_X - 1) + 1;
  tetris->count->i = tetris->count->a = tetris->score->play = 0;
  tetris->count->y = tetris->count->start = 1;
  tetris->count->c = tetris->count->collision = 0;
}

int		play_tetris(t_tetris *tetris)
{
  int		ch;
  int		my_time;
  clock_t	time_;
  t_tetri_list	*tetriminos;

  time_ = 0;
  if ((tetriminos = malloc(sizeof(t_tetri_list))) == NULL) exit(84);
  tetriminos = NULL;
  ch = 0;
  init_imp(tetris, ch);
  my_time = 240;
  while (1)
    {
      check_size_term();
      tetris->key->next == 1 ? timer(time_, my_time, tetris) : 0;
      timeout(100);
      ch = getch();
      my_press(tetris, ch);
      tetris->pr = 1;
      display_box_color(tetris, tetris->count->i, ch);
      tetriminos = create_tetrimino_in_game(tetris, tetriminos, ch);
      go_down(tetris);
      if (g_glob == 1) quit_game(tetris);
      tetris->count->i++;
    }
}
