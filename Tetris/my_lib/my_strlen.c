/*
** my_strlen.c for my_strlen in /home/Rev/CPool_Day04
** 
** Made by Roméo Nahon
** Login   <Rev@epitech.net>
** 
** Started on  Thu Oct  6 16:37:52 2016 Roméo Nahon
** Last update Fri Oct  7 07:20:33 2016 Roméo Nahon
*/

int	my_strlen(char	*str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}
