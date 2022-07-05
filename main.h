/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/03 17:12:12 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/07/05 16:37:25 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "list_manipulation.h"	// maybe move all t_list stuff to one h file

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# define PX 0
# define SX 1
# define SS 2
# define RX 3
# define RR 4
# define RRX 5
# define RRR 6

/* main.c */
void	call_error(t_tools *tools);
void	erase_tools(t_tools **tools);
/* initialisations.c */
t_tools	*initialize(void);
int		how_many_tranches(int num_args);
/* input_checks.c */
int		is_sorted(t_list *lst);
int		only_digits(char *str);
int		is_int(char *num);

#endif