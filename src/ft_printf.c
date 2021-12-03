/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossi <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:33:53 by arossi            #+#    #+#             */
/*   Updated: 2021/11/18 11:59:22 by arossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list		ap;
	int			i;
	int			ret;

	ret = 0;
	va_start(ap, s);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{	
			if (ft_is_inset(s[++i]))
				ret += ft_parsectl(s[i++], ap);
			
		}
		else
		{
			ft_putchar_fd(s[i++], 1);
			ret++;
		}
	}		
	va_end(ap);
	return (ret);
}

int	ft_print(char *str)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(str);
	if (check_str(str))
	{
		while (i < len)
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	if (str != NULL)
		free(str);
	return (i);
}

int	ft_is_inset(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' \
	|| c == 'u' || c == 'i' || c == 'x' \
	|| c == 'X' || c == '%' )
		return (1);
	return (0);
}
