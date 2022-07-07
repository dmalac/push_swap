/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_structure.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/04 11:54:25 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/07/07 13:34:50 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_STRUCTURE_H
# define LIST_STRUCTURE_H

typedef struct s_list
{
	int				x;
	int				is_last;
	struct s_list	*prev;
	struct s_list	*nxt;
}				t_list;

#endif