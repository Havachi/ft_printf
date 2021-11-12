/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossi <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:47:39 by arossi            #+#    #+#             */
/*   Updated: 2021/11/11 16:27:17 by arossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int	ft_printf(const char *s, ...);
void	ft_print(char *str);
void	ft_parsectl(char fmt, va_list ap);
char	*ft_convert_c(char c);
char	*ft_convert_ptr(void *ptr);
char	*ft_convert_num(int i);
char	*ft_convert_x(unsigned long x, int upper);
#endif
