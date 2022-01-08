/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 15:24:52 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/12/28 13:35:27 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_width_height(t_all *s, char *filename)
{
	int		fd;
	int 	len;
	char	*line;

	fd = ft_fileopen(s, filename);
	s->map_w = 0;
	s->map_h = 0;
	while (gnl(fd, &line) > 0)
	{
		len = ft_strlen(line);
		free(line);
		s->map_w = len;
		s->map_h++;
	}
	close(fd);
}

void	map_load(char *filename, t_all *s)
{
	get_width_height(s, filename);
	map_create(s, filename);
	map_check(s);
}
