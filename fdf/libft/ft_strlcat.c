/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 20:35:49 by kmoilane          #+#    #+#             */
/*   Updated: 2019/10/29 20:45:48 by kmoilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	dlen = ft_strlen(dst);
	slen = ft_strlen((char *)src);
	i = -1;
	if (!dstsize || dstsize <= dlen)
		return (slen += dstsize);
	else
		slen += dlen;
	while (src[++i] && dlen + i < dstsize - 1)
		dst[dlen + i] = src[i];
	dst[dlen + i] = '\0';
	return (slen);
}
