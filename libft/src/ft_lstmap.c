/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:48:31 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/13 08:35:28 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstresult;
	t_list	*tmp;

	lstresult = NULL;
	while (lst != NULL)
	{
		tmp = ft_lstnew((*f)(lst->content));
		if (tmp == NULL)
		{
			ft_lstclear(&lstresult, del);
			return (NULL);
		}
		ft_lstadd_back(&lstresult, tmp);
		lst = lst->next;
	}
	return (lstresult);
}
