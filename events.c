/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:45:36 by pguillie          #+#    #+#             */
/*   Updated: 2017/03/05 18:02:39 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_data	*ft_event_rot(int dir, t_data *param)
{
	if (dir == 1)
	{
		if ((int)(param->mlx.rot * 100) == 314)
			param->mlx.rot = -M_PI;
		param->mlx.rot += M_PI / 8;
	}
	else if (dir == 2)
	{
		if ((int)(param->mlx.rot * 100) == -314)
			param->mlx.rot = M_PI;
		param->mlx.rot -= M_PI / 8;
	}
	else
		param->mlx.rot = M_PI_4;
	return (param);
}

t_data	*ft_event_move(int dir, t_data *param)
{
	if (dir == 1)
		ft_center(param->mlx.cen, param->mlx.rot, 1);
	else if (dir == 2)
		ft_center(param->mlx.cen, param->mlx.rot, 2);
	else if (dir == 3)
		ft_center(param->mlx.cen, param->mlx.rot, 3);
	else if (dir == 4)
		ft_center(param->mlx.cen, param->mlx.rot, 4);
	else if (dir == 5)
		ft_init_center(param->mlx.cen, param->mlx.max, param->mlx.coef[0]);
	return (param);
}

t_data	*ft_event_size(int val, t_data *param)
{
	if (val == 1)
	{
		param->mlx.coef[0] *= 2;
		param->mlx.cen[0] *= 2;
		param->mlx.cen[1] *= 2;
	}
	else if (val == 2 && param->mlx.coef[0] > 1)
	{
		param->mlx.coef[0] /= 2;
		param->mlx.cen[0] /= 2;
		param->mlx.cen[1] /= 2;
	}
	else if (val == 3 && param->mlx.coef[1] < 9)
		param->mlx.coef[1] += 0.2;
	else if (val == 4 && param->mlx.coef[1] > -9)
		param->mlx.coef[1] -= 0.2;
	return (param);
}

t_data	*ft_event_color(int val, t_data *param)
{
	param->mlx.color = val;
	return (param);
}

t_data	*ft_event_cursor(t_data *param)
{
	param->mlx.cur_val = ++param->mlx.cur_val % 2;
	return (param);
}
