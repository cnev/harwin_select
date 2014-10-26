/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjung <vjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 17:46:06 by vjung             #+#    #+#             */
/*   Updated: 2014/10/26 17:46:07 by vjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/select.h"

static int			check_before_display(int x, int y)
{
	if (x == -1 || y == -1)
		return (TRUE);
	return (FALSE);
}

void				print_selected(t_data *tmp, int fd)
{
	if (BAD_COORD)
		return ;
	tputs(tgoto(tgetstr("cm", NULL), X_POS, Y_POS), 1, tputs_putchar);
	tputs(tgetstr("mr", NULL), 1, tputs_putchar);
	write(fd, tmp->str, ft_strlen(tmp->str));
	tputs(tgetstr("me", NULL), 1, tputs_putchar);
}

void				print_cursor(t_data *tmp, int fd)
{
	if (BAD_COORD)
		return ;
	tputs(tgoto(tgetstr("cm", NULL), X_POS, Y_POS), 1, tputs_putchar);
	tputs(tgetstr("us", NULL), 1, tputs_putchar);
	write(fd, tmp->str, ft_strlen(tmp->str));
	tputs(tgetstr("ue", NULL), 1, tputs_putchar);
}

void				print_selected_cursor(t_data *tmp, int fd)
{
	if (BAD_COORD)
		return ;
	tputs(tgoto(tgetstr("cm", NULL), X_POS, Y_POS), 1, tputs_putchar);
	tputs(tgetstr("mr", NULL), 1, tputs_putchar);
	tputs(tgetstr("us", NULL), 1, tputs_putchar);
	write(fd, tmp->str, ft_strlen(tmp->str));
	tputs(tgetstr("ue", NULL), 1, tputs_putchar);
	tputs(tgetstr("me", NULL), 1, tputs_putchar);
}

void				print_default(t_data *tmp, int fd)
{
	if (BAD_COORD)
		return ;
	tputs(tgoto(tgetstr("cm", NULL), X_POS, Y_POS), 1, tputs_putchar);
	write(fd, tmp->str, ft_strlen(tmp->str));
}
