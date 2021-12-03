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
	if (c == 'x' || c == 'X')
		return (ft_parse_hex(c, ap));
	if (c == 'p')
		return (ft_parse_ptr(ap));
	else
		return (0);
}

int	ft_parse_char(char c, va_list ap)
{
	char	*str;
	char 	chr;

	if (c == 'c')
	{
		chr = (int)va_arg(ap, int);
		write(1, &chr, 1);
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
	if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(ap, int), 1));
	else if (c == 'u')
		return (ft_putnbr_fd(va_arg(ap, unsigned int), 1));
	return(0);
}

int	ft_parse_hex(char c, va_list ap)
{
	int		len;
	int		upper;
	void		*arg;
	char		*str;

	len = 0;
	upper = 0;
	str = malloc(sizeof(char) * 20 + 2);
	if (!str)
		return(-1);
	if (c == 'X')
		upper = 1;
	arg = va_arg(ap, void *);
	str = ft_convert_hex((unsigned long long)arg, str, upper);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str) + 2;
	free(str);
	return (len);
}

int 	ft_parse_ptr(va_list ap)
{
	int	len;
	void	*arg;
	char	*str;
	
	len = 0;
	str = malloc(sizeof(char) * 20 + 2);
	if (str == NULL)
		return(-1);
	arg = va_arg(ap, void *);	
	ft_putstr_fd("0x", 1);
	if(arg == ((void *)0) || arg == 0)
		str = "0";
	else
		str = ft_convert_hex((unsigned long long)arg, str, 0);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str) + 2;
	if (sizeof(str))
		free(str);
	return (len);
}
