/*
** my_printf_display.c for my_printf in /home/Rev/PSU_2016_my_printf
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Sat Nov	12 14:05:56 2016 Roméo Nahon
** Last update	Sat Nov	12 14:05:56 2016 Roméo Nahon
*/

#include "my.h"

int 		display_oct_string(va_list ap, char *str, t_printf *print)
{
	t_type  type;

	type.count = 0;
	type.y = 0;
	type.x = 0;
	type.r = 0;
	type.res = va_arg(ap, char *);
	if (str[print->i] >= '0' && str[print->i] <= '9')
	{
		type.r += weight_n_string(type.res, str, print);
		while (str[print->i] >= '0' && str[print->i] <= '9')
		print->i += 1;
	}
	display_oct_string_next(type, str, print);
}
int 		weight_n(int d, char *str, t_printf *print)
{
	char 	*res;
	char 	*value;
	int 	nb_space;
	int 	j;
	int 	z;

	if ((res = malloc(sizeof(char) * my_intlen(d))) == NULL ||
		(value = malloc(sizeof(char) * my_intlen(d))) == NULL)
		return (-1);
	z = 0;
	j = 0;
	while (str[print->i] >= '0' && str[print->i] <= '9')
	{
		res = my_itoa(d, res);
		value[j++] = str[print->i++];
	}
	nb_space = my_strlen(res) - my_getnbr(value);
	while (nb_space != 0)
	{
		z += 1;
		my_putchar(' ');
		(nb_space < 0) ? (nb_space += 1) : (nb_space -= 1);
	}
	return (z);
}
int 		weight_n_string(char *d, char *str, t_printf *print)
{
	char 	*res;
	char 	*value;
	int 	nb_space;
	int 	j;
	int 	z;

	if ((res = malloc(sizeof(char) * my_strlen(d))) == NULL ||
		(value = malloc(sizeof(char) * my_strlen(d))) == NULL)
		return (-1);
	z = 0;
	j = 0;
	while (str[print->i] >= '0' && str[print->i] <= '9')
		value[j++] = str[print->i++];
	nb_space = my_strlen(d) - my_getnbr(value);
	if (my_getnbr(value) < my_strlen(d))
		return (0);
	while (nb_space != 0)
	{
		z += 1;
		my_putchar(' ');
		(nb_space < 0) ? (nb_space += 1) : (nb_space -= 1);
	}
	return (z);
}
int 		weight_n_char(char d, char *str, t_printf *print)
{
	char 	*res;
	char 	*value;
	int 	nb_space;
	int 	j;
	int 	z;

	if ((res = malloc(sizeof(char))) == NULL ||
		(value = malloc(sizeof(char))) == NULL)
		return (-1);
	z = 0;
	j = 0;
	while (str[print->i] >= '0' && str[print->i] <= '9')
		value[j++] = str[print->i++];
	nb_space = 1 - my_getnbr(value);
	while (nb_space != 0)
	{
		z += 1;
		my_putchar(' ');
		(nb_space < 0) ? (nb_space += 1) : (nb_space -= 1);
	}
	return (z);
}
int 		weight_n_ptr(char *d, char *str, t_printf *print)
{
	char 	*res;
	char 	*value;
	int 	nb_space;
	int 	j;
	int 	z;

	if ((res = malloc(sizeof(char) * my_strlen(d))) == NULL ||
		(value = malloc(sizeof(char) * my_strlen(d))) == NULL)
		return (-1);
	z = 0;
	j = 0;
	while (str[print->i] >= '0' && str[print->i] <= '9')
		value[j++] = str[print->i++];
	nb_space = (my_strlen(d) + 2) - my_getnbr(value);
	if (my_getnbr(value) < my_strlen(d))
		return (0);
	while (nb_space != 0)
	{
		z += 1;
		my_putchar(' ');
		(nb_space < 0) ? (nb_space += 1) : (nb_space -= 1);
	}
	return (z);
}