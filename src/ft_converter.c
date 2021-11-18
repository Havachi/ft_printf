/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossi <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:50:02 by arossi            #+#    #+#             */
/*   Updated: 2021/11/18 16:12:21 by arossi           ###   ########.fr       */
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
	int		count;

	printf("[DEBUG]\nx = %llu\nstr = %s\n", x, str);
	count = 0;
	if (x > 15)
	{
		str = ft_strcat(str, ft_convert_hex(x / 16, str, upper));
		str = ft_strcat(str, ft_convert_hex(x % 16, str, upper));
	}
	else
	{

		printf("[DEBUG]\n x = %s\n",(char *)(x - 10 + 'a' ));
		if (x <= 9)
			str = ft_strcat(str, (const char *)(x + '0'));
		else
		{
			if (upper)
				str = ft_strcat(str, (const char *)(x - 10 + 'A'));
			else
				str = ft_strcat(str, (const char *)(x - 10 + 'a'));
		}
	}
	return (str);
}
