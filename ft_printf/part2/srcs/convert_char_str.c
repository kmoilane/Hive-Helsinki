#include "../includes/ft_printf.h"

void	convert_char(t_printf *data_t, va_list ap)
{
	unsigned char	c;
	int				nb;

	nb = data_t->width - 1;
	c = (unsigned char)va_arg(ap, int);
	if (data_t->minus == 0 && data_t->width)
		data_t->total_printed += printnc(nb, ' ');
	if (data_t->minus == 1 && data_t->width)
	{
		ft_putchar(c);
		data_t->total_printed += printnc(nb, ' ');
	}
	else
		ft_putchar(c);
	data_t->total_printed++;
}

/*
 *	TODO: Fix the string return. Currently on linux, freeing tmp will
 *	cause the str to be empty, and if tmp isn't freed, it will cause
 *	a leak.
 */

static char	*str_precision(char *str, int precision)
{
	char	*temp;

	if (precision > 0 && (size_t)precision <= ft_strlen(str))
	{
		temp = ft_strndup(str, precision);
		str = temp;
		free(temp);
		return (str);
	}
	if (precision == 0)
		str = "";
	return (str);
}

void	convert_string(t_printf *data_t, va_list ap)
{
	char			*str;
	int				nb;

	str = (char *)va_arg(ap, char *);
	(str == NULL) ? str = "(null)" : 0;
	str = str_precision(str, data_t->precision);
	nb = data_t->width - ft_strlen(str);
	if (data_t->minus == 0 && nb > 0)
		data_t->total_printed += (data_t->zero == 1) ? printnc(nb, '0') :
			printnc(nb, ' ');
	if (data_t->minus == 1 && nb > 0)
	{
		ft_putstr(str);
		data_t->total_printed += printnc(nb, ' ');
	}
	else
		ft_putstr(str);
	data_t->total_printed += ft_strlen(str);
}
