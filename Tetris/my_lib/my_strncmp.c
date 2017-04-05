/*
** my_strncmp.c for my_strncmp in /home/Rev/CPool_Day07/lib/my
** 
** Made by Roméo Nahon
** Login   <Rev@epitech.net>
** 
** Started on  Tue Oct 11 09:48:16 2016 Roméo Nahon
** Last update Wed Oct 26 17:11:36 2016 Roméo Nahon
*/

#include "my.h"

int	my_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && n != 0)
	{
		if (s1[i] != s2[i] || s1[i] == '\0'
			&& s2[i] != '\0' || s2[i] == '\0' && s1[i] != '\0')
			return (1);
		i += 1;
		n -= 1;
	}
	return (0);
}
