/*
** parse_this.c for my_lib in /home/Rev/PSU_2016_minishell1
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Fri Jan	20 12:45:56 2017 Roméo Nahon
** Last update	Fri Jan	20 12:45:56 2017 Roméo Nahon
*/

#include "my.h"

int	count_parse_word_all(char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 48 && str[i] <= 57 || str[i] >= 65 && str[i] <= 90
			|| str[i] >= 97 && str[i] <= 122)
		{
			while (str[i] >= 48 && str[i] <= 57 || str[i] >= 97 && str[i] <= 122
				|| str[i] >= 65 && str[i] <= 90)
				i += 1;
			nb += 1;
		}
		i += 1;
	}
	return (nb);
}

int	check_parser(char str, char *to_parse)
{
	int i;
	int len;

	len = my_strlen(to_parse);
	i = 0;
	while (len > 0 && str != '\0')
	{
		if (to_parse[i] == str)
			return (1);
		i += 1;
		len -= 1;
	}
	if (str == '\0')
		return (2);
	return (0);
}

int	count_parse_word(char *str, char *to_parse)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i] != '\0')
	{
		if (check_parser(str[i], to_parse) == 0)
		{
			while (check_parser(str[i], to_parse) == 0)
				i += 1;
			nb += 1;
		}
		i += 1;
	}
	return (nb);
}
char	**parse_in_tab_next(char *str, char **tab, int *k, char *to_parse)
{
	int	i;
	int	j;
	int r;

	j = 0;
	i = 0;
	tab = malloc(sizeof(char *) * count_parse_word(str, to_parse) + 1);
	while (str[i] != '\0')
	{
		tab[*k] = malloc(sizeof(char) * my_strlen(str) + 2);
		while (check_parser(str[i], to_parse) == 1)
			i += 1;
		j = 0;
		while (check_parser(str[i], to_parse) == 0)
		{
			tab[*k][j] = str[i];
			i += 1;
			j += 1;
		}
		tab[*k][i] = '\0';
		*k += 1;
	}
	return (tab);
}

char	**parse_all(char *str, char **tab, int *k)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i] != '\0')
	{
		tab[*k] = malloc(sizeof(char) * my_strlen(str) + 2);
		while (str[i] <= 47 && str[i] >= 32 || str[i] <= 64 && str[i] >= 58
			|| str[i] <= 96 && str[i] >= 91 || str[i] <= 127 && str[i] >= 123)
			i += 1;
		j = 0;
		while (str[i] >= 48 && str[i] <= 57 || str[i] >= 65 && str[i] <= 94
			|| str[i] >= 97 && str[i] <= 122)
		{
			tab[*k][j] = str[i];
			i += 1;
			j += 1;
		}
		tab[*k][i] = '\0';
		*k += 1;
	}
	return (tab);
}

int	check_filled(char **tab, int k)
{
	int i;

	i = 0;
	while (tab[k - 1][i] != '\0')
	{
		if (tab[k - 1][i] != ' ' && tab[k - 1][i] != '\0' &&
			tab[k - 1][i] != '\t')
			return (1);
		i += 1; 
	}
	return (0);
}
char	**parse_in_tab(char *str, char *to_parse)
{
	char	**tab;
	int	j;
	int	k;
	int	i;

	k = 0;
	j = 0;
	i = 0;
	if (to_parse[0] == '\0')
	{
		tab = malloc(sizeof(char *) * count_parse_word_all(str));
		tab = parse_all(str, tab, &k);
	}
	else
		tab = parse_in_tab_next(str, tab, &k, to_parse);
	if (k > 1)
	{
		if (check_filled(tab, k) == 0)
			tab[k - 1] = NULL;
	}
	tab[k] = NULL;
	return (tab);
}