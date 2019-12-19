/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoilane <kmoilane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 18:38:18 by kmoilane          #+#    #+#             */
/*   Updated: 2019/12/17 20:00:30 by kmoilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

typedef	struct		s_piece
{
	int				x[4];
	int				y[4];
	int				size;
	char			letter;
	struct s_piece	*next;
}					t_piece;

void				free_map(char **map);
void				error(void);
void				print_map(char **map, int size);
void				clear_prev(char **map, char letter, int size);
void				map_maker(int size, t_piece *head);
void				checks(char *buff, int size);

void				place_piece(char **map, t_piece *piece, int size,
					int loc);
char				**map_dotter(char **map, int map_size);

int					check_place(char **map, t_piece *piece, int size,
					int location);
int					solver(char **map, t_piece *head, t_piece *curr,
					int location);
int					get_map_size(int size, int old);
int					connections(char *buff, int pos);
int					piececount(char *buff);
int					main(int argc, char **argv);

t_piece				*take_coords(t_piece *temp, char *buff);
t_piece				*fill_piece(char *buff, char letter);

#endif
