/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 15:24:52 by ytomiyos          #+#    #+#             */
/*   Updated: 2022/01/18 16:15:33 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_width(t_all *s, int fd)
{
	int		width;
	char	*line;

	s->map_blank = 0;
	while (gnl(fd, &line) > 0)
	{
		width = ft_strlen(line);
		free(line);
		if (width > 256)
			end(s, 9);
		if (width > 0)
			return (width);
		s->map_blank++;
	}
	return (0);
}

static int	get_height(t_all *s, int fd)
{
	int		len;
	int		height;
	char	*line;

	height = 1;
	while (gnl(fd, &line) >= 0)
	{
		len = ft_strlen(line);
		free(line);
		if (len == 0)
			break ;
		if (len != s->map_w)
			end(s, 2);
		height += 1;
	}
	if (s->map_h > 256)
		end(s, 9);
	return (height);
}

static void	empty_line_check(t_all *s, int fd)
{
	int		len;
	char	*line;

	while (gnl(fd, &line) > 0)
	{
		len = ft_strlen(line);
		free(line);
		if (len > 0)
			end(s, 2);
	}
	len = ft_strlen(line);
	free(line);
	if (len > 0)
		end(s, 2);
}

static void	get_map_info(t_all *s, char *filename)
{
	int		fd;

	fd = ft_fileopen(s, filename);
	s->map_w = get_width(s, fd);
	s->map_h = get_height(s, fd);
	empty_line_check(s, fd);
	close(fd);
}

void	map_load(char *filename, t_all *s)
{
	get_map_info(s, filename);
	map_create(s, filename);
	map_check(s);
}
