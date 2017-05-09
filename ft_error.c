/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 12:26:41 by pguillie          #+#    #+#             */
/*   Updated: 2017/03/06 15:39:54 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(const char *msg)
{
	ft_printf("{red}error: %s{eoc}\n", msg);
	exit(EXIT_FAILURE);
}

void	ft_usage(void)
{
	ft_printf("{red}usage: ./fdf <filename>\n{eoc}");
	exit(EXIT_FAILURE);
}
