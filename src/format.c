#include "format.h"

t_format	*parse_format(const char *s)
{
	t_format	*formats;
	int		i;
	int		j;
	int		nbformat;
	char		type;

	i = 0;
	type = '0';
	nbformat = count_format(s);
	if (!s)
		return (NULL);	
	formats = malloc(sizeof(t_format) * nbformat);
	while(s[i] != '\0')
	{
		if(s[i] = '%')
		{
			if(isvalid_format(s[i + 1]))
			{
				type = s[i + 1];	
			}
		}
		if (type != '0')
			set_format(formats, j++, type);
		i += 2;
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

int	isvalid_format(char c)
{
	int	i;	
	char	*valid_format[AV_FORMAT];
	
	valid_format = {'c','s','p','d','i','u','x'};
	i = 0;
	while (i < AV_FORMAT - 1)
	{
		if(c == valid_format[i])
			return(1);
		i++;
	}
	return (0);
}

t_format	*set_format(t_format *formats, int index, char type)
{
	formats[index].type = type;	
	return (formats);
}
t_format	*set_value(t_format *formats, int index, void *value)
{
	char	type;
	
	type = formats[index].type;
	if (type == 'c')
		formats[index].c = (char)value;
	else if (type == 's')
		formats[index].s = (char *)value;
	else if (type == 'p')
		formats[index].vptr = &value;
	else if (type == 'd')
		formats[index].d = (int)value;
	else if (type == 'i')
		formats[index].i = (int)value;
	else if (type == 'u')
		formats[index].u = (unsigned int)value;
	else if (type == 'x')
		formats[index].x = (unsigned int)value;
}
