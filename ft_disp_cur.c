/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_cur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:27:17 by pguillie          #+#    #+#             */
/*   Updated: 2017/03/05 15:08:59 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_disp_cur(t_mlx mlx)
{
	void	*img;
	char	*str;
	int		info[3];
	int		p;

	img = mlx_new_image(mlx.id, 250, 250);
	str = mlx_get_data_addr(img, info, info + 1, info + 2);
	p = 0;
	while (p < 250 * info[1])
		str[p++] = (mlx.cur_val ? 42 : 150);
	mlx_put_image_to_window(mlx.id, mlx.win, img, 2310, 1145);
	mlx_string_put(mlx.id, mlx.win, 2320, 1145, 0xffffff, "cursor");
}
