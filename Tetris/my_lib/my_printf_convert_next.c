/*
** convert_next.c for my_printf in /home/Rev/PSU_2016_my_printf
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>s
** 
** Started on	Tue Nov	8 15:11:41 2016 Roméo Nahon
** Last update	Tue Nov	8 15:11:41 2016 Roméo Nahon
*/


#include "my.h"

char  	*conv_dec_bin_other(char *str, t_printf *print, int nb)
{
	int 	j;
	int		divs;
	char	base[] = "01";
	char 	*res;

	if ((res = malloc(sizeof(char))) == NULL)
		return (NULL);
	j = 0;
	if (str[print->i] == 'b')
	{
		divs = nb;
		while (divs > 0)
		{
			divs = divs / 2;
			nb = nb % 2;
			res[j] = base[nb];
			j += 1;
			nb = divs;
		}
		my_putstr(my_revstr(res));
	}
	return (res);
}

char 	*conv_hexa_dec_other(unsigned int nb, char *res)
{
	int 			j;
	unsigned int	divs;
	char 			base[] = "0123456789abcdef";

	j = -1;
	divs = nb;
	while (divs > 0)
	{
		divs = divs / 16;
		nb = nb % 16;
		res[++j] = base[nb];
		nb = divs;
	}
	return (res);
}
char 	*conv_hexa_dec_capital_other(unsigned int nb, char *res)
{
	int 			j;
	unsigned int	divs;
	char 			base[] = "0123456789ABCDEF";

	j = -1;
	divs = nb;
	while (divs > 0)
	{
		divs = divs / 16;
		nb = nb % 16;
		res[++j] = base[nb];
		nb = divs;
	}
	return (res);
}
char 	*display_adress_other(unsigned int nb, char *res)
{
	int 			j;
	unsigned int	divs;
	char 			base[] = "0123456789abcdef";

	j = -1;
	divs = nb;
	while (divs > 0)
	{
		divs = divs / 16;
		nb = nb % 16;
		res[++j] = base[nb];
		nb = divs;
	}
	return (res);
}

char 	*conv_dec_oct_other(unsigned int nb, char *res)
{
	int 			j;
	unsigned int	divs;

	j = -1;
	divs = nb;
	while (divs > 0)
	{
		divs = divs / 8;
		nb = nb % 8;
		res[++j] = nb + 48;
		nb = divs;
	}
	return (res);
}