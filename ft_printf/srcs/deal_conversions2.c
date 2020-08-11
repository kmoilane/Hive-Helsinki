#include "../includes/ft_printf.h"

void			dealpointer(t_struct *s, va_list ap)
{
	unsigned long long	p;
	char				*str;
	char				*joint;
	int					nb;

	p = va_arg(ap, unsigned long long);
	str = ft_itoa_base((unsigned long long)p, 16);
	(str[0] == '0' && s->precision == -1) ? str[0] = '\0' : 0;
	joint = ft_strjoin("0x", str);
	nb = s->width - (ft_strlen(joint));
	if (s->minus == 0 && nb > 0)
		(s->zero == 1) ? s->printedn += printnc(nb, '0') : 0;
			s->printedn += printnc(nb, ' ');
	if (s->minus == 1 && nb > 0)
	{
		ft_putstr(joint);
		s->printedn += printnc(nb, ' ');
	}
	else
		ft_putstr(joint);
	s->printedn += ft_strlen(joint);
	free(str);
	free(joint);
}

static	char	*check_octal_len(unsigned long n, t_struct *s, va_list ap)
{
	if (s->length == L)
		n = (unsigned long)va_arg(ap, unsigned long);
	else if (s->length == LL)
		n = (unsigned long long)va_arg(ap, unsigned long long);
	else if (s->length == H)
		n = (unsigned short)va_arg(ap, unsigned int);
	else if (s->length == HH)
		n = (unsigned char)va_arg(ap, unsigned int);
	else if (s->length == Z)
		n = (size_t)va_arg(ap, size_t);
	else if (s->length == 0)
		n = va_arg(ap, unsigned int);
	return (ft_itoa_base(n, 8));
}

void			dealoctal(t_struct *s, va_list ap)
{
	unsigned long	n;
	char			*str;

	n = 0;
	str = check_octal_len(n, s, ap);
	(str[0] == '0' && s->precision == -1) ? str[0] = '\0' : 0;
	if (s->hash)
		str = pre_converter(str, s, '0', 0);
	s->nb = s->precision - ft_strlen(str);
	if (s->precision > 0 && s->nb > 0)
		str = pre_converter(str, s, '0', 1);
	if (s->minus == 1)
		str = leftalign(s, str);
	else if (s->minus == 0)
		str = rightalign(s, str);
	ft_putstr(str);
	s->printedn += ft_strlen(str);
	ft_strdel(&str);
}

static char	*check_udi_len(unsigned long n, t_struct *s, va_list ap)
{
	if (s->length == L)
		n = (unsigned long int)va_arg(ap, long int);
	else if (s->length == LL)
		n = (unsigned long long int)va_arg(ap, long long int);
	else if (s->length == H)
		n = (unsigned short int)va_arg(ap, int);
	else if (s->length == HH)
		n = (unsigned char)va_arg(ap, int);
	else if (s->length == Z)
		n = (size_t)va_arg(ap, size_t);
	else if (s->length == 0)
		n = (unsigned int)va_arg(ap, unsigned int);
	return (ft_itoa_base(n, 10));
}

void	dealudi(t_struct *s, va_list ap)
{
	unsigned long	n;
	char			*str;

	n = 0;
	str = check_udi_len(n, s, ap);
	s->nb = s->precision - ft_strlen(str);
	(str[0] == '0' && s->precision == -1) ? str[0] = '\0' : 0;
	if (s->precision > 0 && s->nb > 0)
		str = pre_converter(str, s, '0', 1);
	if (s->minus == 1)
		str = leftalign(s, str);
	else if (s->minus == 0)
		str = rightalign(s, str);
	ft_putstr(str);
	s->printedn += ft_strlen(str);
	ft_strdel(&str);
}
