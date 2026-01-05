/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:01:53 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/16 15:20:37 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new_lst)
{
	if (*lst == NULL)
		*lst = new_lst;
	else
	{
		new_lst->next = *lst;
		*lst = new_lst;
	}
}
