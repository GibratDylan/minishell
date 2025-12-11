/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:23:04 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/11 10:37:33 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	read_in_file(char **line, int fd, size_t total, char *buffer)
{
	ssize_t	size_read;
	char	*tmp;

	size_read = 1;
	while (size_read > 0 && ft_strchr(*line, total - size_read, '\n') == NULL)
	{
		size_read = read(fd, buffer, BUFFER_SIZE);
		if (size_read < 0)
			return (0);
		buffer[size_read] = '\0';
		tmp = ft_strjoin(*line, buffer, total);
		if (tmp == NULL)
			return (0);
		ft_free_malloc(*line);
		*line = tmp;
		total += size_read;
	}
	return (1);
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
	if (result == NULL)
		return (NULL);
	tmp = ft_substr(*line, i, ft_strlen(*line));
	ft_free_malloc(*line);
	*line = tmp;
	return (result);
}

char	*get_next_line(int fd, int free_line_fd)
{
	static char	*line[1025];
	char		*buffer;
	char		*result;

	if (free_line_fd)
		return (ft_free_malloc(&(line[fd])), NULL);
	if (fd >= 0 && fd <= 1024 && BUFFER_SIZE > 0)
	{
		buffer = ft_malloc(BUFFER_SIZE + 1, sizeof(char));
		if (buffer == NULL)
			return (NULL);
		if (read_in_file(&(line[fd]), fd, ft_strlen(line[fd]), buffer) == 0)
			return (NULL);
		ft_free_malloc(buffer);
		buffer = NULL;
		result = get_first_line(&(line[fd]));
		if (result == NULL)
			return (NULL);
		return (result);
	}
	return (NULL);
}
