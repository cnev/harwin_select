/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjung <vjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/24 16:29:41 by vjung             #+#    #+#             */
/*   Updated: 2014/10/24 16:29:41 by vjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_H
# define SELECT_H
# define TERM OK
typedef struct		s_glob
{
	t_dclist		*list;
}					t_glob;
typedef struct		s_tab_find
{
	int				key1;
	int				key2;
	int				key3;
	void			(*f)(void);
}					t_tab_find;
#endif

Crls.mR5
