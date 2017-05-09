/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 17:59:05 by pguillie          #+#    #+#             */
/*   Updated: 2017/03/05 18:30:14 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_disp_exit(t_mlx mlx)
{
	void	*img;
	char	*str;
	int		info[3];
	int		p;

	img = mlx_new_image(mlx.id, 50, 25);
	str = mlx_get_data_addr(img, info, info + 1, info + 2);
	p = 0;
	while (p < 25 * info[1])
	{
		str[p++] = 0;
		str[p++] = 0;
		str[p++] = 150;
		str[p++] = 0;
	}
	mlx_put_image_to_window(mlx.id, mlx.win, img, 2510, 0);
	mlx_string_put(mlx.id, mlx.win, 2515, 0, 0xffffff, "exit");
}
