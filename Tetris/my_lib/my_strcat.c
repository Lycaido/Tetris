/*
** my_strcat.c for my_strcat in /home/Rev/CPool_Day07
** 
** Made by Roméo Nahon
** Login   <Rev@epitech.net>
** 
** Started on  Tue Oct 11 10:09:45 2016 Roméo Nahon
** Last update Wed Oct 26 17:09:01 2016 Roméo Nahon
*/

#include "my.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	len;

  len = my_strlen(dest);
  i = 0;
  while (src[i] != '\0')
    {
      dest[len + i] = src[i];
      i += 1;
    }
  dest[len + i] = '\0';
  return (dest);
}
