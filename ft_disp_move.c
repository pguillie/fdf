/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:23:04 by pguillie          #+#    #+#             */
/*   Updated: 2017/03/05 17:45:00 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_mv_left(t_mlx mlx)
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
	mlx_put_image_to_window(mlx.id, mlx.win, img, 280, 1350);
	mlx_string_put(mlx.id, mlx.win, 289, 1353, 0xaaaaaa, "A");
}

static void	ft_mv_updo(t_mlx mlx)
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
	mlx_put_image_to_window(mlx.id, mlx.win, img, 325, 1350);
	mlx_string_put(mlx.id, mlx.win, 334, 1353, 0xaaaaaa, "S");
	mlx_destroy_image(mlx.id, img);
	img = mlx_new_image(mlx.id, 30, 30);
	str = mlx_get_data_addr(img, info, info + 1, info + 2);
	p = 0;
	while (p < 30 * info[1])
		str[p++] = 150;
	mlx_put_image_to_window(mlx.id, mlx.win, img, 325, 1305);
	mlx_string_put(mlx.id, mlx.win, 334, 1308, 0xaaaaaa, "W");
}

static void	ft_mv_right(t_mlx mlx)
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
	mlx_put_image_to_window(mlx.id, mlx.win, img, 370, 1350);
	mlx_string_put(mlx.id, mlx.win, 379, 1353, 0xaaaaaa, "D");
}

static void	ft_mv_init(t_mlx mlx)
{
	void	*img;
	char	*str;
	int		info[3];
	int		p;

	img = mlx_new_image(mlx.id, 50, 30);
	str = mlx_get_data_addr(img, info, info + 1, info + 2);
	p = 0;
	while (p < 30 * info[1])
		str[p++] = (mlx.cen[0] == (int)(mlx.max[0] * mlx.coef[0] / 2)
				&& mlx.cen[1] == (int)(mlx.max[1] * mlx.coef[0] / 2) ?
				42 : 150);
	mlx_put_image_to_window(mlx.id, mlx.win, img, 260, 1305);
	mlx_string_put(mlx.id, mlx.win, 269, 1308, 0xaaaaaa, "tab");
}

void		ft_disp_move(t_mlx mlx)
{
	void	*img;
	char	*str;
	int		info[3];
	int		p;

	img = mlx_new_image(mlx.id, 300, 120);
	str = mlx_get_data_addr(img, info, info + 1, info + 2);
	p = 0;
	while (p < 120 * info[1])
		str[p++] = 150;
	mlx_put_image_to_window(mlx.id, mlx.win, img, 190, 1275);
	mlx_string_put(mlx.id, mlx.win, 200, 1275, 0xffffff, "move");
	ft_mv_updo(mlx);
	ft_mv_left(mlx);
	ft_mv_right(mlx);
	ft_mv_init(mlx);
}
