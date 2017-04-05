/*
** get_next_line.c for get_next_line in /home/Rev/CPE_2016_getnextline
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Wed Jan	11 15:43:52 2017 Roméo Nahon
** Last update	Wed Jan	11 15:43:52 2017 Roméo Nahon
*/

#include "my.h"

char	*get_next_line(const int fd)
{
	static int 	lenght = 0;
	static char *buffer;
	static int 	size_read = 0;
	char 		*str;
	int 		i;

	i = 0;
	if (!lenght && (buffer = malloc(sizeof(char) * READ_SIZE)) == NULL ||
		(!lenght && (size_read += read(fd, buffer, READ_SIZE)) <= 0) ||
		(str = malloc(sizeof(char) * READ_SIZE)) == NULL) return (NULL);
		my_memset(str, '\0', READ_SIZE);
	while (1)
	{
		if (lenght == size_read)
		{
			buffer = realloc_read(buffer, lenght, size_read);
			str = realloc_read(str, lenght, size_read);
			size_read += read(fd, &buffer[lenght], READ_SIZE);
			if (str[i - 1] != '\0' && lenght == size_read)
				return (against_zero(str, &i));
			if (lenght == size_read) return (NULL);
		}
		filled_str(&lenght, &i, buffer, str);
		if (buffer[(lenght - 1)] == '\n') return (for_slash_n(str, &i));
	}
}

char	*for_slash_n(char *str, int *i)
{
	str[*i - 1] = '\0';
	return (str);
}

char	*against_zero(char *str, int *i)
{
	str[(*i)] = '\0';
	return (str);
}

char	*filled_str(int *lenght, int *i, char *buffer, char *str)
{
	str[*i] = buffer[*lenght];
	*lenght += 1;
	*i += 1;
	return (str);
}

char 	*realloc_read(char *str, int lenght, int size_read)
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