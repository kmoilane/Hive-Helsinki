/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:27:54 by kmoilane          #+#    #+#             */
/*   Updated: 2019/10/25 17:21:12 by kmoilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wcnt(char const *s, char c)
{
	int	count;

	count = 0;
	if (*s && *s != c)
	{
		s++;
		count++;
	}
	while (*s)
	{
		while (*s == c)
		{
			s++;
			if (*s != c && *s)
				count++;
		}
		s++;
	}
	return (count);
}

static int	ft_wln(char const *s, char c)
{
	int len;

	len = 0;
	while (*s != c && *s)
	{
		len++;
		s++;
	}
	return (len);
}

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
