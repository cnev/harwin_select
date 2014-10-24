/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjung <vjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/24 16:41:25 by vjung             #+#    #+#             */
/*   Updated: 2014/10/24 16:41:25 by vjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_glob			get_glob(int end)
{
	static t_glob	*donjon = NULL;

	if (!donjon && !end)
	{
		if (!(donjon = (t_glob *)malloc(sizeof(t_glob))))
			ft_exit();
	}
	else if (donjon && end)
		free(donjon);
	return (donjon);
}

int				get_fd(void)
{
	static int		instance = -1;

	if (instance == -1)
	{
		if ((instance = open("/dev/tty", O_WRONLY)) < 0)
			ft_exit();
	}
	return (instance);
}

void			ft_exit(void)
{
	term_off();
	get_glob(1);
}
