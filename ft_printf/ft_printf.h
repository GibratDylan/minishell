/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:40:51 by dgibrat           #+#    #+#             */
/*   Updated: 2025/11/13 10:04:48 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef unsigned char	t_bool;

int						ft_printf(const char *str, ...);
char					*ft_itoa_base(unsigned long long n, char *base,
							t_bool is_address);
char					*ft_strdup_null(const char *s);

#endif