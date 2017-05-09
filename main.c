/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 12:27:11 by pguillie          #+#    #+#             */
/*   Updated: 2017/03/06 16:23:25 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_mlx	ft_init_mlx(void)
{
	t_mlx	mlx;

	mlx.id = NULL;
	mlx.win = NULL;
	mlx.img = NULL;
	mlx.dat = NULL;
	mlx.w_dim[0] = 2560;
	mlx.w_dim[1] = 1395;
	mlx.i_dim[0] = 2000;
	mlx.i_dim[1] = 1300;
	mlx.i_dim[2] = 0;
	mlx.info[0] = 0;
	mlx.info[1] = 0;
	mlx.info[2] = 0;
	mlx.max[0] = 0;
	mlx.max[1] = 0;
	mlx.max[2] = 0;
	mlx.max[3] = 0;
	mlx.rot = M_PI_4;
	mlx.coef[0] = 0;
	mlx.coef[1] = 1;
	mlx.color = 1;
	mlx.cur_val = 1;
	return (mlx);
}

static t_data	*ft_init_param(t_lst *l, t_mlx m)
{
	t_data	*n;

	if (!(n = malloc(sizeof(t_lst*) + sizeof(t_mlx))))
		return (NULL);
	n->coord = l;
	n->mlx = m;
	return (n);
}

int				main(int ac, char **av)
{
	t_data	*param;
	t_lst	*coord;
	t_mlx	mlx;

	if (ac != 2)
		ft_usage();
	coord = ft_get_coord(av[1]);
	mlx = ft_init_mlx();
	mlx.file = ft_filename(av[1]);
	ft_max(coord, mlx.max);
	mlx.id = mlx_init();
	mlx.win = mlx_new_window(mlx.id, mlx.w_dim[0], mlx.w_dim[1], "fdf");
	mlx.img = mlx_new_image(mlx.id, mlx.i_dim[0], mlx.i_dim[1]);
	mlx.dat = mlx_get_data_addr(mlx.img, mlx.info, mlx.info + 1, mlx.info + 2);
	mlx.cur = mlx_new_image(mlx.id, 250, 250);
	ft_calibrate(mlx.i_dim, mlx.max, mlx.coef, mlx.info);
	ft_init_center(mlx.cen, mlx.max, mlx.coef[0]);
	if (!(param = ft_init_param(coord, mlx)))
		ft_error("not enought memory to malloc");
	ft_display(mlx, coord);
	mlx_key_hook(mlx.win, ft_key_input, param);
	mlx_mouse_hook(mlx.win, ft_mouse_input, param);
	mlx_loop(mlx.id);
	return (0);
}
