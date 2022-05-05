/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_operations.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/04 11:21:23 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/05/05 16:58:44 by dmalacov      ########   odam.nl         */
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
		new->last = 0;
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
		new->last = 1;
	}
	else
	{
		top = *lst;
		top->prev->last = 0;
		temp = top->prev;
		top->prev = new;
		new->nxt = top;
		temp->nxt = new;
		new->prev = temp;
		new->last = 1;
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

/* for testing purposes; to be removed at some point */
void	lst_print(t_list *top)
{
	t_list	*current;

	current = top;
	while (current->last != 1)
	{
		ft_printf("%d\n", current->x);
		current = current->nxt;
	}
	ft_printf("%d\n", current->x);
}
