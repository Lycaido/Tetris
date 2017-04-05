/*
** my_printf_next.c for my_printf in /home/Rev/PSU_2016_my_printf
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Mon Nov	14 11:11:33 2016 Roméo Nahon
** Last update	Mon Nov	14 11:11:33 2016 Roméo Nahon
*/

#include "my.h"

int 	display_oct_string_zero(char *res, int j)
{
	if (res[j] < 8)
	{
		my_putstr("\\00");
		return (3);
	}
	else if (res[j] > 8 && res[j] < 32 || res[j] >= 127)
	{
		my_putstr("\\0");
		return (2);
	}
	else
		return (0);
}

t_printf 	*my_printf_other(va_list ap, t_printf *print, char *str)
{
	if (str[print->i] == '%')
	{
		print->i += 1;
		print->x += my_printf_next(ap, str, print);
		if (str[print->i] == '+' || str[print->i] == '#')
		{
			print->i += 1;
			print->x += 1;
		}
		while (str[print->i] >= '0' && str[print->i] <= '9' || str[print->i] == 32)
			print->i += 1;
	}
	else
	{
		my_putchar(str[print->i]);
		print->x += 1;
	}
	return (print);
}

int 	display_oct_string_next(t_type type, char *str, t_printf *print)
{
	int 	j;

	j = -1;
	if (str[print->i] == 'S')
	{
		while (type.res[++j] != '\0')
		{
			if (type.res[j] < 32 || type.res[j] >= 127)
			{
				type.x += display_oct_string_zero(type.res, j);
				type.count += my_put_nbr_oct(type.res[j]);
				type.y -= 1;
			}
			else if (type.res[j] >= 32 && type.res[j] < 127)
				my_putchar(type.res[j]);
		}
	}
	return (my_strlen(type.res) + type.count + type.x + type.y + type.r);
}

int 	my_printf_turnup(t_printf *print, char *str
	, int (*fptr[16])(va_list, char *, t_printf *)
	, va_list ap)
{
	char	buff[] = "dcsSuxXbpoi+### %";
	int 	j;

	j = -1;
	while (buff[++j] != '\0' && str[print->i] != '\0')
	{
		while (str[print->i] >= '0' && str[print->i] <= '9' STRBUFF)
			print->i += 1;
		if (str[print->i] == buff[j])
		{
			while (str[print->i] != '%')
				print->i -= 1;
			if (str[print->i - 1] != '%')
				print->i += 1;
			return (fptr[j](ap, str, print));
		}
	}
	while (str[print->i] != '%')
		print->i -= 1;
	while (str[print->i] != buff[j] && str[print->i] != '\0')
		my_putchar(str[print->i++]);
	print->i -= 1;
	return (-1);
}
