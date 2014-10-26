/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjung <vjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/24 16:39:21 by vjung             #+#    #+#             */
/*   Updated: 2014/10/24 16:39:23 by vjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/select.h"

static t_data	*set_data(char *str, int x, int y)
{
	t_data			*new;

	if (!(new = (t_data *)malloc(sizeof(t_data))))
		ft_exit();
	new->str = str;
	new->x = x;
	new->y = y;
	new->selected = FALSE;
	return (new);
}

static void		init_list(t_glob *glob, int ac, char **av)
{
	int				i;
	int				x;
	int				y;

	i = 0;
	x = 0;
	y = 0;
	glob->list = NULL;
	while (++i < ac)
	{
		if (x + glob->col_size < glob->wcol - 1)
			cdlist_pushback(&(glob->list), set_data(ft_strdup(av[i]), x, y));
		else
			cdlist_pushback(&(glob->list), set_data(ft_strdup(av[i]), -1, -1));
		y += 1;
		if (y > glob->wlin - 1)
		{
			x += glob->col_size;
			y = 0;
		}
	}
	glob->cursor = glob->list;
	reinit_list(glob);
}

void			reinit_list(t_glob *glob)
{
	int				xy[2];
	t_cdlist		*tmp;
	t_data			*data;

	tmp = glob->list;
	if (!tmp)
		return ;
	ft_bzero(xy, sizeof(int) * 2);
	while (tmp)
	{
		data = tmp->data;
		if (xy[0] + glob->col_size < glob->wcol - 1)
			set_coord(data, xy[0], xy[1]);
		else
			set_coord(data, -1, -1);
		xy[1]++;
		if (xy[1] > glob->wlin - 1)
		{
			xy[0] += glob->col_size;
			xy[1] = 0;
		}
		tmp = tmp->next;
		if (tmp == glob->list)
			break ;
	}
}

int				define_colsize(int ac, char **av)
{
	int				i;
	int				max;

	max = -1;
	i = 0;
	while (++i < ac)
	{
		if (max < (int)ft_strlen(av[i]))
			max = (int)ft_strlen(av[i]);
	}
	return (max + 1);
}

void			create_list(int ac, char **av)
{
	t_glob			*glob;

	glob = get_glob(FALSE);
	glob->col_size = define_colsize(ac, av);
	init_list(glob, ac, av);
}
