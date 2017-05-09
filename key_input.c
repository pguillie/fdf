/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 11:32:59 by pguillie          #+#    #+#             */
/*   Updated: 2017/03/05 18:37:29 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_key_rot(int key, t_data *param)
{
	if (key == 123)
		param = ft_event_rot(1, param);
	else if (key == 124)
		param = ft_event_rot(2, param);
	else if (key == 87)
		param = ft_event_rot(3, param);
	else
		return (0);
	return (1);
}

static int	ft_key_move(int key, t_data *param)
{
	if (key == 0)
		param = ft_event_move(1, param);
	else if (key == 2)
		param = ft_event_move(2, param);
	else if (key == 1)
		param = ft_event_move(3, param);
	else if (key == 13)
		param = ft_event_move(4, param);
	else if (key == 48)
		param = ft_event_move(5, param);
	else
		return (0);
	return (1);
}

static int	ft_key_size(int key, t_data *param)
{
	if (key == 69)
		param = ft_event_size(1, param);
	else if (key == 78 && param->mlx.coef[0] > 1)
		param = ft_event_size(2, param);
	else if (key == 12)
		param = ft_event_size(3, param);
	else if (key == 14)
		param = ft_event_size(4, param);
	else
		return (0);
	return (1);
}

static int	ft_key_cur_col(int key, t_data *param)
{
	if (key == 8)
		param = ft_event_cursor(param);
	else if (key == 18)
		param = ft_event_color(1, param);
	else if (key == 19)
		param = ft_event_color(2, param);
	else if (key == 20)
		param = ft_event_color(3, param);
	else
		return (0);
	return (1);
}

int			ft_key_input(int key, t_data *p)
{
	if (key == 53)
		exit(EXIT_SUCCESS);
	else if (ft_key_rot(key, p) || ft_key_move(key, p)
			|| ft_key_size(key, p) || ft_key_cur_col(key, p))
	{
		mlx_clear_window(p->mlx.id, p->mlx.win);
		ft_display(p->mlx, p->coord);
		return (1);
	}
	return (0);
}
