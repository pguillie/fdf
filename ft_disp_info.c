/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 14:38:21 by pguillie          #+#    #+#             */
/*   Updated: 2017/03/05 18:30:47 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_info_dim(t_mlx mlx)
{
	char	*str;
	char	*tmp;
	char	*x;
	char	*y;

	x = ft_itoa(mlx.max[0]);
	y = ft_itoa(mlx.max[1]);
	str = ft_strdup("(");
	tmp = ft_strjoin(str, x);
	ft_strdel(&str);
	str = ft_strjoin(tmp, " x ");
	ft_strdel(&tmp);
	tmp = ft_strjoin(str, y);
	ft_strdel(&str);
	str = ft_strjoin(tmp, ")");
	ft_strdel(&tmp);
	mlx_string_put(mlx.id, mlx.win, 2400, 80, 0xaaaaaa, str);
	ft_strdel(&x);
	ft_strdel(&y);
	ft_strdel(&str);
}

static void	ft_info_z(t_mlx mlx)
{
	char	*max;
	char	*min;
	char	*tmp;

	tmp = ft_itoa(mlx.max[2]);
	max = ft_strjoin("z max : ", tmp);
	ft_strdel(&tmp);
	tmp = ft_itoa(mlx.max[3]);
	min = ft_strjoin("z min : ", tmp);
	ft_strdel(&tmp);
	mlx_string_put(mlx.id, mlx.win, 2400, 100, 0xaaaaaa, max);
	mlx_string_put(mlx.id, mlx.win, 2400, 120, 0xaaaaaa, min);
	ft_strdel(&max);
	ft_strdel(&min);
}

static void	ft_info_zoom(t_mlx mlx)
{
	char	*zoom;
	char	*str;
	char	*tmp;

	if (mlx.coef[0] < 1)
	{
		tmp = ft_itoa((int)(mlx.coef[0] * 100));
		zoom = ft_strjoin("0.", tmp);
		ft_strdel(&tmp);
	}
	else
		zoom = ft_itoa((int)mlx.coef[0]);
	tmp = ft_strdup("zoom : ");
	str = ft_strjoin(tmp, zoom);
	ft_strdel(&tmp);
	ft_strdel(&zoom);
	mlx_string_put(mlx.id, mlx.win, 2150, 100, 0xaaaaaa, str);
	ft_strdel(&str);
}

static void	ft_info_ang(t_mlx mlx)
{
	char	*ang;
	char	*str;
	char	*tmp;

	tmp = ft_itoa(ABS(mlx.rot));
	if (mlx.rot < 0)
	{
		str = tmp;
		tmp = ft_strjoin("-", tmp);
		ft_strdel(&str);
	}
	ang = ft_itoa((ABS(mlx.rot) - ABS((int)mlx.rot)) * 1000);
	str = ft_strjoin("angle : ", tmp);
	ft_strdel(&tmp);
	tmp = ft_strjoin(".", ang);
	ft_strdel(&ang);
	ang = ft_strjoin(str, tmp);
	mlx_string_put(mlx.id, mlx.win, 2150, 80, 0xaaaaaaa, ang);
	ft_strdel(&ang);
	ft_strdel(&str);
	ft_strdel(&tmp);
}

void		ft_disp_info(t_mlx mlx)
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
	mlx_put_image_to_window(mlx.id, mlx.win, img, 2100, 0);
	mlx_string_put(mlx.id, mlx.win, 2110, 0, 0xffffff, "info");
	mlx_string_put(mlx.id, mlx.win, 2150, 50, 0xaa9020, mlx.file);
	ft_info_dim(mlx);
	ft_info_z(mlx);
	ft_info_ang(mlx);
	ft_info_zoom(mlx);
	ft_info_zoom_z(mlx);
}
