/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdlist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjung <vjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/24 18:26:00 by vjung             #+#    #+#             */
/*   Updated: 2014/10/24 18:26:00 by vjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static t_cdlist		*cdlist_new(void *data)
{
	t_cdlist		*new;

	if (!(new = (t_cdlist *)malloc(sizeof(t_cdlist))))
		return (NULL);
	new->data = data;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void				cdlist_pushback(t_cdlist **head, void *data)
{
	t_cdlist		*new;
	t_cdlist		*last;

	new = cdlist_new(data);
	if (!*head)
	{
		new->prev = new;
		new->next = new;
		*head = new;
		return ;
	}
	if (*head == (*head)->next)
	{
		(*head)->prev = new;
		(*head)->next = new;
		new->prev = *head;
		new->next = *head;
		return ;
	}
	last = (*head)->prev;
	last->next = new;
	(*head)->prev = new;
	new->prev = last;
	new->next = *head;
}

static void			cdlist_freeone(t_cdlist **del)
{
	free((*del)->data);
	free(*del);
	*del = NULL;
}

void			cdlist_delone(t_cdlist **head, t_cdlist *del)
{
	t_cdlist		*prev;
	t_cdlist		*next;

	if (del == *head && del->next == del)
	{
		cdlist_freeone(&del);
		*head = NULL;
		return ;
	}
	prev = del->prev;
	next = del->next;
	if (del == *head)
		*head = next;
	cdlist_freeone(&del);
	prev->next = next;
	next->prev = prev;
}
