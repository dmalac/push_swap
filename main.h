/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/03 17:12:12 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/05/04 18:20:26 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "list_operations.h"

/* main.c */
void	call_error(void);
/* input_processing.c */
void	process_input(int *input, int num, t_list **a);
int		no_doubles(int *input);
int		*check_input(char **arg, int num);

#endif