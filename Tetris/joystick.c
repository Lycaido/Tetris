/*
** joystick.c for tetris in /home/Rev/PSU_2016_tetris/test_tetris_ncurses
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Tue Feb	28 10:14:02 2017 Roméo Nahon
** Last update	Tue Feb	28 10:14:02 2017 Roméo Nahon
*/

#include "include/tetris.h"

void	right_joystick(t_tetris *tetris)
{
  wclear(tetris->window->joystick_box);
  wattron(tetris->window->joystick_box, COLOR_PAIR(9) | A_BOLD);
  mvwprintw(tetris->window->joystick_box, 2, 24, "/---\\");
  mvwprintw(tetris->window->joystick_box, 3, 24, "\\---/");
  wattroff(tetris->window->joystick_box, COLOR_PAIR(9) | A_BOLD);
  wattron(tetris->window->joystick_box, COLOR_PAIR(12) | A_BOLD);
  mvwprintw(tetris->window->joystick_box, 4, 24, "|||");
  mvwprintw(tetris->window->joystick_box, 5, 23, "|||");
  mvwprintw(tetris->window->joystick_box, 6, 22, "|||");
  mvwprintw(tetris->window->joystick_box, 7, 21, "|||");
  mvwprintw(tetris->window->joystick_box, 8, 19, "_-----_");
  wattroff(tetris->window->joystick_box, COLOR_PAIR(12) | A_BOLD);
  wrefresh(tetris->window->joystick_box);
}

void	left_joystick(t_tetris *tetris)
{
  wclear(tetris->window->joystick_box);
  wattron(tetris->window->joystick_box, COLOR_PAIR(9) | A_BOLD);
  mvwprintw(tetris->window->joystick_box, 2, 16, "/---\\");
  mvwprintw(tetris->window->joystick_box, 3, 16, "\\---/");
  wattroff(tetris->window->joystick_box, COLOR_PAIR(9) | A_BOLD);
  wattron(tetris->window->joystick_box, COLOR_PAIR(12) | A_BOLD);
  mvwprintw(tetris->window->joystick_box, 4, 18, "|||");
  mvwprintw(tetris->window->joystick_box, 5, 19, "|||");
  mvwprintw(tetris->window->joystick_box, 6, 20, "|||");
  mvwprintw(tetris->window->joystick_box, 7, 21, "|||");
  mvwprintw(tetris->window->joystick_box, 8, 19, "_-----_");
  wattroff(tetris->window->joystick_box, COLOR_PAIR(12) | A_BOLD);
  wrefresh(tetris->window->joystick_box);
}

void	display_joysticks(t_tetris*	tetris, int ch)
{
  if (ch == KEY_RIGHT)
    right_joystick(tetris);
  else if (ch == KEY_LEFT)
    left_joystick(tetris);
  else
    {
      wclear(tetris->window->joystick_box);
      wattron(tetris->window->joystick_box, COLOR_PAIR(9) | A_BOLD);
      mvwprintw(tetris->window->joystick_box, 2, 20, "/---\\");
      mvwprintw(tetris->window->joystick_box, 3, 20, "\\---/");
      wattroff(tetris->window->joystick_box, COLOR_PAIR(9) | A_BOLD);
      wattron(tetris->window->joystick_box, COLOR_PAIR(12) | A_BOLD);
      mvwprintw(tetris->window->joystick_box, 4, 21, "|||");
      mvwprintw(tetris->window->joystick_box, 5, 21, "|||");
      mvwprintw(tetris->window->joystick_box, 6, 21, "|||");
      mvwprintw(tetris->window->joystick_box, 7, 21, "|||");
      mvwprintw(tetris->window->joystick_box, 8, 19, "_-----_");
      wattroff(tetris->window->joystick_box, COLOR_PAIR(12) | A_BOLD);
      wrefresh(tetris->window->joystick_box);
    }
}

void	push_button(t_tetris *tetris)
{
  wattron(tetris->window->joystick_box, COLOR_PAIR(10) | A_BOLD);
  mvwprintw(tetris->window->joystick_box, 3, 40, "/---\\");
  mvwprintw(tetris->window->joystick_box, 4, 40, "\\---/");
  mvwprintw(tetris->window->joystick_box, 3, 49, "\\-/");
  mvwprintw(tetris->window->joystick_box, 3, 56, "/---\\");
  mvwprintw(tetris->window->joystick_box, 4, 56, "\\---/");
  wattron(tetris->window->joystick_box, COLOR_PAIR(9) | A_BOLD);
  mvwprintw(tetris->window->joystick_box, 6, 40, "/---\\");
  mvwprintw(tetris->window->joystick_box, 7, 40, "\\---/");
  mvwprintw(tetris->window->joystick_box, 6, 48, "/---\\");
  mvwprintw(tetris->window->joystick_box, 7, 48, "\\---/");
  mvwprintw(tetris->window->joystick_box, 6, 56, "/---\\");
  mvwprintw(tetris->window->joystick_box, 7, 56, "\\---/");
}

void	display_button(t_tetris* tetris, int ch)
{
  if (ch == 'z')
    push_button(tetris);
  else
    {
      wattron(tetris->window->joystick_box, COLOR_PAIR(10) | A_BOLD);
      mvwprintw(tetris->window->joystick_box, 3, 40, "/---\\");
      mvwprintw(tetris->window->joystick_box, 4, 40, "\\---/");
      mvwprintw(tetris->window->joystick_box, 3, 48, "/---\\");
      mvwprintw(tetris->window->joystick_box, 4, 48, "\\---/");
      mvwprintw(tetris->window->joystick_box, 3, 56, "/---\\");
      mvwprintw(tetris->window->joystick_box, 4, 56, "\\---/");
      wattron(tetris->window->joystick_box, COLOR_PAIR(9) | A_BOLD);
      mvwprintw(tetris->window->joystick_box, 6, 40, "/---\\");
      mvwprintw(tetris->window->joystick_box, 7, 40, "\\---/");
      mvwprintw(tetris->window->joystick_box, 6, 48, "/---\\");
      mvwprintw(tetris->window->joystick_box, 7, 48, "\\---/");
      mvwprintw(tetris->window->joystick_box, 6, 56, "/---\\");
      mvwprintw(tetris->window->joystick_box, 7, 56, "\\---/");
    }
  wattroff(tetris->window->joystick_box, COLOR_PAIR(2) | A_BOLD);
}
