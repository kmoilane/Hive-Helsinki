/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:45:28 by kmoilane          #+#    #+#             */
/*   Updated: 2019/11/07 21:00:09 by kmoilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*fresh;
	unsigned int	i;

	if (!(fresh = ft_strnew(ft_strlen(s))))
		return (NULL);
	i = 0;
	if (f)
	{
		while (s[i])
		{
			fresh[i] = (*f)(i, s[i]);
			i++;
		}
		return (fresh);
	}
	return (NULL);
}
