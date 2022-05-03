/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_int.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 17:52:59 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/02/10 18:43:50 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putstr_int(const char *s)
{
	int		i;
	ssize_t	printed;

	i = 0;
	printed = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
			printed += write(1, &s[i++], 1);
	}
	return ((int)printed);
}
