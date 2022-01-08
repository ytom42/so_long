/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 15:24:52 by ytomiyos          #+#    #+#             */
/*   Updated: 2022/01/08 19:06:04 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_width(t_all *s, int fd)
{
	int		len;
	char	*line;

	s->map_blank = 0;
	while (gnl(fd, &line) > 0)
	{
		len = ft_strlen(line);
		free(line);
		if (len > 0)
			return (len);
		s->map_blank++;
	}
	return (0);
}

static void	simple_check(t_all *s, char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0)
		end(s, 2);
	if (s->map_h < 3 || s->map_w < 3)
		end(s, 1);
}

static void	get_width_height(t_all *s, char *filename)
{
	int		fd;
	int		len;
	char	*line;

	fd = ft_fileopen(s, filename);
	s->map_w = get_width(s, fd);
	s->map_h = 1;
	while (gnl(fd, &line) >= 0)
	{
		len = ft_strlen(line);
		free(line);
		if (len == 0)
			break ;
		if (len != s->map_w)
			end(s, 2);
		s->map_h += 1;
	}
	while (gnl(fd, &line) > 0)
	{
		len = ft_strlen(line);
		if (len > 0)
			end(s, 2);
	}
	simple_check(s, line);
	close(fd);
}

void	map_load(char *filename, t_all *s)
{
	get_width_height(s, filename);
	map_create(s, filename);
	map_check(s);
}
