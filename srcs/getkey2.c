/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getkey2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjung <vjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 19:55:53 by vjung             #+#    #+#             */
/*   Updated: 2014/10/26 19:55:54 by vjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/select.h"

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
	cdlist_delone(&(glob->list), tmp);
	glob->cursor = next;
	reinit_list(GLOB);
}
