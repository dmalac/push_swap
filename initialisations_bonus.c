/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialisations_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/05 15:54:11 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/07/06 18:57:22 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"
#include "libft/libft.h"
#include <stdlib.h>



t_tools	*initialize(void)
{
	t_tools	*tools;

	tools = malloc(sizeof(t_tools));
	if (!tools)
		call_error(tools);
	tools->a = NULL;
	tools->b = NULL;
	tools->action[SA] = swap;
	tools->action[SB] = swap;
	tools->action[SS] = swap;
	tools->action[RA] = rotate;
	tools->action[RB] = rotate;
	tools->action[RR] = rotate;
	tools->action[RRA] = rev_rotate;
	tools->action[RRB] = rev_rotate;
	tools->action[RRR] = rev_rotate;
	return (tools);
}
