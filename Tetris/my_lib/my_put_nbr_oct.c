/*
** my_put_nbr_oct.c for mylib in /home/Rev/PSU_2016_my_printf
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Fri Nov	11 13:43:32 2016 Roméo Nahon
** Last update	Fri Nov	11 13:43:32 2016 Roméo Nahon
*/

#include "my.h"

int 	my_put_nbr_oct(char nb)
{
	char 	*res;
	int 	i;
	int		divs;

	if ((res = malloc(sizeof(char) * my_intlen(nb))) == NULL)
		return (-1);
	i = 0;
	divs = nb;
	while (divs > 0)
	{
		divs = divs / 8;
		nb = nb % 8;
		res[i] = nb + 48;
		nb = divs;
		i += 1;
	}
	my_putstr(my_revstr(res));
	return (i);
}