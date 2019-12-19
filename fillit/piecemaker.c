/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piecemaker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoilane <kmoilane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 13:07:59 by kmoilane          #+#    #+#             */
/*   Updated: 2019/12/17 22:48:52 by kmoilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece		*take_coords(t_piece *temp, char *buff)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 19)
	{
		if (buff[i] == '#')
		{
			if (j == 0)
			{
				temp->x[j] = (i % 5);
				temp->y[j] = (i / 5);
				j++;
			}
			else
			{
				temp->x[j] = (i % 5 - temp->x[0]);
				temp->y[j] = (i / 5 - temp->y[0]);
				j++;
			}
		}
		i++;
	}
	return (temp);
}

t_piece		*fill_piece(char *buff, char letter)
{
	t_piece *fresh;

	if (!(fresh = (t_piece *)malloc(sizeof(t_piece))))
		error();
	fresh->letter = letter;
	return (take_coords(fresh, buff));
}

int			connections(char *buff, int pos)
{
	int		c;

	c = 0;
	if (pos + 1 <= 18 && *(buff + 1) == '#')
		c++;
	if (pos - 1 >= 0 && *(buff - 1) == '#')
		c++;
	if (pos + 5 <= 18 && *(buff + 5) == '#')
		c++;
	if (pos - 5 >= 0 && *(buff - 5) == '#')
		c++;
	return (c);
}

int			piececount(char *buff)
{
	int		i;
	int		pieces;
	int		conns;

	i = 0;
	conns = 0;
	pieces = 0;
	while (i < 19)
	{
		if ((buff[i] && buff[i] != '\n' && buff[i] != '#' && buff[i] != '.')
		|| (buff[i] == '\n' && (i + 1) % 5) || !buff[i])
			return (0);
		if (buff[i] == '#')
		{
			pieces++;
			conns += connections(buff + i, i);
		}
		i++;
	}
	if (pieces != 4 || conns < 6)
		return (0);
	return (1);
}

void		checks(char *buff, int size)
{
	int		i;
	t_piece	*curr;
	t_piece	*head;
	char	letter;

	i = 0;
	letter = 'A';
	head = fill_piece(buff, letter);
	curr = head;
	while (i <= size)
	{
		if (!piececount(buff + i))
			error();
		if (letter != 'A')
		{
			curr->next = fill_piece(buff + i, letter);
			curr = curr->next;
		}
		letter++;
		i += 21;
	}
	curr->next = NULL;
	map_maker((int)letter - 65, head);
}
