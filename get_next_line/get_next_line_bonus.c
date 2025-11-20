/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:23:04 by dgibrat           #+#    #+#             */
/*   Updated: 2025/11/20 16:20:33 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	read_in_file(char **line, int fd)
{
	ssize_t	size_read;
	char	*buffer;
	char	*tmp;
	size_t	total;

	buffer = malloc((BUFFER_SIZE * sizeof(char)) + sizeof(char));
	size_read = 1;
	if (buffer == NULL)
		size_read = -1;
	total = ft_strlen(*line);
	while (size_read > 0 && ft_strchr(*line, total - size_read, '\n') == NULL)
	{
		size_read = read(fd, buffer, BUFFER_SIZE * sizeof(char));
		if (size_read >= 0)
		{
			buffer[size_read] = '\0';
			tmp = ft_strjoin(*line, buffer, total);
			free(*line);
			*line = tmp;
			total += size_read;
		}
		else
			free(*line);
	}
	free(buffer);
}

static char	*get_first_line(char **line)
{
	unsigned int	i;
	char			*result;
	char			*tmp;

	if (*line == NULL)
		return (NULL);
	i = 0;
	while ((*line)[i] != '\0' && (*line)[i] != '\n')
		i++;
	if ((*line)[i] == '\n')
		i++;
	result = ft_substr(*line, 0, i);
	tmp = ft_substr(*line, i, ft_strlen(*line));
	free(*line);
	*line = tmp;
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*line[200];

	if (fd >= 0 && fd <= 200)
	{
		read_in_file(&(line[fd]), fd);
		return (get_first_line(&(line[fd])));
	}
	return (NULL);
}
