/*
** help.c for help in /home/mistralaix/delivery/project/tetris/PSU_2016_tetris
** 
** Made by cyril chaillan
** Login   <mistralaix@epitech.net>
** 
** Started on  Thu Feb 23 13:40:09 2017 cyril chaillan
** Last update Sun Mar 19 16:55:45 2017 cyril chaillan
*/

#include "include/tetris.h"

int	help(char *str)
{
  my_printf("Usage:  %s [options]\nOptions:\n", str);
  my_printf("\t--help\t\t\tDisplay this help\n\t-l --level={num}\t");
  my_printf("Start Tetris at level num (def:  1)\n\t-kl --key-left={K}\t");
  my_printf("Move the tetrimino LEFT using the K key (def:  left arrow)\n");
  my_printf("\t-kr --key-right={K}\tMove the tetrimino RIGHT using the K");
  my_printf(" key (def:  right arrow)\n\t-kt --key-turn={K}\tTURN the");
  my_printf(" tetrimino clockwise 90d using the K key (def:  top arrow)\n");
  my_printf("\t-kd --key-drop={K}\tDROP the tetrimino using the K key (def:");
  my_printf("  down arrow)\n\t-kq --key-quit={K}\tQUIT the game using");
  my_printf(" the K key (def:  'Q' key)\n\t-kp --key-pause={K}\tPAUSE/");
  my_printf("RESTART the game using the K key (def:  space bar)\n");
  my_printf("\t--map-size={row,col}\tSet the numbers of rows and columns");
  my_printf(" of the map (def:  20,10)\n\t-w --without-next\tHide next");
  my_printf(" tetrimino (def:  false)\n\t-d --debug\t\tDebug mode ");
  my_printf("(def:  false)\n");
  return (0);
}

int	check_opt(int i, int ac, char **av, t_tetris *tetris)
{
  tetris->err = 0;
  if ((i = basic_options_one(i, ac, av, tetris)) == 84)
    return (84);
  if ((i = basic_options_two(i, ac, av, tetris)) == 84)
    return (84);
  basic_options_three(i, av, tetris);
  options_one(i, av, tetris);
  options_two(i, av, tetris);
  options_three(i, av, tetris);
  opt_four(i, av, tetris);
  return (i);
}
