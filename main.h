/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/03 17:12:12 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/05/06 13:06:24 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "list_operations.h"

# define INT_MAX_CHAR "2147483647"
# define INT_MIN_CHAR "-2147483648"

/* main.c */
void	call_error(void);
/* input_processing.c */
void	create_lnkd_lst(char **input, int num, t_list **a);
int		doubles(t_list *lst, int n);
void	check_input(char **input, int num);

#endif