#include "../includes/ft_printf.h"

void	get_flags(t_printf *data_t, const char *format)
{
	while (ft_strchr("#0-+ ", format[data_t->pos]))
	{
		if (format[data_t->pos] == '#')
			data_t->hash = 1;
		if (format[data_t->pos] == '0')
			data_t->zero = 1;
		if (format[data_t->pos] == '-')
			data_t->minus = 1;
		if (format[data_t->pos] == '+')
			data_t->plus = 1;
		if (format[data_t->pos] == ' ')
			data_t->space = 1;
		data_t->pos++;
	}
	if (data_t->plus == 1)
		data_t->space = 0;	
}

void	get_width(t_printf *data_t, const char *format, va_list ap)
{
	if (format[data_t->pos] >= '0' && format[data_t->pos] <= '9')
		data_t->width = ft_atoi(&format[data_t->pos]);
	else if (format[data_t->pos] == '*')
		data_t->width = va_arg(ap, int);
	data_t->pos += ft_intlen(data_t->width);
}

void	get_precision(t_printf *data_t, const char *format, va_list ap)
{
	if (format[data_t->pos] == '.')
	{
		data_t->pos++;
		if (format[data_t->pos] > '0' && format[data_t->pos] <= '9')
		{
			data_t->precision = ft_atoi(&format[data_t->pos]);
			data_t->pos += ft_intlen(data_t->precision);
		}
		else if (format[data_t->pos] == '*')
		{
			data_t->precision = va_arg(ap, int);
			data_t->pos++;
		}
		else
			data_t->precision = 0;
	}
}

void	get_length(t_printf *data_t, const char *format)
{
	if (ft_strchr(LENGTH, format[data_t->pos]))
	{
		if (format[data_t->pos] == 'h')
			data_t->length = (format[data_t->pos + 1] == 'h') ? HH : H;
		if (format[data_t->pos] == 'l')
			data_t->length = (format[data_t->pos + 1] == 'l') ? LL : L;
		(format[data_t->pos] == 'L') ? data_t->length = CAPL : 0;
		data_t->pos += ft_intlen(data_t->length);
	}
}
