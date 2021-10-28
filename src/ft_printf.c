#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list arglist;
	va_start(arglist, s);
	t_format	*formats;
	formats = parse_format(s);
	(void)formats;
	va_end(arglist);
	return (0);
}
