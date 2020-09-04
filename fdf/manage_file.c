/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 16:04:48 by kmoilane          #+#    #+#             */
/*   Updated: 2020/09/03 18:55:37 by kmoilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			*make_map(char *line, int ymax, t_fdf *vars)
{
	char	**tab;
	int		i;
	int		xmax;

	i = 0;
	tab = ft_strsplit(line, ' ');
	free(line);
	xmax = tablen(tab);
	while (tab[i] && (i < xmax))
	{
		vars->map[ymax][i] = ft_atoi(tab[i]);
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	free(tab);
	return (vars->map[ymax]);
}

int			get_xmax(char *line, t_fdf *vars, int ymax)
{
	int		i;
	char	**tab;

	i = 0;
	tab = ft_strsplit(line, ' ');
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	vars->x_max[ymax] = i;
	free(tab);
	return (i);
}

void		parse_file(int fd, t_fdf *vars)
{
	char	*line;
	int		ymax;

	if (!(vars->map = (int **)malloc(sizeof(int *) * (vars->y_max))))
		errors(1);
	line = NULL;
	ymax = 0;
	while ((get_next_line(fd, &line)) == 1)
	{
		if ((get_xmax(line, vars, ymax)) == -1)
			errors(3);
		if (ymax != 0)
			if (vars->x_max[ymax] != vars->x_max[ymax - 1])
				errors(4);
		if (!(vars->map[ymax] = (int *)malloc(sizeof(int) * (vars->x_max[0]))))
			errors(1);
		if ((vars->map[ymax] = make_map(line, ymax, vars)) == NULL)
			errors(5);
		ymax++;
	}
}
