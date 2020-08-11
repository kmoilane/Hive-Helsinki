#include "../includes/ft_printf.h"

void	flags(const char *format, t_struct *s)
{
	while (ft_strchr("-+ #0", format[s->pos]))
	{
		if (format[s->pos] == '-')
			s->minus = 1;
		if (format[s->pos] == '+')
			s->plus = 1;
		if (format[s->pos] == ' ')
			s->space = 1;
		if (format[s->pos] == '#')
			s->hash = 1;
		if (format[s->pos] == '0')
			s->zero = 1;
		s->pos++;
	}
	if (s->plus == 1)
		s->space = 0;
}

void	width(const char *format, t_struct *s, va_list ap)
{
	if (format[s->pos] >= '0' && format[s->pos] <= '9')
		s->width = ft_atoi(&format[s->pos]);
	else if (format[s->pos] == '*')
		s->width = va_arg(ap, int);
	s->pos += ft_intlen(s->width);
}

void	precision(const char *format, t_struct *s, va_list ap)
{
	if (format[s->pos] == '.')
	{
		s->precisiontf = 1;
		s->pos++;
		if (format[s->pos] == '*')
		{
			s->precision = va_arg(ap, int);
			s->precisiontf = s->precision >= 0 ? 1 : -1;
			s->pos++;
		}
		else
			s->precision = ft_atoi(&format[s->pos]);
		s->pos += ft_intlen(s->precision);
	}
	else
		s->precisiontf = -1;
}

void	length(const char *format, t_struct *s)
{
	if (format[s->pos] == 'h')
	{
		if (format[s->pos + 1] == 'h')
			s->length = HH;
		else if (format[s->pos + 1] != 'h')
			s->length = H;
	}
	if (format[s->pos] == 'l')
	{
		if (format[s->pos + 1] == 'l')
			s->length = LL;
		else if (format[s->pos + 1] != 'l')
			s->length = L;
	}
	(format[s->pos] == 'L') ? s->length = BIGL : 0;
	(format[s->pos] == 'z') ? s->length = Z : 0;
	s->pos += ft_intlen(s->length);
}

void	modifiers(const char *format, t_struct *s, va_list ap)
{
	flags(format, s);
	width(format, s, ap);
	precision(format, s, ap);
	length(format, s);
}
