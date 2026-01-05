/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:10:52 by dgibrat           #+#    #+#             */
/*   Updated: 2026/01/05 16:49:28 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*get_env_value(const char *name, char **env)
{
	int		i;
	char	*key;
	int		size_key;

	if (!name || !(*env))
		return (NULL);
	key = ft_strjoin(name, "=", ft_strlen(name));
	size_key = ft_strlen(key);
	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(key, env[i], size_key))
		{
			ft_free_malloc(key);
			return (&(env[i][size_key]));
		}
		i++;
	}
	ft_free_malloc(key);
	return (NULL);
}

int	get_env_line(const char *name, char **env)
{
	int		i;
	char	*key;
	int		size_key;

	if (!name || !(*env))
		return (-1);
	key = ft_strjoin(name, "=", ft_strlen(name));
	size_key = ft_strlen(key);
	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(key, env[i], size_key))
		{
			ft_free_malloc(key);
			return (i);
		}
		i++;
	}
	ft_free_malloc(key);
	return (-1);
}

t_bool	add_env_line(const char *name, char ***env, char *new_value)
{
	size_t	memory_size_array;
	int		len_array;

	if (!name || !(*env) || !new_value)
		return (FAIL);
	len_array = ft_tab_len(*env);
	memory_size_array = sizeof(char *) * len_array + sizeof(char *);
	*env = ft_realloc(*env, memory_size_array, memory_size_array
			+ sizeof(char *));
	if (!(*env))
		return (FAIL);
	(*env)[len_array] = ft_strjoin(name, "=", ft_strlen(name));
	if (!(*env)[len_array])
		return (FAIL);
	(*env)[len_array] = ft_strjoin_free((*env)[len_array], new_value,
			ft_strlen((*env)[len_array]), (*env)[len_array]);
	if (!(*env)[len_array])
		return (FAIL);
	return (SUCCESS);
}

t_bool	modify_env_value(const char *name, char ***env, char *new_value)
{
	int		index;
	size_t	len_name;
	size_t	len_line;
	size_t	len_new_value;

	if (!name || !(*env) || !new_value)
		return (FAIL);
	index = get_env_line(name, *env);
	if (index == -1)
	{
		if (!add_env_line(name, env, new_value))
			return (FAIL);
		return (SUCCESS);
	}
	len_name = ft_strlen(name);
	len_line = ft_strlen((*env)[index]);
	len_new_value = ft_strlen(new_value);
	(*env)[index] = ft_realloc((*env)[index], len_line + 1, len_name
			+ len_new_value + 1);
	if (!(*env)[index])
		return (FAIL);
	ft_strlcpy(&((*env)[index][len_name + 1]), new_value, len_new_value + 1);
	return (SUCCESS);
}
