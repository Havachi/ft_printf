/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossi <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:57:41 by arossi            #+#    #+#             */
/*   Updated: 2021/10/27 13:03:02 by arossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	process_p(unsigned long long n)
{
	int	count;

	count = 0;
	count += ft_putstr_fd("0x", 1);
	count += process_hex(n, 'x');
	return (count);
}
