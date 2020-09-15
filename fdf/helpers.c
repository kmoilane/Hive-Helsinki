/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 17:11:13 by kmoilane          #+#    #+#             */
/*   Updated: 2020/09/03 19:03:48 by kmoilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	errors(int nb)
{
	if (nb == -1)
	{
		ft_putstr("Bye!\n");
		exit(1);
	}
	if (nb == 0)
		ft_putstr("Error opening file\n");
	else if (nb == 1)
		ft_putstr_fd("Memory error\n", 2);
	else if (nb == 2)
		ft_putstr_fd("Mlx init error\n", 2);
	else if (nb == 3)
		ft_putstr_fd("Invalid map (map has other symbols than numbers)\n", 2);
	else if (nb == 4)
		ft_putstr_fd("Invalid map (different sized rows)\n", 2);
	else if (nb == 5)
		ft_putstr_fd("Invalid map\n", 2);
	exit(-1);
}

int		tablen(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
