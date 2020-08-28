/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoilane <kmoilane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:27:54 by kmoilane          #+#    #+#             */
/*   Updated: 2020/02/17 20:17:55 by kmoilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	char	**fresh;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s || (!(fresh = (char**)malloc(sizeof(char *) * (ft_wcnt(s, c) + 1)))))
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			if (!(fresh[i] = (char*)malloc(sizeof(char) * ft_wln(s, c) + 1)))
				return (NULL);
			while (*s && *s != c)
				fresh[i][j++] = (char)*s++;
			fresh[i][j] = '\0';
			j = 0;
			i++;
		}
	}
	fresh[i] = NULL;
	return (fresh);
}
