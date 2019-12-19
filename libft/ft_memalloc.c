/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 18:38:51 by kmoilane          #+#    #+#             */
/*   Updated: 2019/10/19 19:15:22 by kmoilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t *fresh;

	if (!(fresh = malloc(size)))
		return (NULL);
	ft_bzero(fresh, size);
	return (fresh);
}
