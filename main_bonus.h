/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_bonus.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/28 15:36:57 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/07/11 17:48:25 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_BONUS_H
# define MAIN_BONUS_H

# include "list_structure.h"

typedef struct s_checker_tools
{
	void	(*action[11])(t_list **);
	t_list	*a;
	t_list	*b;
}				t_checker_tools;

# define PA 0
# define PB 1
# define SA 2
# define SB 3
# define SS 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10

/* main_bonus.c */
void	call_error(t_checker_tools *tools);
/* input_processing_bonus.c */
void	process_input(char **input, int *num_args, t_checker_tools *tools);
/* line_checks_bonus.c */
int		is_push(char *line);
int		is_swap(char *line);
int		is_rotate(char *line);
/* line_processing_bonus.c */
void	read_follow_instructions(t_checker_tools **tools);

#endif