/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoilane <kmoilane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:51:35 by kmoilane          #+#    #+#             */
/*   Updated: 2019/10/30 16:53:49 by kmoilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*cdest;
	const unsigned char	*csrc;

	if (!len || dst == src)
		return (dst);
	cdest = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	if (csrc > cdest)
		ft_memcpy(cdest, csrc, len);
	else
	{
		while (len)
		{
			cdest[len - 1] = csrc[len - 1];
			len--;
		}
	}
	return (dst);
}
