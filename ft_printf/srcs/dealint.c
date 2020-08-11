#include "../includes/ft_printf.h"

static char	*check_int_len(intmax_t n, t_struct *s, va_list  ap)
{
	if (s->length == L)
		n = (long int)va_arg(ap, long int);
	else if (s->length == LL)
		n = (long long int)va_arg(ap, long long int);
	else if (s->length == H)
		n = (short int)va_arg(ap, int);
	else if (s->length == HH)
		n = (signed char)va_arg(ap, int);
	else if (s->length == Z)
		n = (size_t)va_arg(ap, size_t);
	else if (s->length == 0)
		n = (int)va_arg(ap, int);
	if (n < 0)
	{
		s->sign = 1;
		n *= -1;
	}
	return (ft_itoa_base(n, 10));
}

void		dealint(t_struct *s, va_list ap)
{
	intmax_t	n;
	char		*str;

	n = 0;
	str = check_int_len(n, s, ap);
	s->nb = s->precision - ft_strlen(str);
	(str[0] == '0' && s->precision == -1) ? str[0] = '\0' : 0;
	if (s->precision > 0 && s->nb > 0)
		str = pre_converter(str, s, '0', 1);
	if (s->space && !s->sign)
	{
		s->nb = 1;
		str = pre_converter(str, s, ' ', 2);
	}
	if ((s->plus && !s->sign) || s->sign)
		str = pre_converter(str, s, '+', 3);
	if (s->minus == 1)
		str  = leftalign(s, str);
	else if (s->minus == 0)
		str = rightalign(s, str);
	ft_putstr(str);
	s->printedn += ft_strlen(str);
	ft_strdel(&str);
}
