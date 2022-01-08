/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_load.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 23:55:17 by ytomiyos          #+#    #+#             */
/*   Updated: 2022/01/08 00:02:14 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	texture_load(t_all *s)
{
	s->texs.floor.img = mlx_xpm_file_to_image(s->mlx, "./floor.xpm", \
		&s->texs.floor.width, &s->texs.floor.height);
	s->texs.floor.addr = mlx_get_data_addr(s->texs.floor.img, \
		&s->texs.floor.bpp, &s->texs.floor.line_len, &s->texs.floor.endian);
	s->texs.wall.img = mlx_xpm_file_to_image(s->mlx, "./wakame.xpm", \
		&s->texs.wall.width, &s->texs.wall.height);
	s->texs.wall.addr = mlx_get_data_addr(s->texs.wall.img, \
		&s->texs.wall.bpp, &s->texs.wall.line_len, &s->texs.wall.endian);
	s->texs.player.img = mlx_xpm_file_to_image(s->mlx, "./player.xpm", \
		&s->texs.player.width, &s->texs.player.height);
	s->texs.player.addr = mlx_get_data_addr(s->texs.player.img, \
		&s->texs.player.bpp, &s->texs.player.line_len, &s->texs.player.endian);
	s->texs.collect.img = mlx_xpm_file_to_image(s->mlx, "./kouseki.xpm", \
		&s->texs.collect.width, &s->texs.collect.height);
	s->texs.collect.addr = mlx_get_data_addr(s->texs.collect.img, \
		&s->texs.collect.bpp, &s->texs.collect.line_len, \
		&s->texs.collect.endian);
	s->texs.exit.img = mlx_xpm_file_to_image(s->mlx, "./exit.xpm", \
		&s->texs.exit.width, &s->texs.exit.height);
	s->texs.exit.addr = mlx_get_data_addr(s->texs.exit.img, \
		&s->texs.exit.bpp, &s->texs.exit.line_len, &s->texs.exit.endian);
}
