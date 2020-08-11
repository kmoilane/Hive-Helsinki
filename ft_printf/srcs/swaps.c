#include "../includes/ft_printf.h"

char	*swap1(char *joint, char c, int i, int state)	
{
	if (state == 1)
	{
		while (joint[i] != '+' && joint[i] != '-' && joint[i])
			i++;
		if (joint[i] == '+' || joint[i] == '-')
		{
			c = joint[i];
			joint[i] = '0';
			joint[0] = c;
		}
	}
	else if (state == 2)
	{
		while (joint[i] != ' ' && joint[i])
			i++;
		if (joint[i] == ' ')
		{
			c = joint[i];
			joint[i] = '0';
			joint[0] = c;
		}
	}
	return (joint);
}

char	*swap2(char *joint, char c, int i, int state)
{
	while (joint[i] != 'x' && joint[i] != 'X' && joint[i])
		i++;
	if (joint[i] == 'x' || joint[i] == 'X')
	{
		c = joint[i];
		joint[i] = '0';
		if (state == 1)
			joint[1] = c;
		else if (state == 2)
		{
			i = 0;
			while (joint[i] == ' ' || joint[i] == '\t' || joint[i] == '\n')
				i++;
			joint[i + 1] = c;
		}
	}
	return (joint);
}
