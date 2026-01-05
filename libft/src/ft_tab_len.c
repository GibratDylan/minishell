/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:35:03 by dgibrat           #+#    #+#             */
/*   Updated: 2026/01/05 14:00:27 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_tab_len(char **tab)
{
	int	size;

	size = 0;
	if (!tab)
		return (size);
	while (tab[size])
		size++;
	return (++size);
}
