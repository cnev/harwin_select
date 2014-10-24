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
	while (buf2 != )
	{
		get_key(buf2);
		print_list(get_glob(0));
		buf2[0] = buf2[1] = buf2[2] = buf2[3] = 0;
		read(0, buf2, 3);
	}
	print_output();
}
