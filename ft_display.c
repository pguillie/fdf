/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 13:17:10 by pguillie          #+#    #+#             */
/*   Updated: 2017/03/05 18:37:24 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_info_zoom_z(t_mlx mlx)
{
	char	*str;
	char	*tmp;

	str = ft_strnew(19);
	tmp = ft_strnew(3);
	str = ft_strcat(str, "z proportion : ");
	if (mlx.coef[1] < 0)
		str = ft_strcat(str, "-");
	tmp[0] = ABS(mlx.coef[1]) + '0';
	tmp[1] = '.';
	tmp[2] = (ABS(mlx.coef[1]) - ABS((int)mlx.coef[1])) * 10 + '0';
	if (tmp[2] == ':')
		tmp[2] = '0';
	str = ft_strcat(str, tmp);
	mlx_string_put(mlx.id, mlx.win, 2150, 120, 0xaaaaaa, str);
	ft_strdel(&str);
	ft_strdel(&tmp);
}

void	ft_display(t_mlx mlx, t_lst *coord)
{
	mlx.dat = ft_fill_image(mlx, coord);
	ft_cursor(mlx);
	mlx_put_image_to_window(mlx.id, mlx.win, mlx.img, 0, 0);
	ft_disp_info(mlx);
	ft_disp_pos(mlx, coord);
	ft_disp_move(mlx);
	ft_disp_rot(mlx);
	ft_disp_zoom(mlx);
	ft_disp_col(mlx);
	ft_disp_cur(mlx);
	ft_disp_exit(mlx);
	if (mlx.cur_val)
		mlx_put_image_to_window(mlx.id, mlx.win, mlx.cur, 875, (mlx.i_dim[2]
			- (mlx.i_dim[0] / 2 * mlx.info[0] / 8)) / mlx.info[1] - 125);
	mlx_put_image_to_window(mlx.id, mlx.win, mlx.cur, 2310, 1145);
}
