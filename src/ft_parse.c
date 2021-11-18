/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossi <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:32:34 by arossi            #+#    #+#             */
/*   Updated: 2021/11/18 15:51:43 by arossi           ###   ########.fr       */
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
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}

int	ft_parse_num(char c, va_list ap)
{
	char	*str;
	size_t	len;

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
	len = ft_strlen(str);
	free(str);
	return (len);
}

int	ft_parse_hex(char c, va_list ap)
{
	int		len;
	int		upper;
	void	*arg;
	char	*str;

	len = 0;
	upper = 0;
	str = ft_calloc(20, sizeof(char));
	if (c == 'X')
		upper = 1;
	arg = va_arg(ap, void *);
	printf("[DEBUG parse] arg = %p", arg);
	str = ft_convert_hex((unsigned int)arg, str, upper);
	printf("[DEBUG parse] str = %s \n", str); 
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str) + 2;
	free(str);
	return (len);
}
