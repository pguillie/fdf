/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 17:03:08 by pguillie          #+#    #+#             */
/*   Updated: 2017/03/05 10:59:31 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pt			ft_grad(t_pt a, t_pt b, t_pt d)
{
	t_pt	c;
	int		p;
	int		n;

	p = ABS(d.x) > ABS(d.y) ? a.x - (b.x - d.x) : a.y - (b.y - d.y);
	n = ABS(d.x) > ABS(d.y) ? d.x : d.y;
	c.c[0] = a.c[0] + (b.c[0] - a.c[0]) * p / n;
	c.c[1] = a.c[1] + (b.c[1] - a.c[1]) * p / n;
	c.c[2] = a.c[2] + (b.c[2] - a.c[2]) * p / n;
	c.c[3] = a.c[3] + (b.c[3] - a.c[3]) * p / n;
	return (c);
}

unsigned int	ft_pt_color(int max, int z)
{
	unsigned int	c;

	if (z > 0)
	{
		if (z > 0.6 * max)
			c = 0xFFFFFF;
		else if (z > 0.4 * max)
			c = 0x582900;
		else if (z > 0.2 * max)
			c = 0xCD853F;
		else if (z > 0.1 * max)
			c = 0xDDDE75;
		else
			c = 0x57D53B;
	}
	else
		c = 0x0000AA;
	return (c);
}
