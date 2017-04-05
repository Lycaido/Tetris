/*
** my_power_it.c for my_lib in /home/Rev/my_lib
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Mon Nov	7 17:45:35 2016 Roméo Nahon
** Last update	Mon Nov	7 17:45:35 2016 Roméo Nahon
*/

#include "my.h"

int my_power_it(int nb, int p)
{
  int result;
  int power;

  result = 1;
  power = 0;
  while (power < p)
  {
    result *= nb;
    power += 1;
  }
  return (result);
}