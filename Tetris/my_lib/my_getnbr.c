/*
** my_getnbr.c for my_getnbr in /home/Rev/my_lib
** 
** Made by Roméo Nahon
** Login   <Rev@epitech.net>
** 
** Started on  Fri Oct 28 15:09:39 2016 Roméo Nahon
** Last update Wed Nov  2 14:42:45 2016 Roméo Nahon
*/

#include "my.h"

int	my_getnbr(char *str)
{
  int var;
  int inv;
  int i;
  inv = 1;
  var = 0;
  i = 0;
  if (str == NULL)
    return (-42);
  while ((*str < 47 || *str > 58) && *str != 0)
  {
    str = str + 1;
    i = i + 1;
  }
  if (i > 0 && *(str - 1) == 45)
    inv = -1;
  while (*str != 0 && *str >= '0' && *str <= '9')
  {
    var = var * 10;
    var = var + *str - 48;
    str = str + 1;
  }
  var = var * inv;
  return (var);
}
