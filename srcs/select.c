/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjung <vjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/24 16:26:16 by vjung             #+#    #+#             */
/*   Updated: 2014/10/24 16:26:17 by vjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				exec_select(int ac, char **av)
{
	char			buf[2048] = "";
	char			buf2[4] = "";

	init_win();
	term_on(TERM);
	signals_on();
	tgetent(buf, getenv("TERM"));
	create_list(ac, av);
}
