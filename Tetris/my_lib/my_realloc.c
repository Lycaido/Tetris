/*
** my_realloc.c for my_lib in /home/Rev/my_lib
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Wed Feb	1 13:39:27 2017 Roméo Nahon
** Last update	Wed Feb	1 13:39:27 2017 Roméo Nahon
*/

#include "my.h"

char 	*my_realloc(char *str, int lenght, int size_read)
{
	int i;
	char *newstr;

	i = -1;
	if ((newstr = malloc(sizeof(char) * (size_read * 2))) == NULL)
		return (NULL);
	my_memset(newstr, '\0', size_read * 2);
	while (++i < lenght)
		newstr[i] = str[i];
	free(str);
	return (newstr);
}