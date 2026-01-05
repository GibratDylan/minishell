/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:10:52 by dgibrat           #+#    #+#             */
/*   Updated: 2026/01/05 14:01:51 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test_minishell.h"

char	*get_env_value(const char *name, char **env)
{
	int		i;
	char	*key;
	int		size_key;

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
	int		size_array;

	size_array = ft_tab_len(*env);
	memory_size_array = sizeof(char **) * size_array;
	*env = ft_realloc(*env, memory_size_array, memory_size_array
			+ sizeof(char **));
	if (!(*env))
		return (FAIL);
	*env[size_array - 2] = ft_strjoin(name, "=", ft_strlen(name));
	if (*env[size_array - 2])
		return (FAIL);
	*env[size_array - 2] = ft_strjoin_free(*env[size_array - 2], new_value,
			ft_strlen(name), *env[size_array - 2]);
	if (*env[size_array - 2])
		return (FAIL);
	return (SUCCESS);
}

t_bool	modify_env_value(const char *name, char ***env, char *new_value)
{
	int		index;
	int		i;
	size_t	len_name;
	size_t	len_line;
	size_t	len_new_value;

	index = get_env_line(name, *env);
	if (index == -1)
	{
		add_env_line(name, env, new_value);
		index = ft_tab_len(*env) - 2;
	}
	len_name = ft_strlen(name);
	len_line = ft_strlen(*(env)[index]);
	len_new_value = ft_strlen(new_value);
	env[index] = ft_realloc(*(env)[index], len_line + 1, len_name
			+ len_new_value + 2);
	if (!(*(env)[index]))
		return (FAIL);
	i = len_name + 1;
	ft_strlcpy(&(*(env)[index][i]), new_value, len_new_value + 1);
	return (SUCCESS);
}
