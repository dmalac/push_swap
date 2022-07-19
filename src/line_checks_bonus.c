/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   line_checks_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/06 16:53:50 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/07/19 11:39:17 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main_bonus.h"

int	is_push(char *line)
{
	if (line[2] == '\0' || line[2] == '\n')
	{
		if (line[0] == 'p' && line[1] == 'a')
			return (PA);
		else if (line[0] == 'p' && line[1] == 'b')
			return (PB);
	}
	return (-1);
}

int	is_swap(char *line)
{
	if (line[2] == '\0' || line[2] == '\n')
	{
		if (line[0] == 's' && line[1] == 'a')
			return (SA);
		else if (line[0] == 's' && line[1] == 'b')
			return (SB);
		else if (line[0] == 's' && line[1] == 's')
			return (SS);
	}
	return (-1);
}

int	is_rotate(char *line)
{
	if (line[2] == '\0' || line[2] == '\n')
	{		
		if (line[0] == 'r' && line[1] == 'a')
			return (RA);
		else if (line[0] == 'r' && line[1] == 'b')
			return (RB);
		else if (line[0] == 'r' && line[1] == 'r')
			return (RR);
	}
	else if ((line[3] == '\0' || line[3] == '\n') && line[0] == 'r' && \
	line[1] == 'r')
	{
		if (line[2] == 'a')
			return (RRA);
		else if (line[2] == 'b')
			return (RRB);
		else if (line[2] == 'r')
			return (RRR);
	}
	return (-1);
}
