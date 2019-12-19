/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:33:51 by kmoilane          #+#    #+#             */
/*   Updated: 2019/11/07 20:59:50 by kmoilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fresh;
	int		i;

	if (!(fresh = ft_strnew(ft_strlen(s))))
		return (NULL);
	i = 0;
	if (f)
	{
		while (s[i])
		{
			fresh[i] = f((char)s[i]);
			i++;
		}
		return (fresh);
	}
	return (NULL);
}
