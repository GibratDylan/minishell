/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:05:34 by dgibrat           #+#    #+#             */
/*   Updated: 2025/11/18 17:22:02 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	read_in_file(char **line, int fd)
{
	ssize_t	size_read;
	char	*buffer;
	char	*tmp;

	buffer = malloc((BUFFER_SIZE + sizeof(char)) * sizeof(char));
	size_read = 1;
	if (buffer == NULL)
		size_read = -1;
	while (size_read > 0 && (ft_strchr(*line, '\n') == NULL))
	{
		size_read = read(fd, buffer, BUFFER_SIZE * sizeof(char));
		if (size_read >= 0)
		{
			buffer[size_read] = '\0';
			tmp = ft_strjoin(*line, buffer);
			free(*line);
			*line = tmp;
		}
	}
	if (size_read == -1)
	{
		free(*line);
		*line = NULL;
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
	static char	*line;

	read_in_file(&line, fd);
	return (get_first_line(&line));
}
