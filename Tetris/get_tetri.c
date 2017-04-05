/*
** tetrimino.c for tetris in /home/Rev/PSU_2016_tetris
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Mon Feb	20 10:28:12 2017 Roméo Nahon
** Last update	Mon Feb	20 10:28:12 2017 Roméo Nahon
*/

#include "include/tetris.h"

void	filled_tetri_list(t_tetri_first_list *tetri_list,
			  char *tetriminos, char *tetri_file)
{
  t_tetri_list	tetri_value;
  int	tetri_size_only;
  int	i;
  int	countline;

  i = -1;
  countline = 0;
  while (tetriminos && tetriminos[++i])
    if (tetriminos[i] == '\n' || (countline >= 1 && tetriminos[i + 1] == 0))
      countline += 1;
  tetri_value.tetri_size = NULL;
  if (!(countline <= 1))
    {
      tetri_value.tetri_size = get_tetri_mension(tetriminos);
      tetri_value.tetri_color = get_tetri_color(tetriminos);
      tetri_value.tetri_forme = get_tetri_forme
	(tetriminos, tetri_value.tetri_size, &tetri_size_only);
      tetri_value.tetri_size_only = tetri_size_only;
    }
  tetri_value.tetri_name = get_tetri_name(tetri_file);
  tetri_value.tetri_error = tetri_forme_error(tetri_value, tetriminos);
  push_tetrimino(tetri_list, tetri_value);
}

int	get_size_of_file(char *tetri_file)
{
  struct stat size;

  stat(tetri_file, &size);
  return (size.st_size);
}

void	get_tetrimino(char *tetri_file, char *name_dir,
		      t_tetri_first_list *tetri_list)
{
  char	*tetriminos;
  char	*get_file;
  int	fd;
  int	size;
  int	i;

  i = -1;
  if ((get_file = malloc(sizeof(char) * my_strlen(name_dir) +
			 my_strlen(tetri_file) + 3)) == NULL)
    exit(84);
  get_file = my_memset(get_file, '\0', my_strlen(name_dir) +
		       my_strlen(tetri_file) + 3);
  while (name_dir[++i] != '\0')
    get_file[i] = name_dir[i];
  get_file[i] = '/';
  get_file = my_strcat(get_file, tetri_file);
  if ((fd = open(get_file, O_RDONLY)) == -1)
    exit(84);
  size = get_size_of_file(get_file);
  if ((tetriminos = malloc(sizeof(char) * size + 9)) == NULL)
    exit(84);
  tetriminos = my_memset(tetriminos, 0, size + 4);
  if ((read(fd, tetriminos, size + 9)) < 0)
    exit(84);
  filled_tetri_list(tetri_list, tetriminos, tetri_file);
}

t_tetri_first_list	*tetrimino(t_tetri_first_list *tetri_list,
				   t_tetris *tetris)
{
  struct dirent		*tetri_dir;
  DIR			*rep;
  char			*name_dir;
  int			i;

  i = 2;
  name_dir = my_strdup("tetriminos");
  if ((rep = opendir(name_dir)) == NULL)
    {
      my_strerror("Error: can't open directory\n");
      exit(84);
    }
  while ((tetri_dir = readdir(rep)) != NULL)
    {
      ++i;
      if (check_name_of_file(tetri_dir->d_name) == 0)
	get_tetrimino(tetri_dir->d_name, name_dir, tetri_list);
      else
	--i;
    }
  closedir(rep) == -1 ? exit(84) : 0;
  tetri_list = (i == 1 ? NULL : tetri_list);
  tetris->nbr = i - 2;
  return (tetri_list);
}

t_tetri_first_list	*list_tetriminos(t_tetris *tetris)
{
  t_tetri_first_list *tetri_list;

  if ((tetri_list = malloc(sizeof(*tetri_list))) == NULL)
    exit(84);
  tetri_list = tetrimino(tetri_list, tetris);
  return (tetri_list);
}
