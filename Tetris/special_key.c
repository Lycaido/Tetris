/*
** special_key.c for special_key in /home/mistralaix/delivery/project/tetris/PSU_2016_tetris
** 
** Made by cyril chaillan
** Login   <mistralaix@epitech.net>
** 
** Started on  Tue Mar 14 23:57:21 2017 cyril chaillan
** Last update Sat Mar 18 21:06:03 2017 cyril chaillan
*/

#include "include/tetris.h"

void	spec_key(char *str, int i, int sortie)
{
  if (str[i] == 13)
    write(sortie, "CR", 2);
  else if (str[i] == 12)
    write(sortie, "FF", 2);
  else if (str[i] == 11)
    write(sortie, "VT", 2);
  else if (str[i] == 10)
    write(sortie, "LF", 2);
  else if (str[i] == 9)
    write(sortie, "HT", 2);
  else if (str[i] == 8)
    write(sortie, "BS", 2);
  else if (str[i] == 7)
    write(sortie, "BEL", 2);
  else if (str[i] == 6)
    write(sortie, "ACK", 2);
  else if (str[i] == 5)
    write(sortie, "ENQ", 2);
  else if (str[i] == 4)
    write(sortie, "EOT", 2);
}

void	spec_key_two(char *str, int i, int sortie)
{
  if (str[i] == 29)
    write(sortie, "GS", 2);
  else if (str[i] == 28)
    write(sortie, "FS", 2);
  else if (str[i] == 26)
    write(sortie, "ESC", 2);
  else if (str[i] == 25)
    write(sortie, "EM", 2);
  else if (str[i] == 24)
    write(sortie, "CAN", 2);
  else if (str[i] == 23)
    write(sortie, "ETB", 2);
  else if (str[i] == 22)
    write(sortie, "SYN", 2);
  else if (str[i] == 21)
    write(sortie, "NAK", 2);
  else if (str[i] == 20)
    write(sortie, "DC4", 2);
}

void	spec_key_three(char *str, int i, int sortie)
{
  if (str[i] == 19)
    write(sortie, "DC3", 2);
  else if (str[i] == 18)
    write(sortie, "DC2", 2);
  else if (str[i] == 17)
    write(sortie, "DC1", 2);
  else if (str[i] == 16)
    write(sortie, "DLE", 2);
  else if (str[i] == 15)
    write(sortie, "SI", 2);
  else if (str[i] == 14)
    write(sortie, "SO", 2);
  else if (str[i] == 3)
    write(sortie, "ETX", 2);
  else if (str[i] == 2)
    write(sortie, "STX", 2);
  else if (str[i] == 1)
    write(sortie, "SOH", 2);
  else if (str[i] == 0)
    write(sortie, "NUL", 2);
}

int	get_key(int i, int j, t_tetris *tetris, char **arr)
{
  if (i == 1)
    {
      while (arr[i][++j])
	tetris->key->touches[0][j] = arr[i][j];
      tetris->key->touches[0][j++] = 0;
    }
  else if (i == 2)
    {
      while (arr[i][++j])
	tetris->key->touches[1][j] = arr[i][j];
      tetris->key->touches[1][j++] = 0;
    }
  else if (i == 3)
    {
      while (arr[i][++j])
	tetris->key->touches[3][j] = arr[i][j];
      tetris->key->touches[3][j++] = 0;
    }
  return (j);
}
