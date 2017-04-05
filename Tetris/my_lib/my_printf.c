/*
** my_printf.c for my_printf in /home/Rev/PSU_2016_my_printf
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Mon Nov	7 10:31:11 2016 Roméo Nahon
** Last update	Mon Nov	7 10:31:11 2016 Roméo Nahon
*/

#include "my.h"

int			display_d(va_list ap, char *str, t_printf *print)
{
	int 	d;
	int 	y;

	d = va_arg(ap, int);
	y = 0;
	if (str[print->i] == '+')
	{
		if (d >= 0)
			my_putchar('+');
		print->i += 1;
	}
	while (str[print->i] == 32)
		print->i += 1;
	if (str[print->i] >= '0' && str[print->i] <= '9')
	{
		y += weight_n(d, str, print);
		while (str[print->i] >= '0' && str[print->i] <= '9')
			print->i += 1;
	}
	if (str[print->i] == 'd' || str[print->i] == 'i')
		my_put_nbr(d);
	return (my_intlen(d) + y);
}

int				display_c(va_list ap, char *str, t_printf *print)
{
	char 		c;
	int 		y;

	y = 0;
	c = va_arg(ap, int);
	if (str[print->i] >= '0' && str[print->i] <= '9')
	{
		y += weight_n_char(c, str, print);
		while (str[print->i] >= '0' && str[print->i] <= '9')
			print->i += 1;
	}
	if (str[print->i] == 'c')
		my_putchar(c);
	return (y + 1);
}

int 			display_s(va_list ap, char *str, t_printf *print)
{
	char	*res;
	int 	y;

	if ((res = malloc(sizeof(char) * my_strlen(str))) == NULL)
		return (-1);
	y = 0;
	if ((res = va_arg(ap, char *)) == NULL)
	{
		my_putstr("(null)");
		return (6);
	}
	if (str[print->i] >= '0' && str[print->i] <= '9')
	{
		y += weight_n_string(res, str, print);
		while (str[print->i] >= '0' && str[print->i] <= '9')
			print->i += 1;
	}
	if (str[print->i] == 's')
		my_putstr(res);
	return (my_strlen(res) + y);
}

int 			my_printf_next(va_list ap, char *str, t_printf *print)
{
	int 	(*fptr[17])(va_list, char *, t_printf *);

	fptr[0] = &display_d;
	fptr[1] = &display_c;
	fptr[2] = &display_s;
	fptr[3] = &display_oct_string;
	fptr[4] = &positiv_int;
	fptr[5] = &conv_hexa_dec;
	fptr[6] = &conv_hexa_dec_capital;
	fptr[7] = &conv_dec_bin;
	fptr[8] = &display_adress;
	fptr[9] = &conv_dec_oct;
	fptr[10] = &display_d;
	fptr[11] = &display_d;
	fptr[12] = &conv_hexa_dec;
	fptr[13] = &conv_hexa_dec_capital;
	fptr[14] = &conv_dec_oct;
	fptr[15] = &display_d;
	fptr[16] = &display_pourcent;
	my_printf_turnup(print, str, fptr, ap);
}

int 			my_printf(char *str, ...)
{
	va_list		ap;
	t_printf 	*print;
	int 		a;

	if ((print = malloc(sizeof(t_printf))) ==  NULL)
		return (-1);
	print->x = 0;
	print->i = 0;
	va_start(ap, str);
	while (str[print->i] != '\0')
	{
		my_printf_other(ap, print, str);
		print->i += 1;
	}
	va_end(ap);
	return (print->x + a);
}