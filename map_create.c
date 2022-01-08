/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 17:07:19 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/12/26 17:07:52 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_create(t_all *s, char *filename)
{
	int		fd;
	char	*line;
	int	i;
	int	j;

	i = 0;
	fd = ft_fileopen(s, filename);
	s->map = (char **)ft_malloc(s, sizeof(char *) * s->map_h);
	while (i < s->map_h)
	{
		gnl(fd, &line);
		s->map[i] = line;
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
			{
				s->colle_n++;
			}
			else if (s->map[i][j] == 'E')
			{
				s->exit_n++;
			}
			j++;
		}
		i++;
	}
	close(fd);
}
