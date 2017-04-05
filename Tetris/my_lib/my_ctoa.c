/*
** my_ctoa.c for my_lib in /home/Rev/my_lib
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Wed Feb	1 13:33:58 2017 Roméo Nahon
** Last update	Wed Feb	1 13:33:58 2017 Roméo Nahon
*/

#include "my.h"

char *my_ctoa(char str)
{
	char *str1;

	if ((str1 = malloc(sizeof(char) * 2)) == NULL)
		return (NULL);
	str1[0] = str;
	str1[1] = '\0';
	return (str1);
}