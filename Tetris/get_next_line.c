/*
** main.c for main in /home/mistralaix/delivery/project/get_next_line/CPE_2017_getnextline
** 
** Made by cyril chaillan
** Login   <mistralaix@epitech.net>
** 
** Started on  Mon Jan  2 20:20:02 2017 cyril chaillan
** Last update Fri Mar 10 23:56:42 2017 cyril chaillan
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include "include/tetris.h"

char	*end_of_text(char *str, int j)
{
  if (j > -1)
    return (str);
  return (NULL);
}

char	*get_next_line(const int fd)
{
  static char	buff[READ_SIZE];
  static int	idx = 0;
  int		j;
  char		*str;
  int		end;

  (1) ? (j = -1) && (end = 1) : 0;
  if ((str = malloc(sizeof(char) * (1000))) == NULL)
    return (NULL);
  my_memset(str, 0, 999);
  while (end)
    {
      if (idx == 0)
	{
	  my_memset(buff, 0, READ_SIZE);
	  if ((read(fd, buff, READ_SIZE)) <= 0)
	    return (end_of_text(str, j));
	}
      while (buff[idx] != '\n' && buff[idx])
	str[++j] = buff[idx++];
      buff[idx] == '\n' ? (end = 0) : (idx = 0);
    }
  str[++j] = 0;
  ++idx;
  return (str);
}
