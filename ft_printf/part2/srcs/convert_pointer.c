#include "../includes/ft_printf.h"

/*
 *	TODO Fix the precision zeroes. Find out what is undefined behaviour in
 *	real printf and what is not.
 */

void	convert_pointer(t_printf *data_t, va_list ap)
{
	unsigned long long	p;
	char				*str;
//	char				*joint;
	int					nb;

	p = va_arg(ap, unsigned long long);
	str = ft_itoa_base((unsigned long long)p, 16);
	(str[0]== '0' && data_t->precision == 0) ? str[0] = '\0' : 0;
	nb = (data_t->width > data_t->precision) ? data_t->width -
		(ft_strlen(str)) - 2 : data_t->precision - ft_strlen(str) - 2;
	ft_putstr("0x");
	data_t->total_printed += 2;
	if (data_t->minus == 0 && nb > 0)
		data_t->total_printed += (data_t->zero == 1) ? printnc(nb, '0') :
		printnc(nb, ' ');
	if (data_t->minus == 1 && nb > 0)
	{
		ft_putstr(str);
		data_t->total_printed += printnc(nb, ' ');
	}
	else
	{
		ft_putstr(str);
	}
	data_t->total_printed += ft_strlen(str);
	free(str);
//	free(joint);
}
