/*
** base.c for my_lib in /home/Rev/my_lib
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Wed Feb	1 13:35:09 2017 Roméo Nahon
** Last update	Wed Feb	1 13:35:09 2017 Roméo Nahon
*/

#include "my.h"

char *binary(int nb)
{
  int   j;
  int   divs;
  char  base[] = "01";
  char  *res;

  if ((res = malloc(sizeof(char) * my_intlen(nb))) == NULL)
    return (NULL);
  j = 0;
  divs = nb;
  while (divs > 0)
  {
    divs = divs / 2;
    nb = nb % 2;
    res[j] = base[nb];
    j += 1;
    nb = divs;
  }
  my_revstr(res);
  return (res);
}

int  decimal(char *str)
{
  int i;
  int nb;
  int n;
  int n_pow;

  n = 0;
  i = -1;
  nb = 0;
  str = my_revstr(str);
  while (str[++i])
  {
    n_pow = my_power_it(2, n);
    nb += (str[i] - 48) * n_pow;
    n += 1;
  }
  return (nb);
}