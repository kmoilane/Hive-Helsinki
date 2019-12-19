/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_maker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoilane <kmoilane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 13:07:34 by kmoilane          #+#    #+#             */
/*   Updated: 2019/12/17 20:00:04 by kmoilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_map(char **map, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putstr(map[i]);
		write(1, "\n", 1);
		i++;
	}
	free_map(map);
	exit(0);
}

void	free_map(char **map)
{
	int i;

	i = -1;
	while (map[++i])
		free(map[i]);
	if (map)
		free(map);
}

char	**map_dotter(char **map, int map_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_size)
	{
		j = 0;
		while (j < map_size)
		{
			map[i][j] = '.';
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}

int		get_map_size(int count, int old)
{
	int	size;

	size = 2;
	while (size * size < count)
		size++;
	if (size == old)
		size++;
	return (size);
}

void	map_maker(int count, t_piece *head)
{
	int		i;
	char	**map;

	if (!head)
		error();
	head->size = get_map_size(count * 4, head->size);
	if (!(map = (char **)malloc(sizeof(char *) * (head->size + 1))))
		error();
	i = 0;
	while (i < head->size)
	{
		if (!(map[i] = (char *)malloc(sizeof(char) * (head->size + 1))))
			error();
		i++;
	}
	map = map_dotter(map, head->size);
	if (!(solver(map, head, head, 0)))
	{
		free_map(map);
		map_maker(count + 1, head);
	}
}
