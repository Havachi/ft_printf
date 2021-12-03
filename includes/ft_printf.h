/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arossi <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:47:39 by arossi            #+#    #+#             */
/*   Updated: 2021/11/18 15:52:36 by arossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

int		ft_printf(const char *s, ...);
int		ft_print(char *str);
int		ft_is_inset(char c);
int		ft_parsectl(char c, va_list ap);
int		ft_parse_char(char c, va_list ap);
int		ft_parse_num(char c, va_list ap);
int		ft_parse_hex(char c, va_list ap);
int		ft_parse_ptr(va_list ap);
char	*ft_convert_c(int c);
char	*ft_convert_s(char *s);
char	*ft_convert_ptr(void *ptr);
char	*ft_convert_int(int i);
char	*ft_convert_uint(unsigned int u);
char	*ft_convert_hex(unsigned long long x, char *str, int upper);
int		check_str(char *str);
#endif
