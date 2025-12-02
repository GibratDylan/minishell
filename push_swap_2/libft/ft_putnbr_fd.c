/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 12:31:02 by dgibrat           #+#    #+#             */
/*   Updated: 2025/11/08 12:41:25 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	ll_n;
	char		c_nb;

	ll_n = (long long)n;
	if (ll_n < 0)
	{
		write(fd, "-", 1);
		ll_n *= -1;
	}
	if ((ll_n >= 0) && (ll_n <= 9))
	{
		c_nb = ll_n + '0';
		write(fd, &c_nb, 1);
	}
	if (ll_n > 9)
	{
		ft_putnbr_fd(ll_n / 10, fd);
		ft_putnbr_fd(ll_n % 10, fd);
	}
}
