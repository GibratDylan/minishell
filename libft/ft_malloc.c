/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:57:39 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/10 20:11:22 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	**get_malloc_list(void)
{
	static t_list	*malloc_list = NULL;

	return (&malloc_list);
}

void	free_all_malloc(void)
{
	t_list	**malloc_list;
	t_list	*current;
	t_list	*tmp;

	malloc_list = get_malloc_list();
	current = *malloc_list;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp->content);
		free(tmp);
	}
	*malloc_list = NULL;
}

static void	free_node(t_list **malloc_list)
{
	t_list	*tmp;

	free((*malloc_list)->content);
	(*malloc_list)->content = NULL;
	tmp = *malloc_list;
	*malloc_list = (*malloc_list)->next;
	free(tmp);
	tmp = NULL;
}

void	free_malloc(void *ptr)
{
	t_list	**malloc_list;
	t_list	*current;
	t_list	*tmp;

	malloc_list = get_malloc_list();
	if (!ptr || !*malloc_list)
		return ;
	current = *malloc_list;
	if (ptr == current->content)
	{
		free_node(malloc_list);
		return ;
	}
	while (current && current->next)
	{
		if (ptr == current->next->content)
		{
			free(current->next->content);
			tmp = current->next;
			current->next = current->next->next;
			free(tmp);
			return ;
		}
		current = current->next;
	}
}

void	*ft_malloc(size_t nmemb, size_t size)
{
	t_list	**malloc_list;
	void	*result;
	t_list	*new_node;

	malloc_list = get_malloc_list();
	result = ft_calloc(nmemb, size);
	if (!result)
		return (free_all_malloc(), NULL);
	new_node = ft_lstnew(result);
	if (!new_node)
		return (free_all_malloc(), NULL);
	if (!*malloc_list)
		*malloc_list = new_node;
	else
		ft_lstadd_back(malloc_list, new_node);
	return (result);
}
