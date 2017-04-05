/*
** my_printf_flag.c for my_printf in /home/Rev/PSU_2016_my_printf
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Thu Nov	17 15:00:55 2016 Roméo Nahon
** Last update	Thu Nov	17 15:00:55 2016 Roméo Nahon
*/

#include "my.h"

int 			 positiv_int(va_list ap, char *str, t_printf *print)
{
	unsigned int u;
	int 		 y;

	y = 0;
	u = va_arg(ap, unsigned int);
	if (str[print->i] >= '0' && str[print->i] <= '9')
	{
		y += weight_n(u, str, print);
		while (str[print->i] >= '0' && str[print->i] <= '9')
		print->i += 1;
	}
	if (str[print->i] == 'u')
		my_put_nbr_unsigned(u);
	return (my_intlen(u) + y);
}

int 		flag_hexa(char *str, t_printf *print)
{
	if (str[print->i] == '#')
	{
		my_putstr("0x");
		print->i += 1;	
	}
	return (print->i);
}

int 		flag_hexa_capital(char *str, t_printf *print)
{
	if (str[print->i] == '#')
	{
		my_putstr("0X");
		print->i += 1;	
	}
	return (print->i);
}

int 		flag_oct(char *str, t_printf *print)
{
	if (str[print->i] == '#')
	{
		my_putchar('0');
		print->i += 1;
	}
	return (print->i);
}
int 		display_adress_next(unsigned int nb)
{
	if (nb == 0)
	{
		my_putstr("(nil)");
		return (5);
	}
	return (0);
}