/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calibrate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 17:28:35 by pguillie          #+#    #+#             */
/*   Updated: 2017/03/07 15:18:07 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_calibrate(int *dim, int *max, float *coef, int *info)
{
	float	x;
	float	y;

	x = sqrt(max[0] * max[0] + max[1] * max[1]);
	y = sqrt(max[0] * max[0] + max[1] * max[1]) / sqrt(3)
		+ max[2] * sqrt((float)2 / 3) - max[3] * sqrt((float)2 / 3);
	coef[0] = MIN((x ? (float)dim[0] / (float)x : 1),
			(y ? (float)dim[1] / (float)y : 1));
	!coef[0] ? coef[0] = 1 : 0;
	dim[2] = dim[0] / 2 * info[0] / 8
		+ info[1] * (dim[1] / 2
			+ (int)(max[2] * coef[0] * sqrt((float)2 / 3)) / 2
			+ (int)(max[3] * coef[0] * sqrt((float)2 / 3)) / 2);
}
