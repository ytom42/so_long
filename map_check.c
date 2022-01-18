/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:00:11 by ytomiyos          #+#    #+#             */
/*   Updated: 2022/01/11 20:00:29 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	width_height_check(t_all *s)
{
	if (s->map_h < 3 || s->map_w < 3)
		end(s, 1);
}

void	check_char(t_all *s)
{
	printf("p:%d c:%d e:%d\n", s->player_n, s->colle_n, s->exit_n);
	if (s->player_n != 1)
		end(s, 5);
	else if (s->colle_n < 1)
		end(s, 5);
	else if (s->exit_n < 1)
		end(s, 5);
}

void	wall_check(t_all *s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < s->map_h)
	{
		j = 0;
		while (j < s->map_w)
		{
			if (i == 0 || i == (s->map_h - 1) || j == 0 || j == (s->map_w - 1))
			{
				if (s->map[i][j] != '1')
					end(s, 3);
			}
			j++;
		}
		i++;
	}
}

void	map_check(t_all *s)
{
	int		i;
	int		j;

	i = 0;
	while (i < s->map_h)
	{
		j = 0;
		while (j < s->map_w)
		{
			if (s->map[i][j] != '1' && s->map[i][j] != '0' && \
				s->map[i][j] != 'E' && s->map[i][j] != 'C' && \
				s->map[i][j] != 'P')
				end(s, 4);
			j++;
		}
		i++;
	}
	width_height_check(s);
	check_char(s);
	wall_check(s);
}
