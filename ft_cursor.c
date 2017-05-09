/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 18:48:05 by pguillie          #+#    #+#             */
/*   Updated: 2017/03/03 13:20:55 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*ft_put_pixel(char *d, int x, int y, unsigned char *c)
{
	int		pos;

	pos = x * 4 + y * 250 * 4 + 250 / 2 * 4 + 250 * 4 * 250 / 2;
	d[pos + 0] = c[0];
	d[pos + 1] = c[1];
	d[pos + 2] = c[2];
	d[pos + 3] = c[3];
	d[pos + 4] = c[0];
	d[pos + 5] = c[1];
	d[pos + 6] = c[2];
	d[pos + 7] = c[3];
	d[pos - 4] = c[0];
	d[pos - 3] = c[1];
	d[pos - 2] = c[2];
	d[pos - 1] = c[3];
	d[pos + 250 * 4 + 0] = c[0];
	d[pos + 250 * 4 + 1] = c[1];
	d[pos + 250 * 4 + 2] = c[2];
	d[pos + 250 * 4 + 3] = c[3];
	d[pos - 250 * 4 + 0] = c[0];
	d[pos - 250 * 4 + 1] = c[1];
	d[pos - 250 * 4 + 2] = c[2];
	d[pos - 250 * 4 + 3] = c[3];
	return (d);
}

static char	*ft_draw_line(char *d, t_pt a)
{
	float	m;
	float	p;

	m = (a.x ? (float)a.y / (float)a.x : 0);
	p = a.y - m * a.x;
	if (ABS(a.x) > ABS(a.y))
	{
		while (a.x)
		{
			d = ft_put_pixel(d, a.x, m * a.x + p, a.c);
			a.x += (a.x > 0 ? -1 : 1);
		}
	}
	else
	{
		while (a.y)
		{
			d = ft_put_pixel(d, m ? (a.y - p) / m : a.x, a.y, a.c);
			a.y += (a.y > 0 ? -1 : 1);
		}
	}
	return (d);
}

static t_pt	ft_rot(t_mlx mlx, int axis, int c)
{
	t_pt	p;
	float	len;
	float	ang;

	p.x = (axis == 1 ? 100 : 0);
	p.y = (axis == 2 ? 100 : 0);
	p.z = (axis == 3 ? 100 : 0);
	len = sqrt(p.x * p.x + p.y * p.y);
	ang = len ? acos(p.x / len) : 0;
	asin(p.y / len) < 0 ? ang *= -1 : 0;
	ang += mlx.rot;
	p.x = len * cos(ang);
	p.y = (len * sin(ang)) / sqrt(3) - p.z * sqrt((float)2 / 3);
	p.c[0] = c % 256;
	p.c[1] = c / 256 % 256;
	p.c[2] = c / (256 * 256) % 256;
	p.c[3] = c / (256 * 256 * 256) % 256;
	return (p);
}

void		ft_cursor(t_mlx mlx)
{
	char	*dat;
	int		i[3];
	int		pos;

	dat = mlx_get_data_addr(mlx.cur, i, i + 1, i + 2);
	pos = 0;
	while (pos < 250 * 250 * i[0] / 8)
	{
		dat[pos + 0] = 0;
		dat[pos + 1] = 0;
		dat[pos + 2] = 0;
		dat[pos + 3] = 255;
		pos += i[0] / 8;
	}
	dat = ft_draw_line(dat, ft_rot(mlx, 1, 0xff0000));
	dat = ft_draw_line(dat, ft_rot(mlx, 2, 0x00ff00));
	dat = ft_draw_line(dat, ft_rot(mlx, 3, 0x0000ff));
}
