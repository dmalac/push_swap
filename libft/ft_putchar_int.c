/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_int.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 17:50:59 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/02/10 17:35:31 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar_int(char c)
{
	ssize_t	printed;

	printed = write(1, &c, 1);
	return ((int)printed);
}
