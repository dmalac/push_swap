/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_operations.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/04 11:21:23 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/05/11 12:46:05 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list_operations.h"
#include "libft/libft.h"
#include <stdlib.h>

t_list	*lst_new(char *num)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new)
	{
		new->x = ft_atoi(num);
		new->prev = NULL;
		new->nxt = NULL;
		new->is_last = 0;
	}
	return (new);
}

void	lst_erase(t_list **lst)
{
	// to be coded
	if (*lst)
		ft_printf("sth went wrong with mallocing the linked list\n");
	else
		ft_printf("sth went wrong with mallocing the linked list\n");
	exit (0);
}

void	lst_add_back(t_list **lst, t_list *new)
{
	t_list	*temp;
	t_list	*top;

	if (*lst == NULL)
	{
		*lst = new;
		new->nxt = new;
		new->prev = new;
		new->is_last = 1;
	}
	else
	{
		top = *lst;
		top->prev->is_last = 0;
		temp = top->prev;
		top->prev = new;
		new->nxt = top;
		temp->nxt = new;
		new->prev = temp;
		new->is_last = 1;
	}
}

void	lst_add_front(t_list **lst, t_list *new)
{
	t_list	*temp;
	t_list	*top;

	top = *lst;
	temp = top->prev;
	top->prev = new;
	new->nxt = top;
	temp->nxt = new;
	new->prev = temp;
	top = new;
}

void	create_lnkd_lst(char **input, int n, t_list **a)
{
	int		i;
	t_list	*new;

	i = 1;
	while (i < n)
	{
		new = lst_new(input[i]);
		if (!new)
			lst_erase(a);
		lst_add_back(a, new);
		i++;
	}
}

/* for testing purposes; to be removed at some point */
void	lst_print(t_list *top)
{
	t_list	*current;

	current = top;
	while (current->is_last != 1)
	{
		ft_printf("%d, %d\n", current->x, current->is_last);
		current = current->nxt;
	}
	ft_printf("%d, %d\n", current->x, current->is_last);
}
