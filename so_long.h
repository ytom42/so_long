/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 13:30:49 by ytomiyos          #+#    #+#             */
/*   Updated: 2022/01/18 15:18:36 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <stdbool.h>
# include "mlx.h"
# include "libft/libft.h"

# define KEYPRESS 			2
# define DESTROYNOTIFY		17

# define KEY_ESC			53
# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define LEFT				123
# define RIGHT				124

# define TEX_WIDTH			64
# define TEX_HEIGHT			64

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
}					t_img;

typedef struct s_texture
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;

	int				width;
	int				height;
}					t_texture;

typedef struct s_texs
{
	t_texture			floor;
	t_texture			wall;
	t_texture			player;
	t_texture			collect;
	t_texture			exit;
}					t_texs;

typedef struct s_all
{
	void	*mlx;
	void	*win;
	t_img	img;

	t_texs	texs;

	char	**map;
	int		move_n;
	int		player_x;
	int		player_y;
	int		player_n;
	int		colle_n;
	int		exit_n;
	int		screen_w;
	int		screen_h;
	char	*file_name;
	int		map_x;
	int		map_y;
	int		tex_x;
	int		tex_y;
	int		map_w;
	int		map_h;
	int		map_blank;
	bool	move;
}				t_all;

void	my_mlx_pixel_put(t_all *s, int x, int y, int color);
void	mlx_pixel_put_of_tex(t_all *s, int x, int y, t_texture *tex);
void	map_load(char *filename, t_all *s);
void	map_create(t_all *s, char *filename);
void	map_check(t_all *s);
void	flood_fill(t_all *s, int h, int w);
int		close_window(t_all *s);

void	create_window(t_all *s);
void	texture_load(t_all *s);
void	create_img(t_all *s);

int		push_key(int keycode, t_all *s);
void	move_up(t_all *s);
void	move_down(t_all *s);
void	move_right(t_all *s);
void	move_left(t_all *s);

int		ft_fileopen(t_all *s, char *file_name);
void	*ft_malloc(t_all *s, int size);

int		gnl(int fd, char **line);
void	end(t_all *s, int n);

#endif
