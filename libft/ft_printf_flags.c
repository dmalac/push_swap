/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_flags.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 12:53:57 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/07/14 16:19:53 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	is_flag(char c)
{
	if (c == '+')
		return (1);
	else if (c == '#')
		return (1);
	else if (c == ' ')
		return (1);
	else
		return (0);
}

int	contains(char *flags, char c)
{
	while (*flags)
	{
		if (*flags++ == c)
			return (1);
	}
	return (0);
}

char	*get_flags(const char *format, int i)
{
	char	*flags;
	int		x;

	x = 0;
	while (i >= x && is_flag(format[i - x - 1]) == 1)
		x++;
	flags = ft_substr(format, (unsigned int) i - x, x);
	return (flags);
}

int	print_flags(unsigned int a, const char *format, int i)
{
	char	*flags;
	int		printed;

	printed = 0;
	flags = get_flags(format, i);
	if (flags == NULL)
		return (-2);
	if (a != 0 && contains(flags, '#') == 1 && format[i] == 'x')
		printed = ft_putstr_int("0x");
	else if (a != 0 && contains(flags, '#') == 1 && format[i] == 'X')
		printed = ft_putstr_int("0X");
	free(flags);
	return (printed);
}
