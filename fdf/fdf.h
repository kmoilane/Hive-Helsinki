/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoilane <kmoilane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 19:53:51 by kmoilane          #+#    #+#             */
/*   Updated: 2020/09/03 19:07:34 by kmoilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"

typedef	struct		s_draw
{
	int				x0;
	int				x1;
	int				y0;
	int				y1;
}					t_draw;

typedef	struct		s_fdf
{
	void			*mlx;
	void			*win;
	int				width;
	int				height;
	unsigned long	clr;
	char			pers;
	int				view_x;
	int				view_y;
	int				*x_max;
	int				y_max;
	int				altitude;
	int				zoom;
	int				**map;
	int				x0;
	int				x1;
	int				y0;
	int				y1;
	int				z0;
	int				z1;
	int				dx;
	int				dy;
	int				err;
	int				err_temp;
	int				x_dir;
	int				y_dir;
}					t_fdf;

int					detect_key_entries(int key);
int					tablen(char **tab);
int					*make_map(char *line, int ymax, t_fdf *vars);
int					get_xmax(char *line, t_fdf *vars, int ymax);
int					get_events(int keycode, t_fdf *vars);
int					get_zoom(int keycode, t_fdf *vars);
int					get_perspective(int keycode, t_fdf *vars);
int					change_colors(int keycode, t_fdf *vars);

void				errors(int nb);
void				fix_coordinates(t_fdf *vars, int x, int y);
void				draw_pixel(t_fdf *vars, t_draw coords);
void				draw_line(t_fdf *vars, t_draw coords);
void				isometric(t_fdf *vars, int stage);
void				draw_all(t_fdf *vars);
void				manage_draw(t_fdf *vars);
void				manage_window(t_fdf *vars);
void				parse_file(int fd, t_fdf *vars);
void				get_ymax(int fd, t_fdf *vars);
void				init_struct(t_fdf *vars);

#endif
