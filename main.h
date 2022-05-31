/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/03 17:12:12 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/05/31 12:00:43 by dmalacov      ########   odam.nl         */
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

#define TRANCHES 3

/* main.c */
void	call_error(void);
/* input_processing.c */
int		doubles(t_list *lst, int n);
void	check_input(char **input, int num);
int		is_sorted(t_list *lst);

#endif