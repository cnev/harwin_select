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
# include "stdlib.h"
# include "termios.h"
# include "termcap.h"
# include "signal.h"
# include "sys/ioctl.h"
# include "fcntl.h"
# include "../libft/includes/libft.h"
# define TERM				get_termios(FALSE)
# define FD					get_fd()
# define GLOB				get_glob(FALSE)
# define TRUE				1
# define FALSE				0
# define X_POS				tmp->x
# define Y_POS				tmp->y
# define KEY1				g_tab_find[i].key1
# define KEY2				g_tab_find[i].key2
# define KEY3				g_tab_find[i].key3
# define BAD_COORD			check_before_display(X_POS, Y_POS)

typedef struct termios		t_termios;
typedef struct				s_cdlist
{
	void					*data;
	struct s_cdlist			*next;
	struct s_cdlist			*prev;
}							t_cdlist;
typedef struct				s_glob
{
	t_cdlist				*list;
	int						wcol;
	int						wlin;
	int						col_size;
	t_cdlist				*cursor;
}							t_glob;
typedef struct				s_data
{
	char					*str;
	int						x;
	int						y;
	int						selected;
}							t_data;
typedef struct				s_tab_find
{
	int						key1;
	int						key2;
	int						key3;
	void					(*f)(void);
}							t_tab_find;

void						cdlist_pushback(t_cdlist **head, void *data);
void						cdlist_delone(t_cdlist **head, t_cdlist *del);

void						print_list(t_cdlist *tmp);
void						print_selected(t_data *tmp, int fd);
void						print_cursor(t_data *tmp, int fd);
void						print_selected_cursor(t_data *tmp, int fd);
void						print_default(t_data *tmp, int fd);

void						get_key(char *buf2);
void						move_left(void);
void						move_right(void);
void						selectk(void);
void						deletek2(void);
void						deletek(void);

void						reinit_list(t_glob *glob);
void						create_list(int ac, char **av);

void						set_coord(t_data *data, int x, int y);
void						next_line(int *x, int *y);

void						term_on(t_termios *term);
void						term_off(t_termios *term);
int							exec_select(int ac, char **av);

void						signals_on(void);
void						handle_winch(void);
void						handle_tstp(void);
void						handle_cont(void);
void						handle_killers(void);
void						signal_handler(int sig);

t_glob						*get_glob(int end);
int							get_fd(void);
t_termios					*get_termios(int end);
void						ft_exit(void);
int							tputs_putchar(int c);

#endif
