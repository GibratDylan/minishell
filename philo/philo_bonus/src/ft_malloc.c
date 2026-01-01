/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:57:39 by dgibrat           #+#    #+#             */
/*   Updated: 2025/12/31 10:30:49 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

static t_list	**get_malloc_list(void)
{
	static t_list	*malloc_list = NULL;

	return (&malloc_list);
}

void	ft_free_all_malloc(void)
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

void	ft_free_malloc(void *ptr)
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
	t_list	*new;

	malloc_list = get_malloc_list();
	result = ft_calloc(nmemb, size);
	if (!result)
		return (ft_free_all_malloc(), NULL);
	new = new_node(result);
	if (!new)
		return (ft_free_all_malloc(), NULL);
	if (!*malloc_list)
		*malloc_list = new;
	else
		ft_lstadd_back(malloc_list, new);
	return (result);
}
