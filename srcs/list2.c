/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjung <vjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/24 17:27:42 by vjung             #+#    #+#             */
/*   Updated: 2014/10/24 17:27:43 by vjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void			set_coord(t_cdlist *lst, int x, int y)
{
	lst->x = x;
	lst->y = y;
}

void			next_line(int *x, int *y);
{
	*x = 0
	*y += 2;
}
