/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 18:06:12 by kmoilane          #+#    #+#             */
/*   Updated: 2020/08/28 21:13:56 by kmoilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		move_view(int keycode, t_fdf *vars)
{
	if (keycode == 126)
	{
		vars->view_y -= 100;
		mlx_clear_window(vars->mlx_ptr, vars->win_ptr);
		manage_draw(vars);
	}
	if (keycode == 125)
	{
		vars->view_y += 100;
		mlx_clear_window(vars->mlx_ptr, vars->win_ptr);
		manage_draw(vars);
	}
	if (keycode == 123)
	{
		vars->view_x -= 100;
		mlx_clear_window(vars->mlx_ptr, vars->win_ptr);
		manage_draw(vars);
	}
	if (keycode == 124)
	{
		vars->view_x += 100;
		mlx_clear_window(vars->mlx_ptr, vars->win_ptr);
		manage_draw(vars);
	}
	return (0);
}

/*
**	Colors
*/

int		change_colors(int keycode, t_fdf *vars)
{
	if (keycode == 11)
	{
		vars->color = 0x0000FF;
		mlx_clear_window(vars->mlx_ptr, vars->win_ptr);
		manage_draw(vars);
	}
	if (keycode == 15)
	{
		vars->color = 0xFF0000;
		mlx_clear_window(vars->mlx_ptr, vars->win_ptr);
		manage_draw(vars);
	}
	if (keycode == 5)
	{
		vars->color = 0x00FF00;
		mlx_clear_window(vars->mlx_ptr, vars->win_ptr);
		manage_draw(vars);
	}
	return (0);
}

/*
**	ZOOM
*/

int		get_zoom(int keycode, t_fdf *vars)
{
	if (keycode == 18)
	{
		if (vars->y_size > 1)
		{
			vars->x_size = vars->x_size / 2;
			vars->y_size = vars->y_size / 2;
		}
		mlx_clear_window(vars->mlx_ptr, vars->win_ptr);
		manage_draw(vars);
	}
	if (keycode == 19)
	{
		vars->x_size = vars->x_size * 2;
		vars->y_size = vars->y_size * 2;
		mlx_clear_window(vars->mlx_ptr, vars->win_ptr);
		manage_draw(vars);
	}
	return (0);
}

/*
**	"Main" function for gestionning events, exit & Z variation
*/

int		get_events(int keycode, t_fdf *vars)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 69)
	{
		vars->z++;
		mlx_clear_window(vars->mlx_ptr, vars->win_ptr);
		manage_draw(vars);
	}
	if (keycode == 78)
	{
		vars->z--;
		mlx_clear_window(vars->mlx_ptr, vars->win_ptr);
		manage_draw(vars);
	}
	if (keycode == 51)
	{
		init_struct(vars);
		mlx_clear_window(vars->mlx_ptr, vars->win_ptr);
		manage_draw(vars);
	}
	move_view(keycode, vars);
	change_colors(keycode, vars);
	get_zoom(keycode, vars);
	return (0);
}
