/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:59:58 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/27 16:45:49 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_lstadd_back(t_list **lst, t_list *new_lst)
{
	t_list	*last_node;

	if (*lst == NULL)
		*lst = new_lst;
	else
	{
		last_node = ft_lstlast(*lst);
		last_node->next = new_lst;
	}
}
