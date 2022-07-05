/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_manipulation.h                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/04 11:54:25 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/07/05 15:53:17 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_MANIPULATION_H
# define LIST_MANIPULATION_H

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
	int		tranches;
}				t_tools;

/* input_checks.c */
int		is_unique(t_list *lst, int num);
/* input_processing.c */
void	process_input(char **input, int *num_args, t_tools *tools);
/* list_creation.c */
t_list	*lst_new(int num);
void	lst_add_back(t_list **lst, t_list *new);
t_list	*lst_add_front(t_list **lst, t_list *new);
void	create_lnkd_lst(char **input, int n, t_tools *tools);
/* list_operations.c */
void	lst_erase(t_list **lst);
int		lst_size(t_list *lst);
int		lst_max(t_list *lst);
int		lst_min(t_list *lst);
void	lst_print(t_list *top, char list); // will be deleted
/* small_stack.c */
void	sort_small_stack(t_tools *tools);
/* large_stack.c */
void	sort_large_stack(t_tools *tools);
/* tranche_limits.c */
int		*get_limits(t_list *lst, int tranches);
#endif