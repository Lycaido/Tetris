/*
** my_intoarg.c for my_lib in /home/Rev/my_lib
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Mon Jan	9 10:24:13 2017 Roméo Nahon
** Last update	Mon Jan	9 10:24:13 2017 Roméo Nahon
*/

#include "my.h"

char 	*intoarg(int nb, int lenght2)
{
	char *str;
	int lenght;
	int nb_cp;

	if (nb <= 0) 
		return (NULL);
	nb_cp = nb;
	lenght = lenght2;
	if ((str = malloc(sizeof(*str) + (lenght + 1))) == NULL)
		return (NULL);
	str[lenght] = 0;
	while (lenght > 0)
	{
		str[--lenght] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}
