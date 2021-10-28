#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
typedef struct	s_format
{
	char *type;
	union
	{
		char		c;
		char		*s;
		void		*vptr;
		int		d;
		int		i;
		unsigned int 	u;
		unsigned int 	x;
	}
} t_format; 
int	ft_printf(const char *, ...);
t_format	*parse_format(const char *s);
#endif
