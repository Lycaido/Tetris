 /*
** my_strcmp.c for my_lib in /home/Rev/CPool_Day07/lib/my
** 
** Made by Roméo Nahon
** Login   <Rev@epitech.net>
** 
** Started on  Tue Oct 11 09:46:10 2016 Roméo Nahon
** Last update Wed Oct 26 17:16:31 2016 Roméo Nahon
*/

#include "my.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  if (my_strlen(s1) != my_strlen(s2))
  	return (1);
  while (s1[i] != '\0' && s2[i] != '\0')
    {
    	if (s1[i] != s2[i] || s1[i] == '\0'
        && s2[i] != '\0' || s2[i] == '\0' && s1[i] != '\0')
    		return (1);
     i += 1;
    }
  return (0);
}