#include "../includes/ft_printf.h"


void	initstruct(t_struct *s)
{
	s->printedn = 0;
	s->len = 0;
	s->minus = 0;
	s->plus = 0;
	s->space = 0;
	s->zero = 0;
	s->hash = 0;
	s->width = 0;
	s->precisiontf = 0;
	s->precision = 0;
	s->length = 0;
}

int		parsel(t_struct *s, int pos, const char *format, va_list ap)
{
	s->pos = pos;
	if (ft_strchr(FLAGS, format[pos]))
		modifiers(format, s, ap);
	else
	{
		typedetect(s, format[pos], ap);
		initstruct(s);
	}
	pos = s->pos;
	if (format[pos] == '\0')
		return (pos);
	return (pos - 1);
}

int		formatparse(const char *format, t_struct *s, va_list ap, int pos)
{
	while (format[pos] != '\0')
	{
		if (format[pos] != '%')
			s->printedn += write(1, &format[pos], 1);
		else if (format[pos] == '%')
		{
			if (!(ft_strchr(ALL, format[pos + 1]) || format[pos] == '\0'))
				break ;
			while (ft_strchr(ALL, format[pos + 1]) && format[pos] != '\0')
			{
				pos++;
				if (ft_strchr(CONVERS, format[pos]))
				{
					pos = parsel(s, pos, format, ap) + 2;
					break ;
				}
				else
					pos = parsel(s, pos, format, ap);
			}
			continue;
		}
		pos++;
	}
	return (s->printedn);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			status;
	t_struct	*s;
	int			fmtlen;

	if (!(s = (t_struct*)malloc(sizeof(t_struct))))
		return (0);
	initstruct(s);
	s->pos = 0;
	s->format = (char *)format;
	va_start(ap, format);
	fmtlen = ft_strlen(format);
	if (!fmtlen || (fmtlen = 1 && format[0] == '%'))
		return (0);
	status = formatparse(format, s, ap, 0);
	va_end(ap);
	free(s);
	return (status);
}
