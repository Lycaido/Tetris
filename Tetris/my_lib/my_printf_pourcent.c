/*
** my_printf_pourcent.c for my_printf in /home/Rev/PSU_2016_my_printf
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Thu Nov	17 17:04:27 2016 Roméo Nahon
** Last update	Thu Nov	17 17:04:27 2016 Roméo Nahon
*/

#include "my.h"

int 	display_pourcent(va_list ap, char *str, t_printf *print)
{
	if (str[print->i] == '%')
	{
		print->i -= 1;
		my_putchar('%');
	}
	return (1);
}