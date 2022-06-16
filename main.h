/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/03 17:12:12 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/06/16 14:28:41 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "list_operations.h"	// maybe move all t_list stuff to one h file

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# define PX 0
# define SX 1
# define SS 2
# define RX 3
# define RR 4
# define RRX 5
# define RRR 6

# ifndef TRANCHES
#  define TRANCHES 7
# endif

/* main.c */
void	call_error(void);
/* input_processing.c */
int		doubles(t_list *lst, int n);
void	check_input(char **input, int num);
int		is_sorted(t_list *lst);

#endif