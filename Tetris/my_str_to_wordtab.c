/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/mistralaix/delivery/CPool_Day08/task04
** 
** Made by cyril chaillan
** Login   <mistralaix@epitech.net>
** 
** Started on  Thu Oct 13 16:08:34 2016 cyril chaillan
** Last update Tue Mar 14 10:20:54 2017 cyril chaillan
*/

#include <stdlib.h>

int	alphanumeric(char c)
{
  if ('\n' == c)
    return (0);
  else
    return (1);
}

int	sizeligne(char *str)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (str[i] != 0)
    {
      if (alphanumeric(str[i]) == 1)
	{
	  count++;
	  while (alphanumeric(str[i]) == 1 && str[i] != 0)
	    i++;
	}
      if (str[i] != 0)
	i++;
    }
  return (count);
}

char	*sizemots(char *str)
{
  int	count;
  int	i;
  char	*word;

  count = 0;
  i = 0;
  while (alphanumeric(str[count]) == 1 && str[count] != '\0')
    count++;
  word = malloc(sizeof(char) * (count + 1));
  while (i < count)
    {
      word[i] = str[i];
      i++;
    }
  word[i] = '\0';
  return (word);
}

char	**my_str_to_wordtab(char *str)
{
  int	i;
  int	j;
  char	**word;

  i = 0;
  j = 0;
  if (str[0] == 0)
    return (NULL);
  word = malloc(sizeof(char *) * (sizeligne(str) + 1));
  while (str[i] != 0)
    {
      if (alphanumeric(str[i]) == 1)
	{
	  word[j] = sizemots(&str[i]);
	  j++;
	}
      while (alphanumeric(str[i]) == 1 && str[i] != 0)
	i++;
      while (alphanumeric(str[i]) == 0 && str[i] != 0)
	i++;
    }
  word[j] = NULL;
  return (word);
}
