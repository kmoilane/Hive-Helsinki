/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 15:32:21 by kmoilane          #+#    #+#             */
/*   Updated: 2020/08/28 20:34:57 by kmoilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void		manage_draw(t_fdf *vars)
{
	draw_all_x(vars);
	draw_all_y(vars);
}

void		manage_window(t_fdf *vars)
{
	if ((vars->mlx_ptr = mlx_init()) == NULL)
	{
		ft_putstr("mlx couldn't init\n");
		exit(0);
	}
	vars->win_ptr = mlx_new_window(vars->mlx_ptr, vars->width, vars->height, "FdF");
	manage_draw(vars);
	mlx_key_hook(vars->win_ptr, get_events, vars);
	mlx_loop(vars->mlx_ptr);
}

void		init_struct(t_fdf *vars)
{
	vars->height = 1200;
	vars->width = 1200;
	vars->color = 16777215;
	vars->x_size = 32;
	vars->y_size = 16;
	vars->z = 2;
	vars->view_x = 400;
	vars->view_y = 400;
}

void		get_ymax(int fd, t_fdf *vars)
{
	char	*line;
	int		ymax;

	ymax = 0;
	line = NULL;
	while ((get_next_line(fd, &line)) == 1)
		ymax++;
	vars->y_max = ymax;
}

int			main(int argc, char **argv)
{
	t_fdf	vars;
	int		fd;

	if (argc == 2)
	{
		if (!(fd = open(argv[1], O_RDONLY)))
			return (0);
		init_struct(&vars);
		get_ymax(fd, &vars);
		close(fd);
		if (!(fd = open(argv[1], O_RDONLY)))
			return (0);
		parse_file(fd, &vars);
		manage_window(&vars);
		return (0);
	}
	exit(0);
}
