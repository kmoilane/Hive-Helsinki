/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 18:06:12 by kmoilane          #+#    #+#             */
/*   Updated: 2020/09/03 19:04:43 by kmoilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		change_clrs(int keycode, t_fdf *vars)
{
	if (keycode == 11)
	{
		vars->clr = 0x0000FF;
		mlx_clear_window(vars->mlx, vars->win);
		manage_draw(vars);
	}
	if (keycode == 15)
	{
		vars->clr = 0xFF0000;
		mlx_clear_window(vars->mlx, vars->win);
		manage_draw(vars);
	}
	if (keycode == 5)
	{
		vars->clr = 0x00FF00;
		mlx_clear_window(vars->mlx, vars->win);
		manage_draw(vars);
	}
	return (0);
}

int		get_zoom(int keycode, t_fdf *vars)
{
	if (keycode == 19)
	{
		if (vars->zoom > 1)
		{
			vars->zoom = vars->zoom / 2;
			vars->zoom = vars->zoom / 2;
			mlx_clear_window(vars->mlx, vars->win);
			manage_draw(vars);
		}
	}
	if (keycode == 18)
	{
		if (vars->zoom <= 400)
		{
			vars->zoom = vars->zoom * 2;
			vars->zoom = vars->zoom * 2;
			mlx_clear_window(vars->mlx, vars->win);
			manage_draw(vars);
		}
	}
	return (0);
}

int		get_perspective(int keycode, t_fdf *vars)
{
	if (keycode == 34)
	{
		if (vars->pers == 'I')
			return (0);
		else
		{
			vars->pers = 'I';
			mlx_clear_window(vars->mlx, vars->win);
			manage_draw(vars);
		}
	}
	if (keycode == 35)
	{
		if (vars->pers == 'P')
			return (0);
		else
		{
			vars->pers = 'P';
			mlx_clear_window(vars->mlx, vars->win);
			manage_draw(vars);
		}
	}
	return (0);
}

int		get_events(int keycode, t_fdf *vars)
{
	if (keycode == 53)
		errors(-1);
	if (keycode == 69)
	{
		vars->altitude++;
		mlx_clear_window(vars->mlx, vars->win);
		manage_draw(vars);
	}
	if (keycode == 78)
	{
		vars->altitude--;
		mlx_clear_window(vars->mlx, vars->win);
		manage_draw(vars);
	}
	if (keycode == 51)
	{
		init_struct(vars);
		mlx_clear_window(vars->mlx, vars->win);
		manage_draw(vars);
	}
	change_clrs(keycode, vars);
	get_zoom(keycode, vars);
	get_perspective(keycode, vars);
	return (0);
}
