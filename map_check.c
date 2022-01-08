/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:00:11 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/12/26 17:03:43 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_all *s, int h, int w)
{
	if (s->fill_map[h][w] == '1')
		return ;
	if ((h + 1) == s->map_h || (w + 1) == s->map_w)
		end(s, 2);
	else if ((h - 1) < 0 || (w - 1) < 0)
		end(s, 2);
	s->fill_map[h][w] = '1';
	flood_fill(s, (h + 1), w);
	flood_fill(s, h, (w + 1));
	flood_fill(s, (h - 1), w);
	flood_fill(s, h, (w - 1));
}

void	map_check(t_all *s)
{
	int i;
	int j;

	i = 0;
	s->fill_map = (char**)malloc(sizeof(char*) * (s->map_h + 1));
	while (i < s->map_h)
	{
		j = 0;
		s->fill_map[i] = ((char*)malloc(sizeof(char) * (s->map_w + 1)));
		while (j < s->map_w)
		{
			if (s->map[i][j] != '1' && s->map[i][j] != '0' && s->map[i][j] != 'E' && s->map[i][j] != 'C' && s->map[i][j] != 'P')
				end(s, 1);
			else if (s->map[i][j] == '1')
				s->fill_map[i][j] = '1';
			else
				s->fill_map[i][j] = '0';
			j++;
		}
		i++;
	}
	flood_fill(s, s->player_y, s->player_x);
}
