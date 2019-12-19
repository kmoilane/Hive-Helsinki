/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:33:10 by kmoilane          #+#    #+#             */
/*   Updated: 2019/10/14 13:54:58 by kmoilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int result;

	if (nb < 0 || nb > 12)
		return (0);
	else if (nb == 0 || nb == 1)
		return (1);
	else
	{
		result = nb * ft_recursive_factorial(nb - 1);
		return (result);
	}
}
