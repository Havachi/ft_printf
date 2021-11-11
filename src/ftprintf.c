/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossi <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:33:53 by arossi            #+#    #+#             */
/*   Updated: 2021/11/11 16:44:45 by arossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;

	va_start(ap, s);
	i = 0;
	while (s[i])
	{
		while (s[i] != '%' && s[i] != '\0')
		{	
			ft_putchar_fd(s[i], 1);
			i++;
		}
		if (s[i] == '\0')
			break ;
		else if (s[i] == '%')
			ft_parsectl(s[i + 1], ap);
		i++;
	}
	va_end(ap);
	return (0);
}

void	ft_print(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (len > 0)
		ft_putstr_fd(str, 1);
}
