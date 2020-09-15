/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draws.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 16:09:00 by kmoilane          #+#    #+#             */
/*   Updated: 2020/09/03 19:56:42 by kmoilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_fdf *vars, int stage)
{
	int	prev_x;
	int	prev_y;

	if (stage == 1)
	{
		prev_x = vars->x0;
		prev_y = vars->y0;
		vars->x0 = (prev_x - prev_y) * cos(0.523599);
		vars->y0 = -(vars->z0) + (prev_x + prev_y) * sin(0.523599);
	}
	else if (stage == 2)
	{
		prev_x = vars->x1;
		prev_y = vars->y1;
		vars->x1 = (prev_x - prev_y) * cos(0.523599);
		vars->y1 = -(vars->z1) + (prev_x + prev_y) * sin(0.523599);
	}
}

void	draw_pixel(t_fdf *vars, t_draw coords)
{
	vars->dx = abs(coords.x1 - coords.x0);
	vars->dy = -abs(coords.y1 - coords.y0);
	vars->x_dir = (coords.x0 < coords.x1) ? 1 : -1;
	vars->y_dir = (coords.y0 < coords.y1) ? 1 : -1;
	vars->err = vars->dx + vars->dy;
	while (1)
	{
		mlx_pixel_put(vars->mlx, vars->win, coords.x0 + vars->view_x, coords.y0
				+ vars->view_y, vars->clr);
		if (coords.x0 == coords.x1 && coords.y0 == coords.y1)
			break ;
		vars->err_temp = 2 * vars->err;
		if (vars->err_temp >= vars->dy)
		{
			vars->err += vars->dy;
			coords.x0 += vars->x_dir;
		}
		if (vars->err_temp <= vars->dx)
		{
			vars->err += vars->dx;
			coords.y0 += vars->y_dir;
		}
	}
}

void	draw_line(t_fdf *vars, t_draw coords)
{
	vars->z0 = vars->map[coords.y0][coords.x0] * vars->altitude;
	vars->z1 = vars->map[coords.y1][coords.x1] * vars->altitude;
	vars->x0 = coords.x0 * vars->zoom;
	vars->x1 = coords.x1 * vars->zoom;
	vars->y0 = coords.y0 * vars->zoom;
	vars->y1 = coords.y1 * vars->zoom;
	if (vars->pers == 'I')
	{
		isometric(vars, 1);
		isometric(vars, 2);
	}
	coords.x0 = vars->x0;
	coords.y0 = vars->y0;
	coords.x1 = vars->x1;
	coords.y1 = vars->y1;
	draw_pixel(vars, coords);
}

void	fix_coordinates(t_fdf *vars, int x, int y)
{
	t_draw	coords;

	coords.x0 = x;
	coords.y0 = y;
	if (x < vars->x_max[0] - 1)
	{
		coords.x1 = x + 1;
		coords.y1 = y;
		draw_line(vars, coords);
	}
	if (y < vars->y_max - 1)
	{
		coords.x1 = x;
		coords.y1 = y + 1;
		draw_line(vars, coords);
	}
}

void	draw_all(t_fdf *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars->y_max)
	{
		x = 0;
		while (x < vars->x_max[0])
		{
			fix_coordinates(vars, x, y);
			x++;
		}
		y++;
	}
}
