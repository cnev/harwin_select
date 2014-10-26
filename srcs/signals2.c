/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjung <vjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 19:56:10 by vjung             #+#    #+#             */
/*   Updated: 2014/10/26 19:56:10 by vjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/select.h"

void			signal_handler(int sig)
{
	if (sig == SIGTSTP)
		handle_tstp();
	if (sig == SIGCONT)
		handle_cont();
	if (sig == SIGWINCH)
		handle_winch();
	if (sig == SIGINT || sig == SIGTERM)
		handle_killers();
}
