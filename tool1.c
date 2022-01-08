/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 16:55:14 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/12/25 01:26:02 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_all *s, int x, int y, int color)
{
	char	*dst;

	dst = s->img.addr + (y * s->img.line_len + x * (s->img.bpp / 8));
	*(unsigned int*)dst = color;
}

// void	my_mlx_pixel_put2(t_all *s, int x, int y, t_texture *tex)
// {
// 	char			*dst;
// 	unsigned int	color;

// 	dst = s->img.addr + (y * s->img.line_len + x * (s->img.bpp / 8));
// 	color = *(unsigned int*)(tex->addr + (s->tex_y * tex->line_len + s->tex_x * (tex->bpp / 8)));
// 	*(unsigned int*)dst = color;
// }

void	mlx_pixel_put_of_tex(t_all *s, int x, int y, t_texture *tex)
{
	char			*dst;
	unsigned int	color;

	dst = s->img.addr + (y * s->img.line_len + x * (s->img.bpp / 8));
	color = *(unsigned int*)(tex->addr + (s->tex_y * tex->line_len + s->tex_x * (tex->bpp / 8)));
	if (color == 0)
		return ;
	*(unsigned int*)dst = color;
}
