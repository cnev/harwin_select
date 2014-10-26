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



void			print_list(t_glob *glob)
{
	t_cdlist		*tmp;

	tmp = glob->list;
	while (tmp)
	{
		if (tmp == glob->list)
		{
			if (tmp->data->selected)
				print_selected_cursor();
			else
				print_cursor();
		}
		else
		{
			if (tmp->data->selected)
				print_selected();
			else
				print_default();
		}
		tmp = tmp->next;
	}
}
