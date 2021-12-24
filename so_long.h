/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 13:30:49 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/12/24 16:56:43 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// open, close, read, write,
// printf, malloc, free, perror,
// strerror, exit

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "minilibx_mms/mlx.h"
# include "libft/libft.h"

# define KEY_ESC			53
# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define LEFT				123
# define RIGHT				124

typedef struct		s_img
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
}					t_img;

typedef struct		s_texture
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;

	int				width;
	int				height;
}					t_texture;

typedef struct		s_texs
{
	t_texture			floor;
	t_texture			wall;
	t_texture			player;
	t_texture			collectible;
	t_texture			exit;
}					t_texs;

typedef struct s_all
{
	// mlx
	void	*mlx;
	void	*win;
	t_img	img;

	// textures
	t_texs	texs;

	//vars
	int		screen_w;
	int		screen_h;
	char	*file_name;
}				t_all;

void	my_mlx_pixel_put(t_all *s, int x, int y, int color);
void	read_map(char *filename);
int		close_window(t_all *s);

int		gnl(int fd, char **line);


#endif
