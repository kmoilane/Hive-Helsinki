/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 16:04:48 by kmoilane          #+#    #+#             */
/*   Updated: 2020/08/28 17:40:15 by kmoilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			*assign_coordinates(char *line)
{
	char	**tab;
	int		i;
	int		*newline;
	int		xmax;

	i = 0;
	tab = ft_strsplit(line, ' ');
	xmax = tablen(tab);
	if (!(newline = (int *)malloc(sizeof(int) * xmax)))
		exit(0);
	while (tab[i] && (i < xmax))
	{
		newline[i] = ft_atoi(tab[i]);
		i++;
	}
	return (newline);
}

int			check_tab(char **tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
			if (tab[i][j] == '-')
			{
				j++;
				while (tab[i][j])
				{
					if (tab[i][j] < '0' || tab[i][j] > '9')
						return (1);
					j++;
				}
			}
			else if (tab[i][j] >= '0' && tab[i][j] <= '9')
				j++;
			else
				return (1);
		i++;
	}
	return (0);
}

int			get_xmax(char *line, t_fdf *vars, int ymax)
{
	int		i;
	char	**tab;

	i = 0;
	tab = ft_strsplit(line, ' ');
	if (check_tab(tab) == 1)
		return (-1);
	while (tab[i])
		i++;
	vars->x_max[ymax] = i;
	return (i);
}

void		parse_file(int fd, t_fdf *vars)
{
	char	*line;
	int		ymax;

	ft_putstr("Debug Pro\n");
	if (!(vars->map = (int **)malloc(sizeof(int *) * (vars->y_max))))
		exit(0);
	if (!(vars->x_max = (int *)malloc(sizeof(int) * (vars->y_max))))
		exit(0);
	line = NULL;
	ymax = 0;
	while ((get_next_line(fd, &line)) == 1)
	{
		if ((get_xmax(line, vars, ymax)) == -1)
			exit(0);
		if (ymax != 0)
			if (vars->x_max[ymax] != vars->x_max[ymax - 1])
				exit(0);
		if ((vars->map[ymax] = assign_coordinates(line)) == NULL)
			exit(0);
		ymax++;
	}
	ft_putstr("debugger pro2\n");
	print_map(vars);
}

void		print_map(t_fdf *vars)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < vars->y_max)
	{
		ft_putstr("Line ");
		ft_putnbr(i);
		ft_putstr(" : ");
		while (j < vars->x_max[i])
		{
			ft_putnbr(vars->map[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
}
