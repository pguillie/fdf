/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_col.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 11:23:48 by pguillie          #+#    #+#             */
/*   Updated: 2017/03/05 15:08:50 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_color1(t_mlx mlx)
{
	void	*img;
	char	*str;
	int		info[3];
	int		p;

	img = mlx_new_image(mlx.id, 30, 30);
	str = mlx_get_data_addr(img, info, info + 1, info + 2);
	p = 0;
	while (p < 30 * info[1])
		str[p++] = (mlx.color == 1 ? 42 : 150);
	mlx_put_image_to_window(mlx.id, mlx.win, img, 2163, 1350);
	mlx_string_put(mlx.id, mlx.win, 2172, 1353, 0xaaaaaa, "1");
}

static void	ft_color2(t_mlx mlx)
{
	void	*img;
	char	*str;
	int		info[3];
	int		p;

	img = mlx_new_image(mlx.id, 30, 30);
	str = mlx_get_data_addr(img, info, info + 1, info + 2);
	p = 0;
	while (p < 30 * info[1])
		str[p++] = (mlx.color == 2 ? 42 : 150);
	mlx_put_image_to_window(mlx.id, mlx.win, img, 2185, 1305);
	mlx_string_put(mlx.id, mlx.win, 2194, 1308, 0xaaaaaa, "2");
}

static void	ft_color3(t_mlx mlx)
{
	void	*img;
	char	*str;
	int		info[3];
	int		p;

	img = mlx_new_image(mlx.id, 30, 30);
	str = mlx_get_data_addr(img, info, info + 1, info + 2);
	p = 0;
	while (p < 30 * info[1])
		str[p++] = (mlx.color == 3 ? 42 : 150);
	mlx_put_image_to_window(mlx.id, mlx.win, img, 2210, 1350);
	mlx_string_put(mlx.id, mlx.win, 2219, 1353, 0xaaaaaa, "3");
}

void		ft_disp_col(t_mlx mlx)
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
	mlx_put_image_to_window(mlx.id, mlx.win, img, 2100, 1275);
	mlx_string_put(mlx.id, mlx.win, 2110, 1275, 0xffffff, "color");
	ft_color1(mlx);
	ft_color2(mlx);
	ft_color3(mlx);
}
