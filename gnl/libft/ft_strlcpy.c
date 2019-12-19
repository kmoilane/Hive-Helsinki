/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:58:10 by kmoilane          #+#    #+#             */
/*   Updated: 2019/11/06 20:29:59 by kmoilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	slen;

	slen = ft_strlen((char *)src);
	if (slen < dstsize)
		ft_strncpy(dst, src, slen + 1);
	else if (dstsize)
	{
		ft_strncpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (slen);
}
