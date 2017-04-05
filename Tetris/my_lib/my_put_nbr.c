/*
** my_putnbr.c for my_putnbr in /home/Rev/CPool_Day04
** 
** Made by Roméo Nahon
** Login   <Rev@epitech.net>
** 
** Started on  Fri Oct  7 11:42:37 2016 Roméo Nahon
** Last update Thu Oct 27 10:21:33 2016 Roméo Nahon
*/

#include "my.h"

int	my_put_nbr(int nb)
{
  int modulo;

  modulo = 0;
  if (nb <= 9 && nb >= 0)
    my_putchar(nb + '0');
  if (nb < 0)
  {
    my_putchar('-');
    nb = nb * (- 1);
    if (nb <= 9 && nb >=0)
      my_put_nbr(nb);
  }
  if (nb > 9)
  {
    modulo = nb % 10;
    my_put_nbr(nb / 10);
    my_putchar(modulo + '0');
  }
}
