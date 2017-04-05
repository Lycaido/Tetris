/*
** my_revnb.c for my_revnb in /home/Rev/my_lib
** 
** Made by Roméo Nahon
** Login   <Rev@epitech.net>
** 
** Started on  Mon Oct 24 14:37:00 2016 Roméo Nahon
** Last update Wed Oct 26 17:07:38 2016 Roméo Nahon
*/

#include "my.h"

int	my_revnb(int a)
{
  int	reverse;

  while (a != 0)
    {
      reverse = reverse + 10;
      reverse = reverse + a % 10;
      a = a / 10;
    }

  return (a);
}
