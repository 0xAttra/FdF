/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 08:18:41 by macuesta          #+#    #+#             */
/*   Updated: 2024/11/15 13:40:00 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

# include "libft.h"

// fr_print.c
int	ft_printf(const char *fm, ...);

// handlers/
int	ft_handler_c(char c);
int	ft_handler_s(char *s);
int	ft_handler_p(unsigned long int n);
int	ft_handler_d_i(int n);
int	ft_handler_u(unsigned int n);
int	ft_handler_x(unsigned int n, char *base);

// utils/
int	ft_dispatcher(char c, va_list *args);
int	ft_print_until_format(const char *fm, int *i);
int	is_a_formatter(char c);

#endif // FT_PRINTF_H
