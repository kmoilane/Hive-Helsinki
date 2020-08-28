/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoilane <kmoilane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 19:53:51 by kmoilane          #+#    #+#             */
/*   Updated: 2020/08/28 20:53:38 by kmoilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include "./libft/libft.h"

typedef	struct		s_fdf
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				width;
	int				height;
	unsigned long	color;
	int				x_size;
	int				y_size;
	int				view_x;
	int				view_y;
	int				*x_max;
	int				y_max;
	int				z;
	int				**map;
	int				x0;
	int				x1;
	int				y0;
	int				y1;
	int				dx;
	int				dy;
	int				p;
	int				x;
	int				y;
	int				turn;
}					t_fdf;

int					detect_key_entries(int key);
int					tablen(char **tab);
int					*assign_coordinates(char *line);
int					check_tab(char **tab);
int					get_xmax(char *line, t_fdf *vars, int ymax);
int					get_events(int keycode, t_fdf *vars);
int					get_zoom(int keycode, t_fdf *vars);
int					move_view(int keycode, t_fdf *vars);
int					change_colors(int keycode, t_fdf *vars);

void				pixels(t_fdf *vars);
void				positive(t_fdf *vars);
void				negative(t_fdf *vars);
void				draw_all_y(t_fdf *vars);
void				draw_all_x(t_fdf *vars);
void				manage_draw(t_fdf *vars);
void				manage_window(t_fdf *vars);
void				parse_file(int fd, t_fdf *vars);
void				get_ymax(int fd, t_fdf *vars);
void				init_struct(t_fdf *vars);
void				print_map(t_fdf *vars);

#endif
