/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 13:31:16 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/12/24 16:17:03 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_all	s;

	argc = 0;
	argv = 0;

	s.mlx = mlx_init();
	// read_map(argv[1]);
	s.screen_w = 800;
	s.screen_h = 500;
	s.win = mlx_new_window(s.mlx, s.screen_w, s.screen_h, "so_long");

	s.img.img = mlx_new_image(s.mlx, s.screen_w, s.screen_h);
	s.img.addr = mlx_get_data_addr(s.img.img, &s.img.bpp, &s.img.line_len, &s.img.endian);

	// s.texs.floor.addr = mlx_get_data_addr(s.texs.floor.img, &s.texs.floor.bpp, &s.texs.floor.line_len, &s.texs.floor.endian);

	int y = 0;
	while (y < s.screen_h)
	{
		int x = 0;
		while (x < s.screen_w / 2)
		{
			my_mlx_pixel_put(&s, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}


	mlx_put_image_to_window(s.mlx, s.win, s.img.img, 0, 0);

	// mlx_hook(s.win, 2, 0, push_key, &s);
	mlx_hook(s.win, 17, 0, close_window, &s);
	mlx_loop(s.mlx);
	return (0);
}