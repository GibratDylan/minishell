/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:16:59 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/10 14:57:50 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;

	if (size == 0 || nmemb == 0 || nmemb > ULONG_MAX / size)
		return (NULL);
	result = malloc(nmemb * size);
	if (result == NULL)
		return (result);
	ft_bzero(result, nmemb * size);
	return (result);
}
