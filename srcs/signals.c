/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjung <vjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/24 16:32:30 by vjung             #+#    #+#             */
/*   Updated: 2014/10/24 16:32:30 by vjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/select.h"

void			signals_on(void)
{
	signal(SIGWINCH, signal_handler);
	signal(SIGTSTP, signal_handler);
	signal(SIGINT, signal_handler);
	signal(SIGTERM, signal_handler);
}

void			handle_winch(void)
{
	struct winsize	w;

	signal(SIGWINCH, SIG_IGN);
	ioctl(0, TIOCGWINSZ, &w);
	(GLOB)->wcol = w.ws_col;
	(GLOB)->wlin = w.ws_row;
	reinit_list(GLOB);
	print_list(GLOB->list);
	signal(SIGWINCH, signal_handler);
}

void			handle_tstp(void)
{
	char			cp[2];

	cp[0] = (TERM)->c_cc[VSUSP];
	cp[1] = 0;
	term_off(TERM);
	signal(SIGTSTP, SIG_DFL);
	signal(SIGCONT, signal_handler);
	ioctl(0, TIOCSTI, cp);
}

void			handle_cont(void)
{
	term_on(TERM);
	signal(SIGCONT, SIG_DFL);
	signal(SIGTSTP, signal_handler);
	print_list(GLOB->list);
}

void			handle_killers(void)
{
	ft_exit();
}
