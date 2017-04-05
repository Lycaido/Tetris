/*
** my_puterror.c for my_puterror in /home/Rev/my_lib
** 
** Made by Roméo Nahon
** Login   <Rev@epitech.net>
** 
** Started on  Tue Oct 18 12:09:25 2016 Roméo Nahon
** Last update Wed Oct 26 17:06:57 2016 Roméo Nahon
*/

#include "my.h"

void	my_puterror(char c)
{
  write(2, &c, 1);
}
