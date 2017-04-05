/*
** my_strerror.c for my_strerror in /home/Rev/my_lib
** 
** Made by Roméo Nahon
** Login   <Rev@epitech.net>
** 
** Started on  Tue Oct 18 12:10:10 2016 Roméo Nahon
** Last update Wed Oct 26 17:09:57 2016 Roméo Nahon
*/

#include "my.h"

int	my_strerror(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_puterror(str[i]);
      i += 1;
    }
}
