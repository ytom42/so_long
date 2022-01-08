/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:05:06 by ytomiyos          #+#    #+#             */
/*   Updated: 2022/01/08 00:02:48 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		close_window(t_all *s)
{
	mlx_destroy_window(s->mlx, s->win);
	system("leaks so_long map1.ber"); //test
	exit(1);
}

void	end(t_all *s, int n)
{
	if (s->win != NULL)
		mlx_destroy_window(s->mlx, s->win);
	if (n == 0)
		write(1, "Usage: ./so_long [filename]\n", 28);
	else if (n == 1)
		write(1, "Error: Map error\n", 17);
	else if (n == 2)
		write(2, "Error: Map error\n", 17);
	else if (n == 3)
		write(2, "Error: Can't open the file\n", 27);
	else if (n == 4)
		write(1, "Error: malloc error\n" ,20);
	else if (n == 5)
		write(1, "Error: Map is not rectangular\n" ,30);
	exit(1);
}
