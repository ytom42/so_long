/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:05:06 by ytomiyos          #+#    #+#             */
/*   Updated: 2022/01/11 19:34:51 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_all *s)
{
	mlx_destroy_window(s->mlx, s->win);
	exit(1);
}

void	end(t_all *s, int n)
{
	if (s->win != NULL)
		mlx_destroy_window(s->mlx, s->win);
	if (n == 0)
		write(1, "Usage: ./so_long [filename]\n", 28);
	else if (n == 1)
		write(1, "Error\nMap error\n", 16);
	else if (n == 2)
		write(2, "Error\nMap is not rectangular\n", 29);
	else if (n == 3)
		write(2, "Error\nMap is not close\n", 23);
	else if (n == 4)
		write(1, "Error\nIllegal character\n", 24);
	else if (n == 5)
		write(2, "Error\nIncorrect number of elements\n", 35);
	else if (n == 6)
		write(2, "Error\nCan't open the file\n", 27);
	else if (n == 7)
		write(1, "Error\nmalloc error\n", 19);
	else if (n == 8)
		write(1, "Error\nThe map must be surrounded by walls\n", 42);
	exit(1);
}
