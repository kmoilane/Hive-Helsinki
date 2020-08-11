#include "libft.h"

/*
 *	Prints nb amount of characters c. Returns the amount of printed characters.
 *
 */

int		printnc(int nb, char c)
{
	int i;

	i = 0;
	while (nb > 0)
	{
		ft_putchar(c);
		i++;
		nb--;
	}
	return (i);
}
