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

#include "../includes/select.h"

static void		init_win(void)
{
	struct winsize	w;

	ioctl(0, TIOCGWINSZ, &w);
	(GLOB)->wcol = w.ws_col;
	(GLOB)->wlin = w.ws_row;
}

void			term_on(t_termios *term)
{
	tputs(tgetstr("ti", NULL), 1, &tputs_putchar);
	tputs(tgetstr("vi", NULL), 1, &tputs_putchar);
	tcgetattr(0, term);
	term->c_lflag &= ~(ICANON | ECHO);
	term->c_lflag |= ISIG;
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	tcsetattr(0, 0, term);
}

void			term_off(t_termios *term)
{
	tputs(tgetstr("ve", NULL), 1, &tputs_putchar);
	tputs(tgetstr("te", NULL), 1, &tputs_putchar);
	tcgetattr(0, term);
	term->c_lflag |= (ICANON | ECHO);
	term->c_lflag &= (ISIG);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	tcsetattr(0, 0, term);
}

static void		print_output(void)
{
	t_glob			*glob;
	t_cdlist		*list;
	int				first;
	t_data			*data;

	first = TRUE;
	glob = get_glob(FALSE);
	list = glob->list;
	while (list)
	{
		data = list->data;
		if (data->selected)
		{
			if (first)
				first = FALSE;
			if (!first)
				write(1, " ", 1);
			write(1, data->str, ft_strlen(data->str));
		}
		list = list->next;
		if (list == GLOB->list)
			break ;
	}
}

int				exec_select(int ac, char **av)
{
	char			buf[2048];
	char			buf2[4];

	init_win();
	create_list(ac, av);
	signals_on();
	tgetent(buf, getenv("TERM"));
	term_on(TERM);
	ft_bzero(buf, 2048);
	ft_bzero(buf2, 4);
	while (!(buf2[0] == 10 && buf2[1] == 0 && buf2[2] == 0))
	{
		get_key(buf2);
		print_list(GLOB->list);
		buf2[1] = 0;
		buf2[2] = 0;
		read(0, buf2, 3);
	}
	print_output();
	ft_exit();
	return (0);
}
