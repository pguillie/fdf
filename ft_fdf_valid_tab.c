/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_valid_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 13:27:35 by pguillie          #+#    #+#             */
/*   Updated: 2017/03/10 13:53:05 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_valid_str(char *str)
{
	int		i;
	int		j;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] && str[i] != ',')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	if (i == 0)
		return (0);
	if (str[i] == ',')
	{
		j = i + 1;
		if ((str[j] == 'x' || str[j] == 'X') && j == i + 2)
			;
		else if (str[j] < '0' || (str[j] > '9' && str[i] < 'A') ||
				(str[j] > 'F' && str[j] < 'a') || str[j] > 'f')
			return (0);
	}
	return (1);
}

int			ft_fdf_valid_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		if (!ft_valid_str(tab[i++]))
			return (0);
	}
	return (i);
}
