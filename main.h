/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/03 17:12:12 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/05/03 18:52:28 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

typedef struct s_list
{
	int				x;
	struct s_list	*prev;
	struct s_list	*nxt;
}				t_list;

/* main.c */
void	call_error(void);
/* input_processing.c */
void	process_input(char **arg, t_list **a);
int		no_doubles(t_list *a);

#endif