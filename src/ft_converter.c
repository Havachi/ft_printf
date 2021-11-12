/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossi <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:50:02 by arossi            #+#    #+#             */
/*   Updated: 2021/11/12 17:09:21 by arossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*ft_convert_c(int c)
{
	char	*str;

	str = NULL;
	str = (char *)ft_calloc(2, sizeof(char));
	if (str == NULL)
		return (NULL);
	str[0] = (char)c;
	str[1] = '\0';
	return (str);
}

char	*ft_convert_s(char *s)
{
	if (check_str(s))
		return (s);
	return (NULL);
}

char	*ft_convert_x(unsigned long x, int upper)
{
	char	*ret;
	int		i;

	i = 18;
	ret = (char *)calloc(18, sizeof(char));
	if (x == 0)
	{
		free(ret);
		return (0);
	}
	if (x < 0)
		ft_convert_x(INT_MAX - (x * -1), upper);
	while (x > 0)
	{
		if (upper)
			ret[i] = "0123456789ABCDEF"[x % 16];
		else
			ret[i] = "0123456789abcdef"[x % 16];
		x /= 16;
		i++;
	}
	return (ret);
}
