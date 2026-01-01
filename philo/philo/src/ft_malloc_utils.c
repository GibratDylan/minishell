/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:26:28 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/27 21:36:13 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_list	*new_node(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

void	free_node(t_list **malloc_list)
{
	t_list	*tmp;

	free((*malloc_list)->content);
	(*malloc_list)->content = NULL;
	tmp = *malloc_list;
	*malloc_list = (*malloc_list)->next;
	free(tmp);
	tmp = NULL;
}
