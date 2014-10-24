/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getkey.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjung <vjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/24 17:43:49 by vjung             #+#    #+#             */
/*   Updated: 2014/10/24 17:43:49 by vjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static t_tab_find	g_tab_find[] =
{
	{(int), (int), (int), &move_left},
	{(int), (int), (int), &move_right},
	{(int), (int), (int), &selectk},
	{(int), (int), (int), &deletek},
	{(int), (int), (int), &ft_exit},
	{(int), (int), (int), NULL},
};

void			get_key(char *buf2)
{
	int				i;

	i = -1;
	while (g_tab_find[++i].f)
	{
		if (buf2[0] == key1 && buf2[1] == key2 && buf2[2] == key3)
			g_tab_find[i].f();
	}
}

void			move_left(void)
{
	get_glob(FALSE)->cursor = get_glob(FALSE)->cursor->prev;
}

void			move_right(void)
{
	get_glob(FALSE)->cursor = get_glob(FALSE)->cursor->next;
}

void			selectk(void)
{
	t_data		*tmp;

	tmp = get_glob(FALSE)->cursor->data;
	tmp->selected = (tmp->selected) ? FALSE : TRUE;
}

void			deletek(void)
{
	t_glob			*glob;
	t_cdlist		*tmp;
	t_cdlist		*next;

	glob = get_glob(FALSE);
	tmp = glob->cursor;
	next = tmp->next;
	if (tmp == tmp->next)
		ft_exit();
	//del
	glob->cursor = next;
}
