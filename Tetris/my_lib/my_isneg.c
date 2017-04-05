/*
** my_isneg.c for my_isneg in /home/Rev/CPool_Day03
** 
** Made by Roméo Nahon
** Login   <Rev@epitech.net>
** 
** Started on  Wed Oct  5 10:49:33 2016 Roméo Nahon
** Last update Wed Oct 26 17:06:10 2016 Roméo Nahon
*/

#include "my.h"

int	my_isneg(int n)
{
  char	negativ;
  char	positiv;
  int	number;

  number = n;
  positiv = 'P';
  negativ = 'N';
  if (n < 0)
    {
      my_putchar(negativ);
    }
  else if (n > 0)
    {
      my_putchar(positiv);
    }
  return (0);
}
