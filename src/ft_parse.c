/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossi <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:32:34 by arossi            #+#    #+#             */
/*   Updated: 2021/11/11 16:35:09 by arossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
void	ft_parsectl(char c, va_list ap)
{
	if (c == 'c')	
	{
		char *sauce = ft_convert_c((char)va_arg(ap, int));
		ft_print(sauce);
	}
	else if (c == 's')
		ft_print(va_arg(ap, char *));
	else if (c == 'p')
		ft_putstr_fd(ft_convert_ptr(va_arg(ap, void *)), 1);
	else if (c == 'd' || c == 'i')
		ft_putstr_fd(ft_convert_num(va_arg(ap, int)), 1);
	else if (c == 'u')
		ft_putstr_fd(ft_convert_num(va_arg(ap, unsigned int)), 1);
	else if (c == 'x')
		ft_putstr_fd(ft_convert_x(va_arg(ap, int), 0), 1);
	else if (c == 'X')
		ft_putstr_fd(ft_convert_x(va_arg(ap, int), 1), 1);
	else if (c == '%')
		ft_putchar_fd(c, 1);
}
