/*
** moove_tetri.c for moove_tetri in /home/mistralaix/delivery/project/tetris/PSU_2016_tetris
** 
** Made by cyril chaillan
** Login   <mistralaix@epitech.net>
** 
** Started on  Sat Mar 18 18:30:22 2017 cyril chaillan
** Last update Sun Mar 19 22:19:31 2017 cyril chaillan
*/

#include "include/tetris.h"

void	press_up(t_tetris *tetris, t_tetri_list *tetriminos, int opt)
{
  if (opt == 1)
    tetris->pr = 0;
  erase_forme(tetris, tetriminos);
  erase_forme_to_move(tetris, tetriminos);
  drop(tetris, tetriminos, 2);
  tetriminos->tetri_forme = rotate(tetriminos->tetri_forme,
				   tetriminos->tetri_size_only);
  swap_size(tetriminos);
  tetriminos->jeu = create_int(tetriminos->tetri_forme, &tetriminos->size,
			       tetriminos->tetri_size_only);
  erase_forme(tetris, tetriminos);
  draw_forme(tetris, tetriminos);
}

void	press_side(t_tetris *tetris, t_tetri_list *tetriminos,
		   int opt, int pr)
{
  if (pr == 1)
    tetris->pr = 0;
  if (opt == 1)
    {
      drop(tetris, tetriminos, 2);
      erase_forme_to_move(tetris, tetriminos);
      T_POS_X -= 2;
    }
  else if (opt == 2)
    {
      drop(tetris, tetriminos, 2);
      erase_forme_to_move(tetris, tetriminos);
      T_POS_X += 2;
    }
}

void	press_rotate_drop(t_tetris *tetris, t_tetri_list *tetriminos, int ch)
{
  if (0 < tetris->key->touches[2][0] && tetris->key->touches[2][0] < 32)
    {
      if (ch == KEY_UP && check_to_move_left(tetriminos, tetris) == 0 &&
	  check_to_move_right(tetriminos, tetris) == 0)
        press_up(tetris, tetriminos, 0);
    }
  else if (my_strcmp(tetris->press, tetris->key->touches[2]) == 0 &&
	   check_to_move_left(tetriminos, tetris) == 0 &&
	   check_to_move_right(tetriminos, tetris) == 0)
    press_up(tetris, tetriminos, 1);
  if (0 < tetris->key->touches[3][0] && tetris->key->touches[3][0] < 32)
    {
      if (ch == KEY_DOWN)
        drop(tetris, tetriminos, 1);
    }
  else if (my_strcmp(tetris->press, tetris->key->touches[3]) == 0)
    {
      tetris->pr = 0;
      drop(tetris, tetriminos, 1);
    }
}

void	press_lr(t_tetris *tetris, t_tetri_list *tetriminos, int ch)
{
  if (0 < tetris->key->touches[0][0] && tetris->key->touches[0][0] < 32)
    {
      if (ch == KEY_LEFT && check_to_move_left(tetriminos, tetris) == 0)
        press_side(tetris, tetriminos, 1, 0);
    }
  else if (my_strcmp(tetris->press, tetris->key->touches[0]) == 0 &&
	   check_to_move_left(tetriminos, tetris) == 0)
    press_side(tetris, tetriminos, 1, 1);
  if (0 < tetris->key->touches[1][0] && tetris->key->touches[1][0] < 32)
    {
      if (ch == KEY_RIGHT && check_to_move_right(tetriminos, tetris) == 0)
        press_side(tetris, tetriminos, 2, 0);
    }
  else if (my_strcmp(tetris->press, tetris->key->touches[1]) == 0 &&
	   check_to_move_right(tetriminos, tetris) == 0)
    press_side(tetris, tetriminos, 2, 1);
}

void	tetri_move(t_tetri_list *tetriminos, int ch, t_tetris *tetris)
{
  wattroff(GAME_BOX, COLOR_PAIR(1));
  press_rotate_drop(tetris, tetriminos, ch);
  press_lr(tetris, tetriminos, ch);
  if (my_strcmp(tetris->press, tetris->key->touches[5]) == 0)
    {
      tetris->pr = 0;
      while ((ch = getch()) != '\n');
    }
  if (my_strcmp(tetris->press, tetris->key->touches[4]) == 0)
    quit_game(tetris);
}
