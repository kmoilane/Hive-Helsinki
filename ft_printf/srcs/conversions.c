#include "../includes/ft_printf.h"

/*
 *	Detects which conversion will be used and goes to that specific function.
 *	I use ternary operators to save some space, the way it works here is:
 *	if this or this is true do this (?), else do nothing (: 0;)
 *	
 *	dealint is found in dealint.c
 *	dealchar, dealperc and dealstring are found in deal_conversions1.c
 *	dealpointer, dealoctal and deal udi are found in deal_conversions2.c
 *	dealhex and dealfloat are found in deal_conversions3.c
 */

void	typedetect(t_struct *s, char c, va_list ap)
{
	(c == 'd' || c == 'i') ? dealint(s, ap) : 0;
	(c == 'c') ? dealchar(s, ap) : 0;
	(c == 's') ? dealstring(s, ap) : 0;
	(c == 'p') ? dealpointer(s, ap) : 0;
	(c == '%') ? dealperc(s) : 0;
	if (c == 'o' || c == 'u' || c == 'x' || c == 'X')
	{
		s->conv1 = 1;
		(c == 'o') ? dealoctal(s, ap) : 0;
		(c == 'u') ? dealudi(s, ap) : 0;
		if (c == 'x' || c == 'X')
		{
			s->conv2 = 1;
			(c == 'X') ? s->x = 1 : 0;
			dealhex(s, ap);
		}
	}
	if (c == 'f')
	{
		s->conv3 = 1;
		dealfloat(s, ap);
	}
}

