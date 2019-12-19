/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 13:50:14 by kmoilane          #+#    #+#             */
/*   Updated: 2019/10/29 20:28:01 by kmoilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long	result;
	int					neg;
	int					i;

	result = 0;
	neg = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
	str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	if (result > 9223372036854775807 && neg < 0)
		return (0);
	if (result > 9223372036854775807)
		return (-1);
	return (result * neg);
}
