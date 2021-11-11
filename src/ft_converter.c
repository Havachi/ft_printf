/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossi <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:50:02 by arossi            #+#    #+#             */
/*   Updated: 2021/11/11 16:27:34 by arossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convert_ptr(void *ptr)
{
	char	*ret;

	ret = ft_convert_x((unsigned long)ptr, 0);
	return (ret);
}

char	*ft_convert_num(int i)
{
	char	*ret;

	ret = ft_itoa(i);
	return (ret);
}

char	*ft_convert_x(unsigned long x, int upper)
{
	char	*ret;
	int		i;

	i = 17;
	ret = malloc(sizeof(char) * 18);
	ret[i--] = '\0';
	if (x == 0)
		return (0);
	if (x < 0)
		ft_convert_x(INT_MAX - (x * -1), upper);
	while (x > 0)
	{
		if (upper)
			ret[i] = "0123456789ABCDEF"[x % 16];
		else
			ret[i] = "0123456789abcdef"[x % 16];
		i++;
	}
	return (ret);
}
