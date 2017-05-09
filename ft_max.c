/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 17:12:43 by pguillie          #+#    #+#             */
/*   Updated: 2017/03/02 16:22:43 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_max(t_lst *coord, int *max)
{
	int	x;
	int	y;

	y = 0;
	while (coord)
	{
		x = 0;
		while (coord->zc[x])
		{
			coord->zc[x][0] > max[2] ? max[2] = coord->zc[x][0] : 0;
			coord->zc[x][0] < max[3] ? max[3] = coord->zc[x][0] : 0;
			x++;
		}
		coord = coord->next;
		y++;
	}
	max[0] = x - 1;
	max[1] = y - 1;
}
