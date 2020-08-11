#include "../includes/ft_printf.h"

void	dealperc(t_struct *s)
{
	int	nb;

	nb = s->width - 1;
	if (s->minus == 0 && s->width)
	{
		if (s->zero == 1)
			s->printedn += printnc(nb, '0');
		else
			s->printedn += printnc(nb, ' ');
	}
	if (s->minus == 1 && s->width)
	{
		ft_putchar('%');
		s->printedn += printnc(nb, ' ');
	}
	else
		ft_putchar('%');
	s->printedn++;
}

void	dealchar(t_struct *s, va_list ap)
{
	unsigned char	c;
	int				nb;

	nb = s->width - 1;
	c = (unsigned char)va_arg(ap, int);
	if (s->minus == 0 && s->width)
	{
		if (s->zero == 1)
			s->printedn += printnc(nb, '0');
		else if (!s->zero)
			s->printedn += printnc(nb, ' ');
	}
	if (s->width && s->minus == 1)
	{
		ft_putchar(c);
		s->printedn += printnc(nb, ' ');
	}
	else
		ft_putchar(c);
	s->printedn++;
}

static char	*str_precision(char *str, int n)
{
	char	*tmp;

	if (n > 0 && (size_t)n <= ft_strlen(str))
	{
		tmp = ft_strndup(str, n);
		str = tmp;
		free(tmp);
		return (str);
	}
	if (n == -1)
		str = "";
	return (str);
}

void	dealstring(t_struct *s, va_list ap)
{
	char	*str;
	int		nb;

	str = va_arg(ap, char*);
	(str == NULL) ? str = "(null)" : 0;
	str = str_precision(str, s->precision);
	nb = s->width - ft_strlen(str);
	if (s->minus == 0 && nb > 0)
	{
		if (s->zero == 1)
			s->printedn += printnc(nb, '0');
		else
			s->printedn += printnc(nb, ' ');
	}
	if (s->minus == 1 && nb > 0)
	{
		ft_putstr(str);
		s->printedn += printnc(nb, ' ');
	}
	else
		ft_putstr(str);
	s->printedn += ft_strlen(str);
}
