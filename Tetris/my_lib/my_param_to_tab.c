/*
** my_param_to_tab.c for my_param_to_tab in /home/Rev/CPool_Day09/task03
** 
** Made by Roméo Nahon
** Login   <Rev@epitech.net>
** 
** Started on  Thu Oct 13 16:44:09 2016 Roméo Nahon
** Last update Thu Oct 13 16:55:24 2016 Roméo Nahon
*/

#include <stdlib.h>
#include <my.h>

t_list* my_list(void* data, t_list* list)
{
	t_list* pingas;

	pingas = malloc(sizeof(t_list));
	pingas->data = data;
	pingas->next = list;
	return (pingas);
}

t_list *my_params_to_tab(int ac, char **av)
{
	t_list* pingas;
	int i;

	i = -1;
	pingas = 0;
	while(++i < ac)
		pingas = my_list(av[i], pingas);
	return (pingas);
}