/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:07:20 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/11 10:18:35 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_tab(void **tab)
{
	size_t	len;

	len = 0;
	while (tab[len])
	{
		ft_free_malloc(tab[len]);
		len++;
	}
	ft_free_malloc(tab);
}
