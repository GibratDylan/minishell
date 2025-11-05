/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:16:59 by dgibrat           #+#    #+#             */
/*   Updated: 2025/11/05 14:34:40 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned long	i;
	void			**p;
	void			*memb;

	p = NULL;
	i = 0;
	if ((nmemb * size > INT_MAX) || nmemb == 0 || size == 0)
		return (p);
	p = malloc(nmemb * size);
	while (i < nmemb)
	{
		memb = malloc(size);
		ft_bzero(memb, size);
		p[i++] = memb;
	}
	return (p);
}
