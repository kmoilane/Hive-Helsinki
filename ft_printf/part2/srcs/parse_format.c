#include "../includes/ft_printf.h"

/*
 *	TODO: Obviously.. Create the missing functions for ints, octals,
 *	unsigned decimal ints, hexadecimals and floats.
 */

static void	detect_type(t_printf *data_t, char c, va_list ap)
{
	(c == 'c') ? convert_char(data_t, ap) : 0;
	(c == 's') ? convert_string(data_t, ap) : 0;
	(c == 'p') ? convert_pointer(data_t, ap) : 0;
//	(c == 'd' || c == 'i') ? convert_int(data_t, ap) : 0;
	if (c == '%')
	{
		ft_putchar('%');
		data_t->total_printed++;
	}
/*	if (c == 'o' || c == 'u' || c == 'x' || c == 'X')
	{
		data_t->conv_c = 'u';
		(c == 'o') ? convert_octal(data_t, ap) : 0;
		(c == 'u') ? convert_u_int(data_t, ap) : 0;
		if (c == 'x' || c == 'X')
		{
			(c == 'x') ? data_t->conv_c = 'x' : data_t->conv_c = 'X';
			convert_hexa(data_t, ap);
		}
	}
	if (c == 'f')
	{
		data_t->conv_c = 'f';
		convert_float(data_t, ap);
	}*/
}

static void	get_modifiers(t_printf *data_t, const char *format, va_list ap)
{
	get_flags(data_t, format);
	get_width(data_t, format, ap);
	get_precision(data_t, format, ap);
	get_length(data_t, format);
}

int	detect_specifier(t_printf *data_t, const char *format, va_list ap, int pos)
{
	data_t->pos = pos;
	if (ft_strchr(FLAGS, format[pos]))
		get_modifiers(data_t, format, ap);
	else
	{
		detect_type(data_t, format[pos], ap);
		init_struct(data_t);
	}
	pos = data_t->pos;
	if (format[pos] =='\0')
		return (pos);
	return (pos - 1);
}

int	parse_format(t_printf *data_t, const char *format, va_list ap, int pos)
{
	while (format[pos] != '\0')
	{
		if (format[pos] != '%')
			data_t->total_printed += write(1, &format[pos], 1);
		else if (format[pos] == '%')
		{
			if (!(ft_strchr(ALL, format[pos + 1]) || format[pos] == '\0'))
				break ;
			while (ft_strchr(ALL, format[pos + 1]) && format[pos] != '\0')
			{
				pos++;
				if (ft_strchr(CONVERS, format[pos]))
				{
					pos = detect_specifier(data_t, format, ap, pos) + 2;
					break ;
				}
				else
					pos = detect_specifier(data_t, format, ap, pos);
			}
			continue ;
		}
		pos++;
	}
	return (data_t->total_printed);
}
