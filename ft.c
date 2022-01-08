/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:24:53 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/12/26 16:25:12 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		ft_fileopen(t_all *s, char *file_name)
{
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1) //エラーは-1だけ?
		end(s, 3);
	return (fd);
}

void	*ft_malloc(t_all *s, int size)
{
	void	*tmp;

	tmp = malloc(size);
	if (tmp == NULL)
		end(s, 4);
	return (tmp);
}
