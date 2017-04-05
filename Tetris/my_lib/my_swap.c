/*
** my_swap.c for my_swap in /home/Rev/CPool_Day04
** 
** Made by Roméo Nahon
** Login   <Rev@epitech.net>
** 
** Started on  Thu Oct  6 10:01:11 2016 Roméo Nahon
** Last update Tue Nov  1 15:49:05 2016 Roméo Nahon
*/

#include "my.h"

void	my_swap(int a, int b)
{
  int	swap;

  swap = a;
  a = b;
  b = swap;
}
