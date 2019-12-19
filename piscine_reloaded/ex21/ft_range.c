/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:16:21 by kmoilane          #+#    #+#             */
/*   Updated: 2019/10/14 16:20:32 by kmoilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int i;
	int *out;

	i = 0;
	if (min >= max || !(out = malloc(sizeof(int) * (max - min))))
		return (NULL);
	while (min < max)
	{
		out[i] = min;
		i++;
		min++;
	}
	return (out);
}
