/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 00:56:38 by ytomiyos          #+#    #+#             */
/*   Updated: 2022/01/19 11:24:52 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_pixel_img(t_all *s, int *window_x, int *window_y)
{
	char	dst;

	s->map_y = *window_y / 64;
	*window_x = 0;
	while (*window_x < s->screen_w)
	{
		s->map_x = *window_x / 64;
		s->tex_x = *window_x % 64;
		s->tex_y = *window_y % 64;
		dst = s->map[s->map_y][s->map_x];
		if (dst == '0' || dst == '1' || dst == 'P' || \
			dst == 'C' || dst == 'E')
			mlx_pixel_put_of_tex(s, *window_x, *window_y, &s->texs.floor);
		if (dst == '1')
			mlx_pixel_put_of_tex(s, *window_x, *window_y, &s->texs.wall);
		else if (dst == 'P')
			mlx_pixel_put_of_tex(s, *window_x, *window_y, &s->texs.player);
		else if (dst == 'C')
			mlx_pixel_put_of_tex(s, *window_x, *window_y, &s->texs.collect);
		else if (dst == 'E')
			mlx_pixel_put_of_tex(s, *window_x, *window_y, &s->texs.exit);
		if (s->exit_n <= 0)
			my_mlx_pixel_put(s, *window_x, *window_y, 0x000000);
		*window_x += 1;
	}
}

void	create_img(t_all *s)
{
	int		window_x;
	int		window_y;

	window_x = 0;
	window_y = 0;
	while (window_y < s->screen_h)
	{
		put_pixel_img(s, &window_x, &window_y);
		window_y++;
	}
}
