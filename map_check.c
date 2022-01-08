/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:00:11 by ytomiyos          #+#    #+#             */
/*   Updated: 2022/01/08 19:09:26 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_all *s, int h, int w)
{
	if (s->fill_map[h][w] == '1')
		return ;
	if ((h + 1) == s->map_h || (w + 1) == s->map_w)
		end(s, 3);
	else if ((h - 1) < 0 || (w - 1) < 0)
		end(s, 3);
	s->fill_map[h][w] = '1';
	flood_fill(s, (h + 1), w);
	flood_fill(s, h, (w + 1));
	flood_fill(s, (h - 1), w);
	flood_fill(s, h, (w - 1));
}

void	check_char(t_all *s)
{
	if (s->player_n != 1)
		end(s, 5);
	else if (s->colle_n < 1)
		end(s, 5);
	else if (s->exit_n < 1)
		end(s, 5);
}

void	map_check(t_all *s)
{
	int		i;
	int		j;

	i = 0;
	s->fill_map = (char **)ft_malloc(s, sizeof(char *) * (s->map_h + 1));
	while (i < s->map_h)
	{
		j = 0;
		s->fill_map[i] = (char *)ft_malloc(s, sizeof(char) * (s->map_w + 1));
		while (j < s->map_w)
		{
			if (s->map[i][j] != '1' && s->map[i][j] != '0' && \
				s->map[i][j] != 'E' && s->map[i][j] != 'C' && \
				s->map[i][j] != 'P')
				end(s, 4);
			else if (s->map[i][j] == '1')
				s->fill_map[i][j] = '1';
			else
				s->fill_map[i][j] = '0';
			j++;
		}
		i++;
	}
	check_char(s);
	flood_fill(s, s->player_y, s->player_x);
}
