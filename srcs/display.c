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

static void			print_selected(char *tmp, int fd)
{
	tputs(tgoto(tgetstr("cm", NULL), X_POS, Y_POS), 1, tputs_putchar);
	tputs(tgetstr("mr", NULL), 1, tputs_putchar);
	write(fd, tmp, ft_strlen(tmp));
	tputs(tgetstr("me", NULL), 1, tputs_putchar);
}

static void			print_cursor(char *tmp, int fd)
{
	tputs(tgoto(tgetstr("cm", NULL), X_POS, Y_POS), 1, tputs_putchar);
	tputs(tgetstr("us", NULL), 1, tputs_putchar);
	write(fd, tmp, ft_strlen(tmp));
	tputs(tgetstr("ue", NULL), 1, tputs_putchar);
}

static void			print_selected_cursor(char *tmp, int fd)
{
	tputs(tgoto(tgetstr("cm", NULL), X_POS, Y_POS), 1, tputs_putchar);
	tputs(tgetstr("mr", NULL), 1, tputs_putchar);
	tputs(tgetstr("us", NULL), 1, tputs_putchar);
	write(fd, tmp, ft_strlen(tmp));
	tputs(tgetstr("ue", NULL), 1, tputs_putchar);
	tputs(tgetstr("me", NULL), 1, tputs_putchar);
}

static void			print_default(char *tmp, int fd)
{
	tputs(tgoto(tgetstr("cm", NULL), X_POS, Y_POS), 1, tputs_putchar);
	write(fd, tmp, ft_strlen(tmp));
}

void				print_list(t_glob *glob)
{
	t_cdlist		*tmp;

	tmp = glob->list;
	while (tmp)
	{
		if (tmp == glob->list)
		{
			if (tmp->data->selected)
				print_selected_cursor(tmp->data->str, FD);
			else
				print_cursor(tmp->data->str, FD);
		}
		else
		{
			if (tmp->data->selected)
				print_selected(tmp->data->str, FD);
			else
				print_default(tmp->data->str, FD);
		}
		tmp = tmp->next;
	}
}
