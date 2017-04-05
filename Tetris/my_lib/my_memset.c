/*
** my_memset.c for my_lib in /home/Rev/my_lib
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Sun Jan	22 10:19:48 2017 Roméo Nahon
** Last update	Sun Jan	22 10:19:48 2017 Roméo Nahon
*/

#include "my.h"

char	*my_memset(char* str, char filled, int nb)
{
  int	i;

  i = -1;
  while (++i < nb)
    str[i] = '\0';
  return (str);
}
