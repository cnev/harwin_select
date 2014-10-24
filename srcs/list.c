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

void			create_list(int ac, char **av)
{
	t_glob			*glob;
	int				i;

	i = 0;
	glob = get_glob(0);
	glob->list = NULL;
	while (++i < ac)
		cdlist_push_back(&(glob->list), create_data(av[i]));

}
