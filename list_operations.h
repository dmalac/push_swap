/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_operations.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/04 11:54:25 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/05/20 17:01:46 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_OPERATIONS_H
# define LIST_OPERATIONS_H

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
	t_list	**a;
	t_list	**b;
}		t_tools;

/* list_operations.c */
t_list	*lst_new(char *num);
void	lst_erase(t_list **lst);
void	lst_add_back(t_list **lst, t_list *new);
t_list	*lst_add_front(t_list **lst, t_list *new);
void	create_lnkd_lst(char **input, int n, t_list **a);
int		lst_size(t_list *lst);
int		lst_max(t_list *lst);
int		lst_min(t_list *lst);
void	lst_print(t_list *top, char list); // will be deleted
/* small_stack.c */
void	sort_small_stack(t_tools tools);
#endif