/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_converters.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 12:03:40 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/07/14 16:17:24 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*ultohex(unsigned long a, char c)
{
	char			*hex;
	int				exp;
	unsigned long	mod;

	exp = 1;
	while (a >= ft_power(16, exp) && exp < 16)
		exp++;
	hex = malloc(sizeof(char) * exp + 1);
	if (hex)
	{
		hex[exp--] = '\0';
		if (a == 0)
			hex[exp] = '0';
		while (a > 0)
		{
			mod = a % 16;
			if (mod >= 0 && mod <= 9)
				hex[exp--] = mod + 48;
			else if (mod >= 10 && mod <= 15)
				hex[exp--] = c - 33 + mod;
			a /= 16;
		}
	}
	return (hex);
}

char	*uitohex(unsigned int a, char c)
{
	char	*hex;
	int		exp;
	int		mod;

	exp = 1;
	while (a >= ft_power(16, exp) && exp < 8)
		exp++;
	hex = malloc(sizeof(char) * exp + 1);
	if (hex)
	{
		hex[exp--] = '\0';
		if (a == 0)
			hex[exp] = '0';
		while (a > 0)
		{
			mod = a % 16;
			if (mod >= 0 && mod <= 9)
				hex[exp--] = mod + 48;
			else if (mod >= 10 && mod <= 15)
				hex[exp--] = c - 33 + mod;
			a /= 16;
		}
	}
	return (hex);
}
