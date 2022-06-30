/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/03 17:12:12 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/06/30 16:26:47 by dmalacov      ########   odam.nl         */
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
void	call_error(void);

/* input_checks.c */
int		are_there_doubles(t_list *lst);
int		is_sorted(t_list *lst);
int		only_digits(char *str);
int		is_int(char *num);

#endif