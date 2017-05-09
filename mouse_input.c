/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:44:12 by pguillie          #+#    #+#             */
/*   Updated: 2017/03/05 18:37:25 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_ms_rot(int x, int y, t_data *param)
{
	if (x >= 613 && x <= 643 && y >= 1350 && y <= 1380)
		param = ft_event_rot(1, param);
	else if (x >= 657 && x <= 687 && y >= 1350 && y <= 1380)
		param = ft_event_rot(2, param);
	else if (x >= 613 && x <= 687 && y >= 1305 && y <= 1335)
		param = ft_event_rot(3, param);
	else
		return (0);
	return (1);
}

static int	ft_ms_move(int x, int y, t_data *param)
{
	if (x >= 280 && x <= 310 && y >= 1350 && y <= 1380)
		param = ft_event_move(1, param);
	else if (x >= 370 && x <= 400 && y >= 1350 && y <= 1380)
		param = ft_event_move(2, param);
	else if (x >= 325 && x <= 355 && y >= 1350 && y <= 1380)
		param = ft_event_move(3, param);
	else if (x >= 325 && x <= 355 && y >= 1305 && y <= 1335)
		param = ft_event_move(4, param);
	else if (x >= 260 && x <= 310 && y >= 1305 && y <= 1335)
		param = ft_event_move(5, param);
	else
		return (0);
	return (1);
}

static int	ft_ms_size(int x, int y, t_data *param)
{
	if (x >= 2156 && x <= 2186 && y >= 1175 && y <= 1205)
		param = ft_event_size(1, param);
	else if (x >= 2200 && x <= 2230 && y >= 1175 && y <= 1205
			&& param->mlx.coef[0] > 1)
		param = ft_event_size(2, param);
	else if (x >= 2156 && x <= 2186 && y >= 1220 && y <= 1250)
		param = ft_event_size(3, param);
	else if (x >= 2200 && x <= 2230 && y >= 1220 && y <= 1250)
		param = ft_event_size(4, param);
	else
		return (0);
	return (1);
}

static int	ft_ms_cur_col(int x, int y, t_data *param)
{
	if (x >= 2310 && x <= 2560 && y >= 1145 && y <= 1395)
		param = ft_event_cursor(param);
	else if (x >= 2163 && x <= 2193 && y >= 1350 && y <= 1380)
		param = ft_event_color(1, param);
	else if (x >= 2185 && x <= 2215 && y >= 1305 && y <= 1335)
		param = ft_event_color(2, param);
	else if (x >= 2210 && x <= 2240 && y >= 1350 && y <= 1380)
		param = ft_event_color(3, param);
	else
		return (0);
	return (1);
}

int			ft_mouse_input(int button, int x, int y, t_data *p)
{
	(void)button;
	if (x >= 2510 && x <= 2560 && y >= 0 && y <= 25)
		exit(EXIT_SUCCESS);
	else if (ft_ms_rot(x, y, p) || ft_ms_move(x, y, p)
			|| ft_ms_size(x, y, p) || ft_ms_cur_col(x, y, p))
	{
		mlx_clear_window(p->mlx.id, p->mlx.win);
		ft_display(p->mlx, p->coord);
		return (1);
	}
	return (0);
}
