#include "libft.h"

static int	helper_f(long value, int base, int state)
{
	int		neg;

	if (state == 1)
	{
		neg = 0;
		if (base < 2 || base > 36)
			exit (0);
		if (base == 10 && value < 0)
			neg = 1;
		return (neg);
	}
	else if (state == 2)
	{
		if (value < 0)
			value *= -1;
		return (value % base);
	}
	return (0);
}

char		*ft_itoa_base(unsigned long long value, int base)
{
	long	num;
	char	*str;
	char	*list;
	int		neg;
	int		size;

	list = "0123456789abcdefghijklmnopqrstuvwxyz";
	neg = 0;
	neg = helper_f(value, base, 1);
	size = neg + 1;
	num = value;
	while (num /= base)
		size++;
	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (0);
	str[size--] = '\0';
	while (value)
	{
		str[size--] = list[helper_f(value, base, 2)];
		value /= base;
	}
	if (neg == 1)
		str[0] = '-';
	return (str);
}
