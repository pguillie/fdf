/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:50:16 by pguillie          #+#    #+#             */
/*   Updated: 2017/03/05 15:08:21 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_rot_left(t_mlx mlx)
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
	mlx_put_image_to_window(mlx.id, mlx.win, img, 613, 1350);
	mlx_string_put(mlx.id, mlx.win, 622, 1353, 0xaaaaaa, "<");
}

static void	ft_rot_init(t_mlx mlx)
{
	void	*img;
	char	*str;
	int		info[3];
	int		p;

	img = mlx_new_image(mlx.id, 74, 30);
	str = mlx_get_data_addr(img, info, info + 1, info + 2);
	p = 0;
	while (p < 30 * info[1])
		str[p++] = ((int)(mlx.rot * 10) == 7 ? 42 : 150);
	mlx_put_image_to_window(mlx.id, mlx.win, img, 613, 1305);
	mlx_string_put(mlx.id, mlx.win, 644, 1308, 0xaaaaaa, "5");
}

static void	ft_rot_right(t_mlx mlx)
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
	mlx_put_image_to_window(mlx.id, mlx.win, img, 657, 1350);
	mlx_string_put(mlx.id, mlx.win, 666, 1353, 0xaaaaaa, ">");
}

void		ft_disp_rot(t_mlx mlx)
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
	mlx_put_image_to_window(mlx.id, mlx.win, img, 500, 1275);
	mlx_string_put(mlx.id, mlx.win, 510, 1275, 0xffffff, "rotate");
	ft_rot_left(mlx);
	ft_rot_init(mlx);
	ft_rot_right(mlx);
}
