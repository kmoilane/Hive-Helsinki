/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoilane <kmoilane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 13:07:45 by kmoilane          #+#    #+#             */
/*   Updated: 2019/12/17 20:01:58 by kmoilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	clear_prev(char **map, char letter, int size)
{
	int	x;
	int	y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (map[y][x] == letter)
				map[y][x] = '.';
			x++;
		}
		y++;
	}
}

void	place_piece(char **map, t_piece *piece, int size, int loc)
{
	int	x;
	int	y;
	int i;

	x = loc % size;
	y = loc / size;
	i = 0;
	map[y][x] = piece->letter;
	while (++i < 4)
		map[y + piece->y[i]][x + piece->x[i]] = piece->letter;
}

int		check_place(char **map, t_piece *piece, int size, int location)
{
	int x;
	int y;
	int i;

	x = location % size;
	y = location / size;
	i = 1;
	while (i < 4)
	{
		if (map[y][x] != '.')
			return (0);
		if (piece->y[i] + y >= size || piece->x[i] + x >= size)
			return (0);
		if (piece->y[i] + y < 0 || piece->x + x < 0)
			return (0);
		if (map[y + (piece->y[i])][x + (piece->x[i])] == '.')
			i++;
		else
			return (0);
	}
	return (1);
}

int		solver(char **map, t_piece *head, t_piece *curr, int location)
{
	int		x;
	int		y;
	int		size;

	size = head->size;
	y = location / size;
	x = location % size;
	if (curr == NULL)
		print_map(map, size);
	while (location < (size * size - 3))
	{
		if (check_place(map, curr, size, location))
		{
			place_piece(map, curr, size, location);
			if (solver(map, head, curr->next, 0))
			{
				if (!curr->next)
					return (1);
			}
			else
				clear_prev(map, curr->letter, size);
		}
		location++;
	}
	return (0);
}
