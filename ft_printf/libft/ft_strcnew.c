#include "libft.h"

char	*ft_strcnew(size_t size, int c)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size)
		str[i++] = c;
	str[i] = '\0';
	return (str);
}	
