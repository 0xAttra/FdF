/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_until_format.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:42:03 by macuesta          #+#    #+#             */
/*   Updated: 2024/11/15 09:47:36 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_print_until_format(const char *fm, int *i)
{
	int	k;

	k = 0;
	while (fm && fm[k] && !(fm[k] == '%' && is_a_formatter(fm[k + 1])))
		k++;
	write(1, fm, k);
	*i += k;
	return (k);
}
