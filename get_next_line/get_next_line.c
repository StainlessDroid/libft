/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapascua <mapascua@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:15:46 by lperalta          #+#    #+#             */
/*   Updated: 2025/07/14 16:26:01 by mapascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_loop(int fd, char **res, char *buffer)
/*	reads (buffer_size)bytes from fd until a \n or end of file */
{
	int	bytes_read;

	bytes_read = 1;
	while (!ft_strchr(*res, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			if (*res)
			{
				free(*res);
				*res = NULL;
			}
			return (NULL);
		}
		if (bytes_read)
		{
			buffer[bytes_read] = '\0';
			*res = ft_strjoin_mod(*res, buffer);
		}
	}
	return (*res);
}

char	*ft_file_read(char **res, int fd)
{
	char		*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!ft_read_loop(fd, res, buffer))
	{
		free(buffer);
		return (NULL);
	}
	free (buffer);
	return (*res);
}

char	*ft_get_line(char *res)
/*	returns a copy of res with the leftover text after \n removed */
{
	int		i;

	if (!res || !*res)
		return (NULL);
	if (!ft_strchr(res, '\n'))
		return (ft_strdup(res));
	i = 0;
	while (res[i] && res[i] != '\n')
		i++;
	if (res[i] == '\n')
		i++;
	return (ft_substr_mod(res, i));
}

char	*ft_clean_static(char *res)
/*	free res and return a new static with the leftover text after \n
	it does so by giving strdup a pointer to the first character after \n */
{
	int		i;
	char	*save;

	if (!res)
		return (NULL);
	i = 0;
	while (res[i] && res[i] != '\n')
		i++;
	if (!res[i])
	{
		free(res);
		return (NULL);
	}
	save = ft_strdup(res + i + 1);
	free(res);
	if (save && save[0] == '\0')
	{
		free(save);
		save = NULL;
	}
	return (save);
}

char	*get_next_line(int fd)
/*	Reads a line from a given file and returns it as an allocated char pointer
	Call on loop for reading the file until the end */
{
	static char	*res;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!ft_file_read(&res, fd))
		return (NULL);
	line = ft_get_line(res);
	res = ft_clean_static(res);
	return (line);
}
