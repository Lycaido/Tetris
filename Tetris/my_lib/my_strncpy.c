/*
** my_strncpy.c for my_strncpy in /home/Rev/CPool_Day06
** 
** Made by Roméo Nahon
** Login   <Rev@epitech.net>
** 
** Started on  Mon Oct 10 13:53:32 2016 Roméo Nahon
** Last update Wed Oct 26 17:11:43 2016 Roméo Nahon
*/

#include "my.h"

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (i < n && src[i] != '\0')
    {
      dest[i] = src[i];
      i += 1;
    }
  return (dest);
}
