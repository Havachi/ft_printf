#ifndef FORMAT_H
# define FORMAT_H
# define AV_FORMAT 7
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
		unsigned int	u;
		unsigned int	x;
	};
}		t_format;
t_format	*parse_format(const char *s);
int		count_format(const char *s);
int		isvalid_format(char c);
t_format	*set_format(t_format *formats, int index, char type);
#endif
