#include "../includes/ft_printf.h"

char	*pre_converter(char *str, t_struct *s, char c, int status)
{
	char	*tmp;
	char	*joint;

	if (status == 0)
	{
		(str[0] = '0' && c == '0') ? joint = ft_strdup(str) : 0;
		(str[0] != '0' && c == '0') ? joint = ft_strjoin("0", str) : 0;
		(c == 'x') ? joint = ft_strjoin("0x", str) : 0;
		(c == 'X') ? joint = ft_strjoin("0X", str) : 0;
	}
	if (status == 1 || status == 2)
	{
		tmp = ft_strcnew(s->nb, c);
		joint = ft_strjoin(tmp, str);
		free(tmp);
	}
	if (status == 3)
		if ((s->plus && !s->sign) || s->sign)
		{
			(s->plus && !s->sign) ? joint = ft_strjoin("+", str) : 0;
			(s->sign) ? joint = ft_strjoin("-", str) : 0;
		}
	free(str);
	return (joint);
}

char	*left_convert(char *str, size_t nb, t_struct *s, char c)
{
	char	*joint;
	char	*tmp;
	int		i;

	joint = NULL;
	tmp = NULL;
	i = 0;
	tmp = ft_strcnew(nb, c);
	joint = ft_strjoin(str, tmp);
	free(tmp);
	free(str);
	if (s->hash && s->conv2 && (s->width || s->precision))
		joint = swap2(joint, 'c', i, 1);
	return (joint);
}

char	*right_convert(char *str, size_t nb, t_struct *s, char c)
{
	char	*joint;
	char	*tmp;
	int		i;

	joint = NULL;
	tmp = NULL;
	tmp = ft_strcnew(nb, c);
	joint = ft_strjoin(tmp, str);
	i = 0;
	free(tmp);
	free(str);
	if (s->zero && s->width && (s->plus || s->minus) && 
		!s->precision && !s->conv1)
		joint = swap1(joint, c, i, 1);
	else if (s->zero && s->width && (s->sign || s->plus) && s->conv3)
		joint = swap1(joint, c, i, 1);
	if (s->hash && s->conv2 && (s->width || s->precision))
		joint = swap2(joint, c, i, 2);
	(s->space && s->width) ? joint = swap1(joint, c, i, 2) : 0;
	return (joint);
}

char	*leftalign(t_struct *s, char *str)
{
	int		nb;
	char	*joint;

	joint = NULL;
	nb = s->width - ft_strlen(str);
	if (nb > 0)
		return (joint = right_convert(str, nb, s, ' '));
	if (nb < 0 && s->nb > 0 && s->conv2)
		return (joint = swap2(str, '0', 0, 1));
	return (str);
}

char	*rightalign(t_struct *s, char *str)
{
	int		nb;
	char	*joint;

	joint = NULL;
	nb = s->width - ft_strlen(str);
	if (nb > 0)
	{
		if (s->zero == 1 && s->width > 0 && !s->sign && !s->precision)
			return (joint = right_convert(str, nb, s, '0'));
		else if (s->zero && s->width > 0 && s->conv3)
			return (joint = right_convert(str, nb, s, '0'));
		else if (s->zero && !s->precision)
		{
			joint = right_convert(str, nb, s, '0');
			return (joint = swap1(joint, '+', 0, 1));
		}
		else
			return (joint = right_convert(str, nb, s, ' '));
	}
	if (nb < 0 && s->nb > 0 && s->conv2)
		return (joint = swap2(str, '0', 0, 2));
	return (str);
}
