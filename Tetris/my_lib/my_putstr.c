/*
** my_putstr.c for my_putstr in /home/Rev/CPool_Day04
** 
** Made by Roméo Nahon
** Login   <Rev@epitech.net>
** 
** Started on  Thu Oct  6 12:30:06 2016 Roméo Nahon
** Last update Tue Oct 25 19:43:25 2016 Roméo Nahon
*/

#include "my.h"

int	my_putstr(char	*str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}
