/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_center.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:18:13 by pguillie          #+#    #+#             */
/*   Updated: 2017/03/03 18:37:39 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_center(int *c, int *max, float coef)
{
	c[0] = max[0] * coef / 2;
	c[1] = max[1] * coef / 2;
}

void	ft_center(int *cen, float ang, int dir)
{
	if (dir == 1)
	{
		cen[0] -= (int)(cos(ang) * 100);
		cen[1] += (int)(sin(ang) * 100);
	}
	else if (dir == 2)
	{
		cen[0] += (int)(cos(ang) * 100);
		cen[1] -= (int)(sin(ang) * 100);
	}
	else if (dir == 3)
	{
		cen[0] += (int)(sin(ang) * 100);
		cen[1] += (int)(cos(ang) * 100);
	}
	else if (dir == 4)
	{
		cen[0] -= (int)(sin(ang) * 100);
		cen[1] -= (int)(cos(ang) * 100);
	}
}
