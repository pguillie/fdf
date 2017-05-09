/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_coord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 12:42:00 by pguillie          #+#    #+#             */
/*   Updated: 2017/03/10 13:52:50 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_lst	*ft_lst_new(int **coord, size_t size)
{
	t_lst	*new;

	if (!(new = malloc(size + sizeof(t_lst*))))
		return (NULL);
	new->zc = coord;
	new->next = NULL;
	return (new);
}

static t_lst	*ft_draught(char *str)
{
	char	**tab;
	int		**coord;
	int		i;

	if (!(tab = ft_strsplit(str, ' ')))
		return (NULL);
	if (!(i = ft_fdf_valid_tab(tab)))
		return (NULL);
	if (!(coord = (int**)malloc(sizeof(int*) * (i + 1))))
		return (NULL);
	coord[i] = NULL;
	while (i--)
	{
		if (!(coord[i] = (int*)malloc(sizeof(int) * 2)))
			return (NULL);
		coord[i][0] = ft_atoi(tab[i]);
		coord[i][1] = ft_atoi_base(ft_find_color(tab[i]), 16);
		!coord[i][1] ? coord[i][1] = 0x555555 : 0;
		free(tab[i]);
		tab[i] = NULL;
	}
	free(tab);
	tab = NULL;
	return (ft_lst_new(coord, sizeof(int*) * (i + 1)));
}

static void		*ft_clean_lst(t_lst *b)
{
	t_lst	*tmp;

	while (b)
	{
		ft_memdel((void**)&b->zc);
		tmp = b->next;
		ft_memdel((void**)&b);
		b = tmp;
	}
	return (NULL);
}

static t_lst	*ft_lst_add(t_lst *b, t_lst *n)
{
	t_lst	*l;
	int		i;

	if (!n)
		return (ft_clean_lst(b));
	if (!b)
		return ((b = n));
	i = 0;
	while (b->zc[i] && n->zc[i])
		i++;
	if (b->zc[i] != n->zc[i])
		return (ft_clean_lst(b));
	l = b;
	while (l->next)
		l = l->next;
	l->next = n;
	return (b);
}

t_lst			*ft_get_coord(char *file)
{
	t_lst	*begin;
	char	*line;
	int		fd;
	int		ret;

	begin = NULL;
	if ((fd = open(file, O_RDONLY)) < 0)
		ft_error("unable to open file");
	ft_printf("getting datas from {yellow}%s{eoc}... ", file);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		if (!(begin = ft_lst_add(begin, ft_draught(line))))
		{
			close(fd);
			ft_strdel(&line);
			ft_error("invalid file format");
		}
		ft_strdel(&line);
	}
	close(fd);
	(!ret && !begin ? ft_error("empty file") : 0);
	(ret == -1 ? ft_error("unable to read file.\
	Make sure you don't try to read a directory") : 0);
	ft_printf("{green} ok{eoc}\n");
	return (begin);
}
