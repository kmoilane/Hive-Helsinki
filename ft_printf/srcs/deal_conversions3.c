#include "../includes/ft_printf.h"

char	*check_hex_len(unsigned long n, t_struct *s, va_list ap)
{
	if (s->length == L)
		n = (unsigned long int)va_arg(ap, uintmax_t);
	if (s->length == LL)
		n = (unsigned long long int)va_arg(ap, uintmax_t);
	if (s->length == H)
		n = (unsigned short)va_arg(ap, int);
	if (s->length == HH)
		n = (unsigned char)va_arg(ap, int);
	if (s->length == Z)
		n = (size_t)va_arg(ap, size_t);
	if (s->length == 0)
		n = (unsigned int)va_arg(ap, unsigned int);
	return (ft_itoa_base(n, 16));
}

void	dealhex(t_struct *s, va_list ap)
{
	unsigned long	n;
	char			*str;
	int				len;

	n = 0;
	str = check_hex_len(n, s, ap);
	(str[0] == '0' && s->precision == -1) ? str[0] = '\0' : 0;
	if (s->x == 1)
		ft_strupper(str);
	if (s->hash && str[0] != '0' && str[0] != '\0')
	{
		s->nb = s->precision - ft_strlen(str);
		(s->x == 1) ? str = pre_converter(str, s, 'X', 0) : 0;
		(s->x == 0) ? str = pre_converter(str, s, 'x', 0) : 0;
	}
	len = ft_strlen(str);
	(!s->hash) ? s->nb = s->precision - len : 0;
	(s->hash && str[1] == '\0') ? s->nb = s->precision - len : 0;
	if (s->precision > 0 && s->nb > 0)
		str = pre_converter(str, s, '0', 1);
	(s->minus == 1) ? str = leftalign(s, str) : 0;
	(s->minus == 0) ? str = rightalign(s, str) : 0;
	ft_putstr(str);
	s->printedn += ft_strlen(str);
	ft_strdel(&str);
}

char	*check_float_len(long double n, t_struct *s, va_list ap)
{
	if (s->length == BIGL)
		n = (long double)va_arg(ap, long double);
	else
		n = (long double)va_arg(ap, double);
	(n < 0) ? s->sign = 1 : 0;
	if (s->precision == 0)
	{
		s->precision = 6;
		s->precisiontf = 1;
	}
	else if (s->hash && s->precisiontf == -1 && !s->precision && n != 0)
	{
		s->precisiontf = 1;
		s->precision = 0;
	}
	return (ft_ftoa(n, s->precisiontf, s->precision));
}

void	dealfloat(t_struct *s, va_list ap)
{
	char		*str;
	long double	n;

	n = 0;
	str = check_float_len(n, s, ap);
	s->nb = s->precision - ft_strlen(str);
	if (s->space && !s->sign)
	{
		s->nb = 1;
		str = pre_converter(str, s, ' ', 2);
	}
	if (((s->plus && !s->sign) || s->sign) && str[0] != '-')
		str = pre_converter(str, s, '+', 3);
	if (s->minus == 1)
		str = leftalign(s, str);
	else if (s->minus == 0)
		str = rightalign(s, str);
	ft_putstr(str);
	s->printedn += ft_strlen(str);
	ft_strdel(&str);
}
