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

#include "../includes/select.h"

static t_tab_find	g_tab_find[] =
{
	{(int)27, (int)91, (int)68, &move_left},
	{(int)27, (int)91, (int)67, &move_right},
	{(int)32, (int)0, (int)0, &selectk},
	{(int)127, (int)0, (int)0, &deletek},
	{(int)27, (int)91, (int)51, &deletek2},
	{(int)27, (int)0, (int)0, &ft_exit},
	{(int)0, (int)0, (int)0, NULL},
};

void			get_key(char *buf2)
{
	int				i;

	i = -1;
	while (g_tab_find[++i].f)
	{
		if (buf2[0] == KEY1 && buf2[1] == KEY2 && buf2[2] == KEY3)
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

void			deletek2(void)
{
	char			bu[4];

	ft_bzero(bu, 4);
	read(0, bu, 3);
	if (bu[0] == 126 && bu[1] == 0 && bu[2] == 0)
		deletek();
}
