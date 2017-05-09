/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:23:53 by pguillie          #+#    #+#             */
/*   Updated: 2017/03/06 16:23:24 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_put_pixel(t_mlx mlx, int x, int y, t_pt c)
{
	int		pos;

	pos = x * mlx.info[0] / 8 + y * mlx.info[1] + mlx.i_dim[2];
	if (x > -mlx.i_dim[0] / 2 && x < mlx.i_dim[0] / 2
		&& y > -mlx.i_dim[2] / mlx.info[1]
		&& y < mlx.i_dim[1] - mlx.i_dim[2] / mlx.info[1])
	{
		mlx.dat[pos + 0] = c.c[0];
		mlx.dat[pos + 1] = c.c[1];
		mlx.dat[pos + 2] = c.c[2];
		mlx.dat[pos + 3] = c.c[3];
	}
}

static void	ft_draw_line(t_mlx mlx, t_pt a, t_pt b)
{
	t_pt	d;
	float	m;
	float	p;

	m = a.x != b.x ? ((float)b.y - (float)a.y) / ((float)b.x - (float)a.x) : 0;
	p = a.y - m * a.x;
	d.x = b.x - a.x;
	d.y = b.y - a.y;
	if (ABS(d.x) > ABS(d.y))
	{
		while (a.x != b.x)
		{
			ft_put_pixel(mlx, a.x, m * a.x + p, ft_grad(a, b, d));
			a.x += ABS(d.x) / d.x;
		}
	}
	else
	{
		while (a.y != b.y)
		{
			ft_put_pixel(mlx, m ? (a.y - p) / m : a.x, a.y, ft_grad(a, b, d));
			a.y += ABS(d.y) / d.y;
		}
	}
	ft_put_pixel(mlx, b.x, b.y, b);
}

static t_pt	ft_rotation(t_mlx mlx, int x, int y, int *zc)
{
	t_pt			p;
	float			xy[2];
	float			len;
	float			ang;
	unsigned int	color;

	xy[0] = (float)x * mlx.coef[0] - (float)mlx.cen[0];
	xy[1] = (float)y * mlx.coef[0] - (float)mlx.cen[1];
	len = sqrt(xy[0] * xy[0] + xy[1] * xy[1]);
	ang = len ? acos(xy[0] / len) : 0;
	asin(xy[1] / len) < 0 ? ang *= -1 : 0;
	ang += mlx.rot;
	p.x = len * cos(ang);
	p.y = (len * sin(ang)) / sqrt(3)
		- zc[0] * mlx.coef[0] * mlx.coef[1] * sqrt((float)2 / 3);
	color = 0xffffff;
	if (mlx.color == 1)
		color = ft_pt_color(zc[0] > 0 ? mlx.max[2] : mlx.max[3], zc[0]);
	else if (mlx.color == 2)
		color = (unsigned int)zc[1];
	p.c[0] = color % 256;
	p.c[1] = color / 256 % 256;
	p.c[2] = color / (256 * 256) % 256;
	p.c[3] = color / (256 * 256 * 256) % 256;
	return (p);
}

char		*ft_fill_image(t_mlx mlx, t_lst *coord)
{
	int		x;
	int		y;

	ft_memset(mlx.dat, 0, mlx.i_dim[1] * mlx.info[1]);
	y = 0;
	while (coord)
	{
		x = 0;
		while (coord->zc[x])
		{
			if (coord->zc[x + 1])
				ft_draw_line(mlx, ft_rotation(mlx, x, y, coord->zc[x]),
						ft_rotation(mlx, x + 1, y, coord->zc[x + 1]));
			if (coord->next)
				ft_draw_line(mlx, ft_rotation(mlx, x, y, coord->zc[x]),
						ft_rotation(mlx, x, y + 1, coord->next->zc[x]));
			if (!coord->zc[x + 1] && !coord->next)
				ft_draw_line(mlx, ft_rotation(mlx, x, y, coord->zc[x]),
						ft_rotation(mlx, x, y, coord->zc[x]));
			x++;
		}
		y++;
		coord = coord->next;
	}
	return (mlx.dat);
}
