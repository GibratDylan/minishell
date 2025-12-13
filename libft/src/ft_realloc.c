/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:13:30 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/13 08:34:46 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_realloc(void *ptr, size_t size_before, size_t size_after)
{
	void	*result;

	result = NULL;
	if (size_after > 0)
	{
		result = ft_malloc(1, size_after);
		if (size_before < size_after)
			ft_memcpy(result, ptr, size_before);
		else
			ft_memcpy(result, ptr, size_after);
	}
	ft_free_malloc(ptr);
	return (result);
}
