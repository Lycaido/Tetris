/*
** my_show_wordtab.c for my_lib in /home/Rev/my_lib
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Wed Jan	18 14:09:13 2017 Roméo Nahon
** Last update	Wed Jan	18 14:09:13 2017 Roméo Nahon
*/

#include "my.h"

void	my_show_wordtab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i] != NULL)
	{
		my_putstr(tab[i]);
		write(1, "\n", 1);
	}
}