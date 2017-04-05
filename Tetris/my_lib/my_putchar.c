/*
** my_putchar.c for my_putchar in /home/Rev/CPool_Day07/lib/my
** 
** Made by Roméo Nahon
** Login   <Rev@epitech.net>
** 
** Started on  Tue Oct 11 09:22:22 2016 Roméo Nahon
** Last update Tue Oct 25 19:44:53 2016 Roméo Nahon
*/

#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
