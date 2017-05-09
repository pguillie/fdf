/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_zoom.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:33:26 by pguillie          #+#    #+#             */
/*   Updated: 2017/03/05 15:11:17 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_zoom_plus(t_mlx mlx)
{
	void	*img;
	char	*str;
	int		info[3];
	int		p;

	img = mlx_new_image(mlx.id, 30, 30);
	str = mlx_get_data_addr(img, info, info + 1, info + 2);
	p = 0;
	while (p < 30 * info[1])
		str[p++] = 150;
	mlx_put_image_to_window(mlx.id, mlx.win, img, 2156, 1175);
	mlx_string_put(mlx.id, mlx.win, 2165, 1178, 0xaaaaaa, "+");
}

static void	ft_zoom_minus(t_mlx mlx)
{
	void	*img;
	char	*str;
	int		info[3];
	int		p;

	img = mlx_new_image(mlx.id, 30, 30);
	str = mlx_get_data_addr(img, info, info + 1, info + 2);
	p = 0;
	while (p < 30 * info[1])
		str[p++] = 150;
	mlx_put_image_to_window(mlx.id, mlx.win, img, 2200, 1175);
	mlx_string_put(mlx.id, mlx.win, 2209, 1178, 0xaaaaaa, "-");
}

static void	ft_z_plus(t_mlx mlx)
{
	void	*img;
	char	*str;
	int		info[3];
	int		p;

	img = mlx_new_image(mlx.id, 30, 30);
	str = mlx_get_data_addr(img, info, info + 1, info + 2);
	p = 0;
	while (p < 30 * info[1])
		str[p++] = 150;
	mlx_put_image_to_window(mlx.id, mlx.win, img, 2156, 1220);
	mlx_string_put(mlx.id, mlx.win, 2165, 1223, 0xaaaaaa, "Q");
}

static void	ft_z_minus(t_mlx mlx)
{
	void	*img;
	char	*str;
	int		info[3];
	int		p;

	img = mlx_new_image(mlx.id, 30, 30);
	str = mlx_get_data_addr(img, info, info + 1, info + 2);
	p = 0;
	while (p < 30 * info[1])
		str[p++] = 150;
	mlx_put_image_to_window(mlx.id, mlx.win, img, 2200, 1220);
	mlx_string_put(mlx.id, mlx.win, 2209, 1223, 0xaaaaaa, "E");
}

void		ft_disp_zoom(t_mlx mlx)
{
	void	*img;
	char	*str;
	int		info[3];
	int		p;

	img = mlx_new_image(mlx.id, 200, 120);
	str = mlx_get_data_addr(img, info, info + 1, info + 2);
	p = 0;
	while (p < 120 * info[1])
		str[p++] = 150;
	mlx_put_image_to_window(mlx.id, mlx.win, img, 2100, 1145);
	mlx_string_put(mlx.id, mlx.win, 2110, 1145, 0xffffff, "zoom");
	ft_zoom_plus(mlx);
	ft_zoom_minus(mlx);
	ft_z_plus(mlx);
	ft_z_minus(mlx);
}
