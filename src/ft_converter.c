/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossi <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:50:02 by arossi            #+#    #+#             */
/*   Updated: 2021/12/03 14:21:11 by arossi           ###   ########.fr       */
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

char	*ft_convert_hex(unsigned long long x, char *str, int upper)
{
	if (x == 0)
		str = "0";
	else{
		if (upper)
			return (ft_ulltoau(x,str,16));
		return (ft_ulltoa(x,str,16));
	}
	return (str);
}
