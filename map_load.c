/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 15:24:52 by ytomiyos          #+#    #+#             */
/*   Updated: 2022/01/12 01:58:26 by ytomiyos         ###   ########.fr       */
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
		if (len > 256)
			exit(1); //test
		free(line);
		if (len > 0)
			return (len);
		s->map_blank++;
	}
	return (0);
}

static void	empty_line_check(t_all *s, char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0)
		end(s, 2);
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
	if (s->map_h > 256)
		exit(1); //test
	while (gnl(fd, &line) > 0)
	{
		len = ft_strlen(line);
		if (len > 0)
			end(s, 2);
	}
	empty_line_check(s, line);
	close(fd);
}

void	map_load(char *filename, t_all *s)
{
	get_width_height(s, filename);
	map_create(s, filename);
	map_check(s);
}
