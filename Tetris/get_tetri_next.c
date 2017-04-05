/*
** get_tetri_next.c for tetris in /home/Rev/PSU_2016_tetris
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Thu Feb	23 17:12:15 2017 Roméo Nahon
** Last update	Thu Feb	23 17:12:15 2017 Roméo Nahon
*/

#include "include/tetris.h"

char	*get_tetri_mension(char *tetriminos)
{
  char	**tab;
  char	*tetri_size;
  int	i;
  int	j;
  int	nb;

  tab = my_str_to_wordtab(tetriminos);
  if ((tetri_size = malloc(sizeof(char) * my_strlen(tab[0]) + 10)) == NULL)
    exit (84);
  tetri_size = my_memset(tetri_size, '\0', my_strlen(tab[0]) + 10);
  tetri_size[0] = 0;
  i = -1;
  j = 0;
  nb = 0;
  while (i < my_strlen(tab[0]) && tab[0][++i] != '\0')
    {
      while (tab[0][i] >= '0' && tab[0][i] <= '9' && nb != 2)
	tetri_size[j++] = tab[0][i++];
      if (nb++ != 2) tetri_size[j++] = '*';
    }
  tetri_size[j - 1] = '\0';
  i = -1;
  while (tab[++i]) free(tab[i]);
  free(tab);
  return (tetri_size);
}

char	*get_tetri_name(char *tetri_file)
{
  int	i;
  int	j;
  char	*tetri_name;

  if ((tetri_name = malloc(sizeof(char) * my_strlen(tetri_file))) == NULL)
    exit(84);
  tetri_name = my_memset(tetri_name, 0, my_strlen(tetri_file));
  i = -1;
  j = my_strlen(tetri_file) - 1;
  while (tetri_file[--j] != '.' && j > -1);
  while (++i < j)
    tetri_name[i] = tetri_file[i];
  return (tetri_name);
}

int		get_tetri_color(char *tetriminos)
{
  char	**tab;
  char	*tetri_color;
  int	nb;
  int	i;
  int	j;

  if ((tetri_color = malloc(sizeof(char) * (4))) == NULL)
    return (84);
  tetri_color = my_memset(tetri_color, 0, 4);
  tab = my_str_to_wordtab(tetriminos);
  nb = 0;
  i = -1;
  j = -1;
  while (i < my_strlen(tab[0]) && tab[0][++i] != '\0')
    {
      while (tab[0][i] >= '0' && tab[0][i] <= '9' && nb == 2)
	tetri_color[++j] = tab[0][i++];
      if (tab[0][i] == ' ')
	nb++;
    }
  i = -1;
  while (tab[++i])
    free(tab[i]);
  free(tab);
  return (my_getnbr(tetri_color));
}

void	parse_tetri_mension(char *tetri_mension, int *width, int *height)
{
  int	i;
  int	j;
  int	nb;
  char	*width_char;
  char	*height_char;

  if ((width_char = malloc(sizeof(char) * 15)) == NULL
      || (height_char = malloc(sizeof(char) * 15)) == NULL)
    exit (84);
  width_char = my_memset(width_char, 0, 15);
  height_char = my_memset(height_char, 0, 15);
  i = -1;
  nb = 0;
  while (tetri_mension[++i] != '\0')
    {
      j = 0;
      while (tetri_mension[i] && TETRI_0_9 && nb == 0)
	width_char[j++] = tetri_mension[i++];
      while (tetri_mension[i] && TETRI_0_9 && nb == 1)
	height_char[j++] = tetri_mension[i++];
      nb++;
    }
  *width = my_getnbr(width_char);
  *height = my_getnbr(height_char);
}

int	**get_my_form(char *tetri, int **tab, int width, int height)
{
  int	i;
  int	j;
  int	y;

  i = -1;
  while (tetri[++i] && tetri[i] != '\n');
  y = -1;
  while (tetri[++i] && y < height)
    {
      j = -1;
      if ((tab[++y] = malloc(sizeof(int) * width)) == NULL)
	exit(84);
      while (++j < width)
	{
	  tab[y][j] = (((tetri[i]) && (tetri[i] == '*')) ? 1 : 0);
	  if (tetri[i] != '\n' && tetri[i])
	    ++i;
	}
      while (tetri[i] && tetri[i] != '\n')
	++i;
    }
  get_end_tab(y, j, width, tab);
  return (tab);
}
