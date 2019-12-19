/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoilane <kmoilane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 18:48:31 by kmoilane          #+#    #+#             */
/*   Updated: 2019/12/17 20:00:00 by kmoilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error(void)
{
	write(1, "error\n", 6);
	exit(0);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	buff[546];

	if (argc != 2)
	{
		write(1, "usage: ./fillit filename\n", 26);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	ret = read(fd, buff, 546);
	close(fd);
	if (ret > 545 || ret < 19)
		error();
	buff[ret] = '\0';
	checks(buff, ret);
	return (0);
}
