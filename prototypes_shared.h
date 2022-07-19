/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prototypes_shared.h                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/07 17:29:58 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/07/19 10:50:37 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_SHARED_H
# define PROTOTYPES_SHARED_H

# include "list_structure.h"
# include <stdlib.h>

/* input_checks.c */
int		is_sorted(t_list *lst);
int		only_digits(char *str);
int		is_int(char *num);
int		is_unique(t_list *lst, int num);
/* list_creation.c */
int		create_lnkd_lst(char **input, int n, t_list **list);
t_list	*lst_add_front(t_list **lst, t_list *new);
/* list_operations.c */
size_t	lst_size(t_list *lst);
void	lst_erase(t_list **lst);
/* actions.c */
void	swap(t_list **lst);
void	push(t_list **to, t_list **from);
void	rotate(t_list **lst);
void	rev_rotate(t_list **lst);

#endif