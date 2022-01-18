/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 17:07:19 by ytomiyos          #+#    #+#             */
/*   Updated: 2022/01/18 16:19:27 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	skip_blank(t_all *s, int fd)
{
	int		i;
	char	*line;

	i = 0;
	while (i < s->map_blank)
	{
		gnl(fd, &line);
		free(line);
		i++;
	}
}

static void	char_number_count(t_all *s, int i)
{
	int		j;

	j = 0;
	while (s->map[i][j])
	{
		if (s->map[i][j] == 'P')
		{
			s->player_x = j;
			s->player_y = i;
			s->player_n++;
		}
		else if (s->map[i][j] == 'C')
			s->colle_n++;
		else if (s->map[i][j] == 'E')
			s->exit_n = 1;
		j++;
	}
}

void	map_create(t_all *s, char *filename)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = ft_fileopen(s, filename);
	s->map = (char **)ft_malloc(s, sizeof(char *) * s->map_h);
	skip_blank(s, fd);
	while (i < s->map_h)
	{
		gnl(fd, &line);
		s->map[i] = line;
		char_number_count(s, i);
		i++;
	}
	close(fd);
}
