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

int	process_u(unsigned long long n)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count = process_u(n / 10);
		count += ft_putchar_fd((n % 10) + '0', 1);
	}
	else
		count += ft_putchar_fd(n + '0', 1);
	return (count);
}
