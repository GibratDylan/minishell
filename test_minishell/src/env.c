/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:10:52 by dgibrat           #+#    #+#             */
/*   Updated: 2026/01/03 16:36:10 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test_minishell.h"

char	*ft_getenv(const char *name, char **env)
{
	int		i;
	char	*key;

	key = ft_strjoin(name, "=", ft_strlen(name));
	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(key, env[i], ft_strlen(key)))
			return (&(env[i][ft_strlen(key)]));
		i++;
	}
	ft_free_malloc(key);
	return (NULL);
}
