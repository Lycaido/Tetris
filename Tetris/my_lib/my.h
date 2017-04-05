/*
** my.h for my in /home/Rev/CPool_Day09/include
** 
** Made by Roméo Nahon
** Login   <Rev@epitech.net>
** 
** Started on  Thu Oct 13 15:42:06 2016 Roméo Nahon
** Last update Sun Jan  8 13:58:38 2017 Roméo Nahon
*/

#ifndef MY_H
#define MY_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define STRBUFF && str[print->i] != buff[j]

int 	my_power_it(int nb, int p);
char 	*my_ctoa(char str);
char 	*binary(int nb);
int  	decimal(char *str);
char 	*realloc_read(char *str, int lenght, int size_read);
char	*filled_str(int *lenght, int *i, char *buffer, char *str);
char	*against_zero(char *str, int *i);
char	*for_slash_n(char *str, int *i);
char	*my_memset(char *, char, int);
int		count_parse_word_all(char *str);
void	my_show_wordtab(char **tab);
int		check_parser(char str, char *to_parse);
int		count_parse_word(char *str, char *to_parse);
char	**parse_in_tab_next(char *str, char **tab, int *k, char *to_parse);
char	**parse_all(char *str, char **tab, int *k);
char	**parse_in_tab(char *str, char *to_parse);
char	**my_str_to_wordtab(char *);
char	**my_str_to_wordtabmod(char *str, char sep);
char	**my_str_to_wordtabmod_next(char *str, char **tab, int *, char sep);
int		count_wordmod(char *str, char sep);
void	my_swap(int a, int b);
char	*my_strupcase(char *str);
char	*my_strstr(char *str, char *to_find);
char	*my_strncpy(char *dest, char*src, int n);
int		my_strncmp(char *s1, char *s2, int n);
char	*my_strncat(char *dest, char *src, int nb);
char	*my_strlowcase(char *str);
char 	*intoarg(int nb, int lenght2);
int 	my_put_nbr_oct(char nb);
int	    my_put_nbr_unsigned(unsigned int nb);
char    *my_itoa(int nb, char* res);
int 	my_intlen(int nb);
int		my_strlen(char *str);
int		my_str_isupper(char *str);
int		my_str_isprintable(char *str);
int		my_str_isnum(char *str);
int		my_str_islower(char *str);
int		my_str_isalpha(char *str);
char	*my_strcpy(char *src, char *dest);
int		my_strcmp(char *s1, char *s2);
char	*my_strcat(char *dest, char *src);
char	*my_strcapitalize(char *str);
int		my_square_root(int nb);
void	my_sort_int_tab(int *tab, int size);
int		my_showstr(char *str);
int		my_showmem(char *str, int size);
char	*my_revstr(char *str);
int		my_putstr(char *str);
int		my_strerror(char *str);
int		my_put_nbr(int nb);
void	my_putchar(char c);
void	my_puterror(char c);
int		my_power_rec(int nb, int power);
int		my_find_prime_sup(int nb);
int		my_getnbr(char *str);
int		my_isneg(int n);
int		my_is_prime(int nombre);
char	*my_strdup(char *str);

typedef struct s_list
{
	void 	*data;
	struct 	s_list 	*next;
} 	t_list;

typedef struct s_type
{
	int 	j;
	int 	x;
	int 	z;
	int 	r;
	int 	y;
	int 	count;
	char 	*res;
} t_type;

typedef struct s_printf
{
	int i;
	int x;
} t_printf;

t_list 		*my_params_to_tab(int ac, char **av);
t_list		*my_list(void* data, t_list* list);
t_printf 	*my_printf_other(va_list ap, t_printf *print, char *str);
int 	my_printf_turnup(t_printf *print, char *str
	, int (*fptr[16])(va_list, char *, t_printf *), va_list ap);
char 	*conv_dec_oct_other(unsigned int nb, char *res);
char  	*conv_dec_bin_other(char *str, t_printf *print, int nb);
char 	*conv_hexa_dec_other(unsigned int nb, char *res);
char 	*conv_hexa_dec_capital_other(unsigned int nb, char *res);
char 	*display_adress_other(unsigned int nb, char *res);
int 	display_oct_string_next(t_type type, char *str, t_printf *print);
int 	display_pourcent(va_list ap, char *str, t_printf *);
int 	weight_n_ptr(char *d, char *, t_printf *print);
int 	weight_n_char(char d, char *str, t_printf *print);
int 	weight_n_string(char *d, char *str, t_printf *print);
int		display_d(va_list ap, char *str, t_printf *print);
int 	parsing(va_list ap, char *str, t_printf *print);
int 	display_oct_string_zero(char *res, int j);
int 	display_adress_next(unsigned int nb);
int 	weight_n(int d,char *str, t_printf *print);
int 	flag_oct(char *str, t_printf *print);
int 	flag_hexa_capital(char *, t_printf *print);
int 	flag_hexa(char *, t_printf *print);
int     my_printf_next(va_list ap, char *str, t_printf *print);
int 	my_printf(char *str, ...);
int 	display_oct_string(va_list ap, char *str, t_printf *print);
int  	display_adress(va_list ap, char *str, t_printf *print);
int		conv_hexa_dec_capital(va_list ap, char *str, t_printf *print);
int 	conv_dec_bin(va_list, char *, t_printf *print);
int 	conv_hexa_dec(va_list, char *, t_printf *print);
int 	conv_dec_oct(va_list, char *, t_printf *print);
int 	positiv_int(va_list ap, char *str, t_printf *print);

#endif /*MY_H*/
