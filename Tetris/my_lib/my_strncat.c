/*
** my_strncat.c for my_strncat in /home/Rev/CPool_Day07
** 
** Made by Roméo Nahon
** Login   <Rev@epitech.net>
** 
** Started on  Tue Oct 11 13:18:54 2016 Roméo Nahon
** Last update Wed Oct 26 17:11:08 2016 Roméo Nahon
*/

#include "my.h"

char	*my_strncat(char *dest, char *src, int nb)
{
  int	len;
  int	i;

  len = my_strlen(dest);
  i = 0;
  while (i < nb &&  src[i] != '\0')
    {
      dest[len + i] = src[i];
      i += 1;
    }
  dest[len + i] = '\0';
  return (dest);
}
