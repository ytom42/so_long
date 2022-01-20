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

static void	vars_init(t_all *s, int argc)
{
	s->mlx = NULL;
	s->win = NULL;
	s->img.img = NULL;
	s->img.addr = NULL;
	s->move_n = 0;
	s->player_n = 0;
	s->colle_n = 0;
	s->exit_n = 0;
	if (argc != 2)
		end(s, 0);
}

int	main(int argc, char **argv)
{
	t_all	s;

	vars_init(&s, argc);
	map_load(argv[1], &s);
	texture_load(&s);
	create_window(&s);
	create_img(&s);
	mlx_put_image_to_window(s.mlx, s.win, s.img.img, 0, 0);
	mlx_hook(s.win, KEYPRESS, 0, push_key, &s);
	mlx_hook(s.win, DESTROYNOTIFY, 0, close_window, &s);
	mlx_loop(s.mlx);
	return (0);
}
