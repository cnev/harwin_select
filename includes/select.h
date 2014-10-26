/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjung <vjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/24 16:29:41 by vjung             #+#    #+#             */
/*   Updated: 2014/10/24 16:29:41 by vjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_H
# define SELECT_H
# define TERM get_termios(FALSE)
# define FD get_fd()
# define GLOB get_glob(FALSE)
# define TRUE		1
# define FALSE		0

typedef struct		s_glob
{
	t_dclist		*list;
}					t_glob;
typedef struct		s_data
{
	char			*str;
	int				x;
	int				y;
	int				selected;
}					t_data;
typedef struct		s_tab_find
{
	int				key1;
	int				key2;
	int				key3;
	void			(*f)(void);
}					t_tab_find;

/*
** cdlist.c
*/
void				cdlist_pushback(t_cdlist **head, void *data);
void				cdlist_delone(t_cdlist **head, t_cdlist *del);

/*
** display.c
*/
void				print_list(t_glob *glob);

/*
** getkey.c
*/
void			get_key(char *buf2);
void			move_left(void);
void			move_right(void);
void			selectk(void);
void			deletek(void);

/*
** list.c
*/
void			reinit_list(t_glob *glob);
void			create_list(int ac, char **av);

/*
** select.c
*/
int				exec_select(int ac, char **av);

/*
** signals.c
*/
void			signals_on(void);
void			handle_winch(void);
void			handle_tstp(void);
void			handle_cont(void);
void			handle_killers(void);
void			signal_handler(int sig);

/*
** singleton.c
*/
t_glob			get_glob(int end);
int				get_fd(void);
void			*get_termios(int end);
void			ft_exit(void);

#endif

