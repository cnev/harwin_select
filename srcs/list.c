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



static t_data	*create_data(char *str, int x, int y)
{
	t_data			*new;

	if (!(new = (t_data *)malloc(sizeof(t_data))))
		ft_exit();
	new->str = str;
	new->x = x;
	new->y = y;
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
		cdlist_push_back(&(glob->list), create_data(ft_strdup(av[i]), x, y));
		x += glob->col_size;
		if (x > glob->wcol)
		{
			x = 0;
			y += 2;
		}
	}
	glob->list->cursored = TRUE;
}

void			reinit_list(t_glob *glob)
{
	int				x;
	int				y;
	t_cdlist		*tmp;

	tmp = glob->list;
	if (!tmp)
		return ;
	x = 0;
	y = 0;
	while (tmp)
	{
		if (y < glob->wlin)
		{
			if (x + (int)ft_strlen(tmp->str) > glob->wcol)
				next_line(&x, &y);
			set_coords(tmp, x, y)
			x += glob->col_size;
		}
		else
			set_coords(tmp, -1, -1);
		tmp = tmp->next;
		if (tmp == glob->list)
			break ;
	}
}
void			create_list(int ac, char **av)
{
	t_glob			*glob;

	glob = get_glob(FALSE);
	glob->col_size = define_colsize(ac, av);
	init_list(glob, ac, av);
}
