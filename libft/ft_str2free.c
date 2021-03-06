/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str2free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnev <cnev@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 09:54:42 by cnev              #+#    #+#             */
/*   Updated: 2014/01/18 09:54:43 by cnev             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void			ft_str2free(char **tab)
{
	int				i;

	i = 0;
	while ((tab[i]))
	{
		free((tab[i]));
		i++;
	}
	free(tab);
}
