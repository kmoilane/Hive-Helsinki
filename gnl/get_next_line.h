/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoilane <kmoilane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:01:00 by kmoilane          #+#    #+#             */
/*   Updated: 2019/11/25 18:53:40 by kmoilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 128

# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

int	get_next_line(const int fd, char **line);

#endif
