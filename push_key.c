/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 23:47:45 by ytomiyos          #+#    #+#             */
/*   Updated: 2022/01/07 23:52:26 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	push_key(int keycode, t_all *s)
{
	s->move = false;
	if (keycode == KEY_ESC)
		exit(1);
	else if (keycode == KEY_W)
		move_up(s);
	else if (keycode == KEY_S)
		move_down(s);
	else if (keycode == KEY_D)
		move_right(s);
	else if (keycode == KEY_A)
		move_left(s);

	create_img(s);
	mlx_put_image_to_window(s->mlx, s->win, s->img.img, 0, 0);
	if (s->exit_n == 0)
		mlx_string_put(s->mlx, s->win, 64, 64, 0xFFFFFF, "You win!");
	else
	{
		char	*str;
		char	*move_num;
		move_num = ft_itoa(s->move_n);
		str = ft_strjoin("Moves: ", move_num);
		mlx_string_put(s->mlx, s->win, 30, 30, 0xFFFFFF, str);
		if (s->move)
			printf("%s\n", str);
		free (move_num);
		free(str);
	}
	return (0);
}