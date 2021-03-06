/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:05:06 by ytomiyos          #+#    #+#             */
/*   Updated: 2022/01/20 12:04:13 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_all *s)
{
	if (s->win != NULL)
		mlx_destroy_window(s->mlx, s->win);
	system("leaks so_long");
	exit(1);
}

void	map_free(t_all *s)
{
	int	i;

	if (s->map != NULL)
	{
		i = 0;
		while (i < s->map_h)
		{
			free(s->map[i]);
			i++;
		}
		free(s->map);
	}
}

void	end(t_all *s, int n)
{
	if (n == 0)
		printf("Usage: ./so_long [filename]\n");
	else if (n == 1)
		printf("Error\nMap error\n");
	else if (n == 2)
		printf("Error\nMap is not rectangular\n");
	else if (n == 3)
		printf("Error\nMap is not close\n");
	else if (n == 4)
		printf("Error\nIllegal character\n");
	else if (n == 5)
		printf("Error\nIncorrect number of elements\n");
	else if (n == 6)
		printf("Error\nCan't open the file\n");
	else if (n == 7)
		printf("Error\nmalloc error\n");
	else if (n == 8)
		printf("Error\nThe map must be surrounded by walls\n");
	else if (n == 9)
		printf("Error\nMap is too big\n");
	map_free(s);
	close_window(s);
}
