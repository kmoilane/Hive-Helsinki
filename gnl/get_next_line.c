/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoilane <kmoilane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:03:38 by kmoilane          #+#    #+#             */
/*   Updated: 2019/11/25 20:01:58 by kmoilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	linefiller(char **str, char **line, int fd, int ret)
{
	int		len;
	char	*temp;

	if (ret == 0 && (str[fd] == NULL))
		return (0);
	len = 0;
	while (str[fd][len] != '\n' && str[fd][len] != '\0')
		len++;
	if (str[fd][len] == '\n')
	{
		if (!(*line = ft_strndup(str[fd], len)) ||
		(!(temp = ft_strdup(str[fd] + len + 1))) || ret < 0)
			return (-1);
		free(str[fd]);
		str[fd] = temp;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else if (str[fd][len] == '\0')
	{
		if (!(*line = ft_strdup(str[fd])) || ret < 0)
			return (-1);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	int			ret;
	char		*temp;
	char		buffer[BUFF_SIZE + 1];
	static char	*str[4864];

	if (fd < 0 || !line || fd > 4864 || read(fd, buffer, 0) < 0)
		return (-1);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (str[fd] == NULL)
			if (!(str[fd] = ft_strnew(1)))
				return (-1);
		if (!(temp = ft_strjoin(str[fd], buffer)))
			return (-1);
		free(str[fd]);
		str[fd] = temp;
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	return (linefiller(str, line, fd, ret));
}
