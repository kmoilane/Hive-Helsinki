/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:03:04 by kmoilane          #+#    #+#             */
/*   Updated: 2019/10/14 18:07:55 by kmoilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display_file.h"

void	ft_display_file(char *filename)
{
	char	data[BUF_SIZE];
	int		file;
	int		cur;

	if ((file = open(filename, O_RDONLY)) >= 0)
	{
		while ((cur = read(file, data, BUF_SIZE - 1)) > 0)
		{
			data[cur] = '\0';
			ft_putstr(data);
		}
		close(file);
	}
}
