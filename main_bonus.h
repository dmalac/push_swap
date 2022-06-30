/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_bonus.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/28 15:36:57 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/06/28 15:37:54 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_BONUS_H
# define MAIN_BONUS_H

typedef struct s_list
{
	int				x;
	int				is_last;
	struct s_list	*prev;
	struct s_list	*nxt;
}				t_list;

typedef struct s_tools
{
	void	(*action[7])(t_list **);
	char	**instruction;
	t_list	*a;
	t_list	*b;
}				t_tools;

#endif