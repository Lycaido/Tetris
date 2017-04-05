/*
** my_revstr.c for my_revstr in /home/Rev/CPool_Day07/lib/my
** 
** Made by Roméo Nahon
** Login   <Rev@epitech.net>
** 
** Started on  Tue Oct 11 09:44:48 2016 Roméo Nahon
** Last update Wed Nov  2 14:43:04 2016 Roméo Nahon
*/

#include "my.h"

char	*my_revstr(char *str)
{
  int	i;
  int	c;
  int	t;

  i = 0;
  c = 0;
  t = 0;
  while (str[c] != '\0')
    c += 1;
  c -= 1;
  while (i < c)
    {
      t = str[i];
      str[i] = str[c];
      str[c] = t;
      i += 1;
      c -= 1;
    }
  return (str);
}
