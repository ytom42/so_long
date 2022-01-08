/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:24:53 by ytomiyos          #+#    #+#             */
/*   Updated: 2022/01/08 19:25:12 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_fileopen(t_all *s, char *file_name)
{
	int		fd;
	int		len;

	len = ft_strlen(file_name);
	if (len < 4 || file_name[len - 1] != 'r' || \
		file_name[len - 2] != 'e' || file_name[len - 3] != 'b')
		end(s, 6);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		end(s, 6);
	return (fd);
}

void	*ft_malloc(t_all *s, int size)
{
	void	*tmp;

	tmp = malloc(size);
	if (tmp == NULL)
		end(s, 7);
	return (tmp);
}
