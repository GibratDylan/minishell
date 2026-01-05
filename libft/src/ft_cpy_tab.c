/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:43:35 by dgibrat           #+#    #+#             */
/*   Updated: 2026/01/05 16:06:21 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	**ft_cpy_tab(char **tab)
{
	char	**result;
	int		i;

	if (!tab)
		return (NULL);
	result = ft_malloc(ft_tab_len(tab) + 1, sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		result[i] = ft_strdup(tab[i]);
		i++;
	}
	result[i] = NULL;
	return (result);
}
