/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 14:49:57 by pguillie          #+#    #+#             */
/*   Updated: 2017/03/05 18:18:16 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_pos_xy(t_mlx mlx)
{
	char	*str;
	char	*tmp;

	tmp = ft_itoa(mlx.cen[0] / mlx.coef[0]);
	str = ft_strjoin("x : ", tmp);
	ft_strdel(&tmp);
	mlx_string_put(mlx.id, mlx.win, 2150, 570, 0xaaaaaa, str);
	ft_strdel(&str);
	str = ft_itoa(mlx.cen[1] / mlx.coef[0]);
	tmp = str;
	str = ft_strjoin("y : ", str);
	ft_strdel(&tmp);
	mlx_string_put(mlx.id, mlx.win, 2150, 600, 0xaaaaaa, str);
	ft_strdel(&str);
}

static void	ft_pos_color(t_mlx mlx, unsigned int color)
{
	void	*img;
	char	*str;
	int		info[3];
	int		p;
	char	c[4];

	c[0] = color % 256;
	c[1] = color / 256 % 256;
	c[2] = color / (256 * 256) % 256;
	c[3] = color / (256 * 256 * 256) % 256;
	img = mlx_new_image(mlx.id, 150, 50);
	str = mlx_get_data_addr(img, info, info + 1, info + 2);
	p = -1;
	while (++p < 50 * info[1])
		str[p] = c[p % 4];
	mlx_put_image_to_window(mlx.id, mlx.win, img, 2300, 600);
}

static void	ft_pos_col(t_mlx mlx, int x, int y, t_lst *coord)
{
	char			*str;
	char			*tmp;
	unsigned int	color;

	mlx_string_put(mlx.id, mlx.win, 2350, 530, 0xaaaaaa, "color :");
	color = 0;
	if (x >= 0 && x <= mlx.max[0] && y >= 0 && y <= mlx.max[1])
	{
		color = 0xffffff;
		if (mlx.color == 1)
			color = ft_pt_color(coord->zc[x][0] > 0 ? mlx.max[2] : mlx.max[3],
					coord->zc[x][0]);
		else if (mlx.color == 2)
			color = (unsigned int)coord->zc[x][1];
		tmp = ft_ntoa_base(color, 16);
		str = ft_strjoin("0x", tmp);
		ft_strdel(&tmp);
		mlx_string_put(mlx.id, mlx.win, 2300, 570, color, str);
		ft_strdel(&str);
	}
	ft_pos_color(mlx, color);
}

static void	ft_pos_z(t_mlx mlx, t_lst *coord)
{
	char	*str;
	char	*tmp;
	int		x;
	int		y;
	int		i;

	x = (int)(mlx.cen[0] / mlx.coef[0]);
	y = (int)(mlx.cen[1] / mlx.coef[0]);
	if (x >= 0 && x <= mlx.max[0] && y >= 0 && y <= mlx.max[1])
	{
		i = 0;
		while (i++ < y)
			coord = coord->next;
		tmp = ft_itoa(coord->zc[x][0]);
		str = ft_strjoin("z : ", tmp);
		ft_strdel(&tmp);
		mlx_string_put(mlx.id, mlx.win, 2150, 630, 0xaaaaaa, str);
		ft_strdel(&str);
	}
	else
		mlx_string_put(mlx.id, mlx.win, 2150, 630, 0xaaaaaa, "z :");
	ft_pos_col(mlx, x, y, coord);
}

void		ft_disp_pos(t_mlx mlx, t_lst *coord)
{
	void	*img;
	char	*str;
	int		info[3];
	int		p;

	img = mlx_new_image(mlx.id, 560, 200);
	str = mlx_get_data_addr(img, info, info + 1, info + 2);
	p = 0;
	while (p < 200 * info[1])
		str[p++] = 150;
	mlx_put_image_to_window(mlx.id, mlx.win, img, 2100, 500);
	mlx_string_put(mlx.id, mlx.win, 2110, 500, 0xffffff, "position");
	ft_pos_xy(mlx);
	ft_pos_z(mlx, coord);
}
