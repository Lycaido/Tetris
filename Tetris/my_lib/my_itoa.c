/*
** my_itoa.c for libmy in /home/Rev/PSU_2016_my_printf
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Sun Nov	13 09:44:06 2016 Roméo Nahon
** Last update	Sun Nov	13 09:44:06 2016 Roméo Nahon
*/

#include "my.h"

char 	*my_itoa(int nb, char *res)
{
  int i;

  i = 0;
  while (0 < nb)
    {
      res[i] = (nb % 10) + 48;
      nb = nb / 10;
      i += 1;
    }
  return (my_revstr(res));
}
