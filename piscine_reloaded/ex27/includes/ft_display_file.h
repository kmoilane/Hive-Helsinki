/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:01:25 by kmoilane          #+#    #+#             */
/*   Updated: 2019/10/14 17:41:13 by kmoilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DISPLAY_FILE_H
# define FT_DISPLAY_FILE_H

# include <unistd.h>
# include <fcntl.h>

# define BUF_SIZE 42

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_display_file(char *filename);

#endif
