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

static void			print_selected(t_data *tmp, int fd)
{
	tputs(tgoto(tgetstr("cm", NULL), X_POS, Y_POS), 1, tputs_putchar);
	tputs(tgetstr("mr", NULL), 1, tputs_putchar);
	write(fd, tmp->str, ft_strlen(tmp->str));
	tputs(tgetstr("me", NULL), 1, tputs_putchar);
}

static void			print_cursor(t_data *tmp, int fd)
{
	tputs(tgoto(tgetstr("cm", NULL), X_POS, Y_POS), 1, tputs_putchar);
	tputs(tgetstr("us", NULL), 1, tputs_putchar);
	write(fd, tmp->str, ft_strlen(tmp->str));
	tputs(tgetstr("ue", NULL), 1, tputs_putchar);
}

static void			print_selected_cursor(t_data *tmp, int fd)
{
	tputs(tgoto(tgetstr("cm", NULL), X_POS, Y_POS), 1, tputs_putchar);
	tputs(tgetstr("mr", NULL), 1, tputs_putchar);
	tputs(tgetstr("us", NULL), 1, tputs_putchar);
	write(fd, tmp->str, ft_strlen(tmp->str));
	tputs(tgetstr("ue", NULL), 1, tputs_putchar);
	tputs(tgetstr("me", NULL), 1, tputs_putchar);
}

static void			print_default(t_data *tmp, int fd)
{
	tputs(tgoto(tgetstr("cm", NULL), X_POS, Y_POS), 1, tputs_putchar);
	write(fd, tmp->str, ft_strlen(tmp->str));
}

void				print_list(t_cdlist *tmp)
{
	t_data			*data;

	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, tputs_putchar);
	tputs(tgetstr("cd", NULL), 1, tputs_putchar);
	while (tmp)
	{
		data = tmp->data;
		if (tmp == GLOB->cursor)
		{
			if (data->selected)
				print_selected_cursor(data, FD);
			else
				print_cursor(data, FD);
		}
		else
		{
			if (data->selected)
				print_selected(data, FD);
			else
				print_default(data, FD);
		}
		tmp = tmp->next;
		if (tmp == GLOB->list)
			break ;
	}
}
