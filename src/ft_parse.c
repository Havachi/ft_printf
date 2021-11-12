/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossi <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:32:34 by arossi            #+#    #+#             */
/*   Updated: 2021/11/12 17:09:23 by arossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parsectl(char c, va_list ap)
{
	if (c == 'c' || c == 's' || c == '%')
		return (ft_parse_char(c, ap));
	if (c == 'd' || c == 'i' || c == 'u')
		return (ft_parse_num(c, ap));
	if (c == 'p' || c == 'x' || c == 'X')
		return (ft_parse_hex(c, ap));
	else
		return (0);
}

int	ft_parse_char(char c, va_list ap)
{
	char	*str;

	if (c == 'c')
	{
		ft_putchar_fd((char)va_arg(ap, void *), 1);
		return (1);
	}
	if (c == 's')
	{
		str = (char *)va_arg(ap, void *);
		if (str != NULL)
		{
			ft_putstr_fd(str, 1);
			return (ft_strlen(str));
		}
		ft_putstr_fd("(null)", 1);
		return (6);
	}	
	if (c == '%')
	{
		ft_putchar_fd((char)va_arg(ap, void *), 1);
		return (1);
	}
	return (0);
}

int	ft_parse_num(char c, va_list ap)
{
	char	*str;

	str = NULL;
	if (c == 'd' || c == 'i')
	{
		str = ft_itoa((int)va_arg(ap, void *));
	}
	else if (c == 'u')
	{
		str = ft_utoa((unsigned int)va_arg(ap, void *));
	}
	if (str == NULL)
		return (0);
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ft_parse_hex(char c, va_list ap)
{
	char			*str;

	if (c == 'p')
	{
		str = ft_convert_x((unsigned long)va_arg(ap, void *), 0);
		str = ft_strcat("0x", str);
		ft_putstr_fd(str, 1);
	}
	else if (c == 'x')
		return (ft_print(ft_convert_x(va_arg(ap, int), 0)));
	else if (c == 'X')
		return (ft_print(ft_convert_x(va_arg(ap, int), 1)));
	return (0);
}
