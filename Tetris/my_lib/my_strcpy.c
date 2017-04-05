/*
** my_strcpy.c for my_strcpy in /home/Rev/CPool_Day06
** 
** Made by Roméo Nahon
** Login   <Rev@epitech.net>
** 
** Started on  Mon Oct 10 09:23:39 2016 Roméo Nahon
** Last update Wed Oct 26 17:09:31 2016 Roméo Nahon
*/

#include "my.h"

char	*my_strcpy(char *src, char *dest)
{
  int	b;

  b = 0;
  while (src[b] != '\0')
    {
      b += 1;
      dest[b] = src[b];
    }
  return (dest);
}
