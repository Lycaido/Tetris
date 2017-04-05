/*
** my_strdup.c for my_strdup in /home/Rev/CPool_Day08
** 
** Made by Roméo Nahon
** Login   <Rev@epitech.net>
** 
** Started on  Wed Oct 12 09:45:19 2016 Roméo Nahon
** Last update Tue Oct 25 19:46:42 2016 Roméo Nahon
*/

#include "my.h"

char	*my_strdup(char *src)
{
  char	*str;
  int	len;
  int	i;

  len = my_strlen(src);
  if ((str = malloc(sizeof(char) * (len + 1))) == NULL)
    return (NULL);
  i = 0;
  while (src[i] != '\0')
    {
      str[i] = src[i];
      i += 1;
    }
  str[i] = '\0';
  return (str);
}
