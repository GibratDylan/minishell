/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:50:01 by dgibrat           #+#    #+#             */
/*   Updated: 2025/11/20 13:50:52 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_free_array(char **array)
{
	unsigned long	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		array[i++] = NULL;
	}
	free(array);
	array = NULL;
	return (NULL);
}
