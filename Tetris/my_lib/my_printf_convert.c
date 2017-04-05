/*
** convert.c for my_printf in /home/Rev/PSU_2016_my_printf
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Mon Nov	7 14:38:20 2016 Roméo Nahon
** Last update	Mon Nov	7 14:38:20 2016 Roméo Nahon
*/

#include "my.h"

int			conv_dec_bin(va_list ap, char *str, t_printf *print)
{
	int		nb;
	int 	y;
	char 	*res;

	if ((res = malloc(sizeof(char))) == NULL)
		return (-1);
	y = 0;
	nb = va_arg(ap, int);
	if (str[print->i] >= '0' && str[print->i] <= '9')
	{
		y += weight_n(nb, str, print);
		while (str[print->i] >= '0' && str[print->i] <= '9')
			print->i += 1;
	}
	res = conv_dec_bin_other(str, print, nb);
	return (my_strlen(res) + y);
}

int			conv_hexa_dec(va_list ap, char *str, t_printf *print)
{
	unsigned int nb;
	int 		 y;
	char		 *res;

	if ((res = malloc(sizeof(char) * my_strlen(str))) == NULL)
		return (-1);
	y = 0;
	print->i = flag_hexa(str, print);
	nb = va_arg(ap, unsigned int);
	res = conv_hexa_dec_other(nb, res);
	if (str[print->i] >= '0' && str[print->i] <= '9')
	{
		y += weight_n_string(res, str, print);
		while (str[print->i] >= '0' && str[print->i] <= '9')
			print->i += 1;
	}
	if (str[print->i] == 'x')
		my_putstr(my_revstr(res));
	return (my_strlen(res) + y);
}

int				conv_hexa_dec_capital(va_list ap, char *str, t_printf *print)
{
	unsigned int nb;
	char		 *res;
	int 		 y;

	if ((res = malloc(sizeof(char) * my_strlen(str))) == NULL)
		return (-1);
	y = 0;
	print->i = flag_hexa_capital(str, print);
	nb = va_arg(ap, unsigned int);
	res = conv_hexa_dec_capital_other(nb, res);
	if (str[print->i] >= '0' && str[print->i] <= '9')
	{
		y += weight_n_string(res, str, print);
		while (str[print->i] >= '0' && str[print->i] <= '9')
			print->i += 1;
	}
	if (str[print->i] == 'X')
		my_putstr(my_revstr(res));
	return (my_strlen(res) + y);
}

int						display_adress(va_list ap, char *str, t_printf *print)
{
	unsigned int		nb;
	int 				y;
	int 				x;
	char				*res;

	if ((res = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
		return (-1);
	y = 0;
	nb = va_arg(ap, unsigned int);
	x = display_adress_next(nb);
	res = display_adress_other(nb, res);
	if (str[print->i] >= '0' && str[print->i] <= '9')
	{
		y += weight_n_ptr(res, str, print);
		while (str[print->i] >= '0' && str[print->i] <= '9')
			print->i += 1;
	}
	if (str[print->i] == 'p')
	{
		my_putstr("0x");
		my_putstr(my_revstr(res));
	}
	return (my_strlen(res) + x + y + 2);
}

int 		conv_dec_oct(va_list ap, char *str, t_printf *print)
{
	char 	*res;
	int 	y;
	int		nb;

	if ((res = malloc(sizeof(char) * my_strlen(str))) == NULL)
		return (-1);
	y = 0;
	print->i = flag_oct(str, print);
	nb = va_arg(ap, int);
	res = conv_dec_oct_other(nb, res);
	if (str[print->i] >= '0' && str[print->i] <= '9')
	{
		y += weight_n_string(res, str, print);
		while (str[print->i] >= '0' && str[print->i] <= '9')
			print->i += 1;
	}
	if (str[print->i] == 'o')
		my_putstr(my_revstr(res));
	return (my_strlen(res) + y);
}
