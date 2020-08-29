/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draws.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 17:51:37 by kmoilane          #+#    #+#             */
/*   Updated: 2020/08/29 17:52:02 by karrzzaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	negative(t_fdf *vars)
{
	int	err;
	int	i;

	i = 0;
	err = vars->dy / 2;
	while (i < vars->dy)
	{
		err += vars->dx;
		if (err > vars->dy)
		{
			err -= vars->dy;
			vars->x0 += vars->x;
		}
		mlx_pixel_put(vars->mlx_ptr, vars->win_ptr,
				vars->x0, vars->y0, vars->color);
		vars->y0 += vars->y;
		i++;
	}
}

void	positive(t_fdf *vars)
{
	int	err;
	int	i;

	i = 0;
	err = vars->dx / 2;
	while (i < vars->dx)
	{
		err += vars->dy;
		if (err > vars->dx)
		{
			err -= vars->dx;
			vars->y0 += vars->y;
		}
		mlx_pixel_put(vars->mlx_ptr, vars->win_ptr, vars->x0,
				vars->y0, vars->color);
		vars->x0 += vars->x;
		i++;
	}
}

void	pixels(t_fdf *vars)
{
	vars->x = (vars->x1 > vars->x0) ? 1 : -1;
	vars->y = (vars->y1 > vars->y0) ? 1 : -1;
	vars->dx = abs(vars->x1 - vars->x0);
	vars->dy = abs(vars->y1 - vars->y0);
	if (vars->dx > vars->dy)
	{
		positive(vars);
	}
	else
	{
		negative(vars);
	}
	mlx_pixel_put(vars->mlx_ptr, vars->win_ptr,
			vars->x0, vars->y0, vars->color);
	mlx_pixel_put(vars->mlx_ptr, vars->win_ptr,
			vars->x1, vars->y1, vars->color);
}

void	draw_all_y(t_fdf *vars)
{
	int	i;

	i = 0;
	vars->turn = 0;
	while (i < vars->y_max - 1)
	{
		while (vars->turn < vars->x_max[i])
		{
			vars->x0 = vars->view_x + (vars->turn - i) * vars->x_size;
			vars->y0 = vars->view_y + (vars->turn + i) * vars->y_size -
				(vars->map[i][vars->turn] * vars->z);
			vars->x1 = vars->view_x + ((vars->turn) - (i + 1)) * vars->x_size;
			vars->y1 = vars->view_y + ((vars->turn) + (i + 1)) * vars->y_size -
				(vars->map[i + 1][vars->turn] * vars->z);
			pixels(vars);
			vars->turn++;
		}
		i++;
		vars->turn = 0;
	}
}

void	draw_all_x(t_fdf *vars)
{
	int	i;

	i = 0;
	vars->turn = 0;
	while (i < vars->y_max)
	{
		while (vars->turn < vars->x_max[i] - 1)
		{
			vars->x0 = vars->view_x + (vars->turn - i) * vars->x_size;
			vars->y0 = vars->view_y + (vars->turn + i) * vars->y_size
				- (vars->map[i][vars->turn] * vars->z);
			vars->x1 = vars->view_x + ((vars->turn + 1) - i) * vars->x_size;
			vars->y1 = vars->view_y + ((vars->turn + 1) + i) * vars->y_size
				- (vars->map[i][vars->turn + 1] * vars->z);
			pixels(vars);
			vars->turn++;
		}
		i++;
		vars->turn = 0;
	}
}
