/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 00:00:50 by ytomiyos          #+#    #+#             */
/*   Updated: 2022/01/19 11:27:49 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_window(t_all *s)
{
	s->screen_w = s->map_w * 64;
	s->screen_h = s->map_h * 64;
	s->win = mlx_new_window(s->mlx, s->screen_w, s->screen_h, "so_long");
	s->img.img = mlx_new_image(s->mlx, s->screen_w, s->screen_h);
	s->img.addr = mlx_get_data_addr(s->img.img, &s->img.bpp, \
		&s->img.line_len, &s->img.endian);
}
