/*
** my_str_to_wordtabmod.c for my_lib in /home/Rev/my_lib
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Wed Jan	18 15:09:57 2017 Roméo Nahon
** Last update	Wed Jan	18 15:09:57 2017 Roméo Nahon
*/

#include "my.h"

int	count_wordmod(char *str, char sep)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i] != '\0')
	{
		if (str[i] != sep)
		{
			while (str[i] != sep)
				i += 1;
			nb += 1;
		}
		i += 1;
	}
	return (nb);
}

char	**my_str_to_wordtabmod_next(char *str, char **tab, int *k, char sep)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((tab[*k] = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
			return (NULL);
		while (str[i] == sep && str[i] != '\0')
			i += 1;
		j = 0;
		while (str[i] != sep && str[i] != '\0')
		{
			tab[*k][j] = str[i];
			i += 1;
			j += 1;
		}
		*k += 1;
	}
	return (tab);
}

char	**my_str_to_wordtabmod(char *str, char sep)
{
	char	**tab;
	int	j;
	int	k;
	int	i;

	k = 0;
	j = 0;
	i = 0;
	if ((tab = malloc(sizeof(char *) * 20)) == NULL)
		return (NULL);
	my_str_to_wordtabmod_next(str, tab, &k, sep);
	tab[k] == NULL;
	return (tab);
}