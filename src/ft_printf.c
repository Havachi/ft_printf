#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	t_format	*formats;
	formats = parse_format(s);
	return (0);
}

t_format	*parse_format(const char *s)
{
	t_format	*formats;
	int		i;
	int		nbformat;

	i = 0;
	nbformat = count_format(s);
	if (!s)
		return (NULL);
	
	while(s[i] != '\0')
	{
		if(s[i] = '%')
	}
}

int		count_format(const char *s)
{
	int	i;
	int	nbformat;
	
	i = 0;
	nbformat = 0;
	while (s[i] != '\0')
	{
		if (s[i] = '%')
		{	
			if(s[i+1] = '%')
				i++;
			nbformat++;
		}
		i++;
	}
	return (nbformat);
}
