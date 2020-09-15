/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 15:32:21 by kmoilane          #+#    #+#             */
/*   Updated: 2020/09/03 19:07:06 by kmoilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		manage_draw(t_fdf *vars)
{
	mlx_string_put(vars->mlx, vars->win, 100, 100, 0x00FFFF, "esc = exit");
	mlx_string_put(vars->mlx, vars->win, 100, 120, 0x00FFFF,
			"R,G,B = to change color");
	mlx_string_put(vars->mlx, vars->win, 100, 140, 0x00FFFF,
			"backspace = reset");
	mlx_string_put(vars->mlx, vars->win, 100, 160, 0x00FFFF,
			"1 and 2 = zoom in and out");
	mlx_string_put(vars->mlx, vars->win, 100, 180, 0x00FFFF,
			"I and P = change projection");
	mlx_string_put(vars->mlx, vars->win, 100, 200, 0x00FFFF,
			"+ and - = change alitude");
	draw_all(vars);
}

void		manage_window(t_fdf *vars)
{
	if ((vars->mlx = mlx_init()) == NULL)
		exit(0);
	vars->win = mlx_new_window(vars->mlx, vars->width, vars->height, "FdF");
	manage_draw(vars);
	mlx_key_hook(vars->win, get_events, vars);
	mlx_loop(vars->mlx);
}

void		init_struct(t_fdf *vars)
{
	vars->height = 1200;
	vars->width = 1200;
	vars->clr = 0xFFFFFF;
	vars->pers = 'I';
	vars->altitude = 1;
	vars->zoom = 25;
	vars->view_x = 500;
	vars->view_y = 400;
}

void		get_ymax(int fd, t_fdf *vars)
{
	char	*line;
	int		ymax;

	ymax = 0;
	line = NULL;
	while ((get_next_line(fd, &line)) == 1)
	{
		free(line);
		ymax++;
	}
	vars->y_max = ymax;
}

int			main(int argc, char **argv)
{
	t_fdf	vars;
	int		fd;

	if (argc == 2)
	{
		if (!(fd = open(argv[1], O_RDONLY)))
			errors(0);
		init_struct(&vars);
		get_ymax(fd, &vars);
		close(fd);
		if (!(vars.x_max = (int *)malloc(sizeof(int) * vars.y_max)))
			errors(1);
		if (!(fd = open(argv[1], O_RDONLY)))
			errors(0);
		parse_file(fd, &vars);
		manage_window(&vars);
		return (0);
	}
	ft_putstr("usage: ./fdf filename.fdf\n");
	exit(0);
}
