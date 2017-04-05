/*
** my_intlen.c for libmy.a in /home/Rev/PSU_2016_my_printf
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Wed Nov	9 13:20:27 2016 Roméo Nahon
** Last update	Wed Nov	9 13:20:27 2016 Roméo Nahon
*/

#include "my.h"

int	my_intlen(int nb)
{
  int 	len;
  int 	divs;

  divs = 1;
  len = 0;
  if (nb < 0)
    {
      nb = nb * -1;
      len += 1;
    }
  while (nb > divs)
    {
      divs = divs * 10;
      len += 1;
    }
  return (len);
}
