/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjung <vjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/24 16:19:53 by vjung             #+#    #+#             */
/*   Updated: 2014/10/24 16:19:53 by vjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/select.h"

int				main(int ac, char **av)
{
	if (!(getenv("TERM")))
	{
		ft_putstr_fd("environment error\n", 2);
		return (0);
	}
	if (ac < 2)
	{
		ft_putstr_fd("parameters error\n", 2);
		return (0);
	}
	exec_select(ac, av);
	return (0);
}

