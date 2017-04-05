/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/Rev/Delivery/CPool_Day08/task04
** 
** Made by Roméo Nahon
** Login   <Rev@epitech.net>
** 
** Started on  Thu Oct 13 17:24:57 2016 Roméo Nahon
** Last update Wed Nov  2 14:58:50 2016 Roméo Nahon
*/

#include "my.h"

int	count_word(char *str)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while (str[i] != '\0')
  {
    if (str[i] >= 48 && str[i] <= 57 || str[i] >= 65 && str[i] <= 90
     || str[i] >= 97 && str[i] <= 122 || str[i] == 95)
    {
     while (str[i] >= 48 && str[i] <= 57 || str[i] >= 97 && str[i] <= 122
       || str[i] >= 65 && str[i] <= 90 || str[i] == 95)
       i += 1;
     nb += 1;
   }
   i += 1;
 }
 return (nb);
}

char	**my_str_to_wordtab_next(char *str, char **tab, int k)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (str[i] != '\0')
  {
    tab[k] = malloc(sizeof(char) * my_strlen(str) + 2);
    while (str[i] <= 47 && str[i] >= 32 || str[i] <= 64 && str[i] >= 58
      || str[i] <= 94 && str[i] >= 91 || str[i] <= 127 && str[i] >= 123 || str[i] == 96)
    	i += 1;
    j = 0;
    while (str[i] >= 48 && str[i] <= 57 || str[i] >= 65 && str[i] <= 90
      || str[i] >= 97 && str[i] <= 122 || str[i] == 95)
    {
     tab[k][j] = str[i];
     i += 1;
     j += 1;
   }
   tab[k][i + 1] = '\0';
   k += 1;
 }
 return (tab);
}

char	**my_str_to_wordtab(char *str)
{
  char	**tab;
  int	j;
  int	k;
  int	i;

  k = 0;
  j = 0;
  i = 0;
  tab = malloc(sizeof(char *) * count_word(str) + 1);
  my_str_to_wordtab_next(str, tab, k);
  tab[k] == NULL;
  return (tab);
}
