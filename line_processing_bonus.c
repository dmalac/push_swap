/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   line_processing_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/06 15:57:25 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/07/11 18:00:58 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"
#include "prototypes_shared.h"
#include "libft/libft.h"
#include <stdlib.h>

static void	perform_action(t_checker_tools *tools, int action_code, char stack)
{
	ft_printf("perform_action called\n");	// PB and SA cause segv
	if (action_code == PA)
		push(&tools->a, &tools->b);
	else if (action_code == PB)
	{
		ft_printf("about to call push PB\n");
		push(&tools->b, &tools->a);
	}
	else 
	{
		if (stack != 'b')
			tools->action[action_code](&tools->a);
		if (stack != 'a')
			tools->action[action_code](&tools->b);
	}
}

static void	process_line(char *line, t_checker_tools **tools)
{
	char	stack;
	int		len;
	int		action_code;
	
	len = ft_strlen(line);
	stack = line[len - 2];
	action_code = is_push(line);
	if (action_code < 0)
		action_code = is_swap(line);
	if (action_code < 0)
		action_code = is_rotate(line);
	if (action_code < 0)
		call_error(*tools);
	// ft_printf("[process_line] line is %s, stack is %c, action code is %d\n",line, stack, action_code);
	perform_action(*tools, action_code, stack);
	// lst_print(tools->a, 'A');
	// lst_print(tools->b, 'B'); // if b is NULL and a has more than 5 items, segfault
}

void	read_follow_instructions(t_checker_tools **tools)
{
	char	*line;
	int		counter;
	
	line = NULL;
	counter = 0;
	while (line || counter++ == 0)
	{
		// lst_print(tools->a, 'A');
		// lst_print(tools->b, 'B');
		line = get_next_line(0);
		// if (!tools->b)
		// 	ft_printf("there is no tools->b\n");
		if (line)
		{
			process_line(line, tools);
			free(line);
		}
	}
}
