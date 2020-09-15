#include "../includes/ft_printf.h"

void			init_struct(t_printf *data_t)
{
	data_t->total_printed = 0;
	data_t->length = 0;
	data_t->conv_c = 'n';
	data_t->hash = 0;
	data_t->zero = 0;
	data_t->minus = 0;
	data_t->plus = 0;
	data_t->space = 0;
	data_t->width = 0;
	data_t->precision = -1;
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			total;
	int			format_len;
	t_printf	*data_t;

	if (!(data_t = (t_printf *)malloc(sizeof(t_printf))))
		return (0);
	init_struct(data_t);
	data_t->pos = 0;
	data_t->format = (char *)format;
	va_start(ap, format);
	format_len = ft_strlen(format);
	if (!format_len || (format_len == 1 && format[0] == '%'))
		return (0);
	total = parse_format(data_t, format, ap, 0);
	va_end(ap);
	free(data_t);
	return (total);
}
