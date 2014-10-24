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
	{(int), (int), (int), &select},
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
	t_dclist		*tmp;

	tmp = (get_glob(0))->list;


}

void			move_right()
{

}
