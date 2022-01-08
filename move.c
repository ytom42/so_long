/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 23:44:49 by ytomiyos          #+#    #+#             */
/*   Updated: 2022/01/07 23:52:45 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_all *s)
{
	char	*now;
	char	*next;

	now = &s->map[s->player_y][s->player_x];
	next = &s->map[s->player_y - 1][s->player_x];
	if (*next == '1')
		return ;
	if (*next == 'C')
		s->colle_n--;
	else if (*next == 'E' && s->colle_n != 0)
		return ;
	else if (*next == 'E' && s->colle_n == 0)
		s->exit_n--;
	*now = '0';
	*next = 'P';
	s->player_y--;
	s->move_n++;
	s->move = true;
}

void	move_down(t_all *s)
{
	char	*now;
	char	*next;

	now = &s->map[s->player_y][s->player_x];
	next = &s->map[s->player_y + 1][s->player_x];
	if (*next == '1')
		return ;
	if (*next == 'C')
		s->colle_n--;
	else if (*next == 'E' && s->colle_n != 0)
		return ;
	else if (*next == 'E' && s->colle_n == 0)
		s->exit_n--;
	*now = '0';
	*next = 'P';
	s->player_y++;
	s->move_n++;
	s->move = true;
}

void	move_right(t_all *s)
{
	char	*now;
	char	*next;

	now = &s->map[s->player_y][s->player_x];
	next = &s->map[s->player_y][s->player_x + 1];
	if (*next == '1')
		return ;
	if (*next == 'C')
		s->colle_n--;
	else if (*next == 'E' && s->colle_n != 0)
		return ;
	else if (*next == 'E' && s->colle_n == 0)
		s->exit_n--;
	*now = '0';
	*next = 'P';
	s->player_x++;
	s->move_n++;
	s->move = true;
}

void	move_left(t_all *s)
{
	char	*now;
	char	*next;

	now = &s->map[s->player_y][s->player_x];
	next = &s->map[s->player_y][s->player_x - 1];
	if (*next == '1')
		return ;
	if (*next == 'C')
		s->colle_n--;
	else if (*next == 'E' && s->colle_n != 0)
		return ;
	else if (*next == 'E' && s->colle_n == 0)
		s->exit_n--;
	*now = '0';
	*next = 'P';
	s->player_x--;
	s->move_n++;
	s->move = true;
}
