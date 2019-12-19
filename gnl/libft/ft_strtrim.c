/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 19:13:02 by kmoilane          #+#    #+#             */
/*   Updated: 2019/11/05 16:03:11 by kmoilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_rmws(char const *s)
{
	int	i;
	int	len;

	len = ft_strlen(s);
	while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
		len--;
	i = -1;
	while (s[++i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		len--;
	if (len <= 0)
		len = 0;
	return (len);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		len;
	char	*fresh;

	if (!s)
		return (NULL);
	len = ft_strlen_rmws(s);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (!(fresh = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	j = -1;
	while (++j < len)
		fresh[j] = s[i + j];
	fresh[j] = '\0';
	return (fresh);
}
