/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_uitoa.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/11 13:29:26 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/02/15 10:59:25 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	power_of_ten(unsigned int n)
{
	size_t	i;

	i = 0;
	while (n / 10 != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static char	*int_to_str(unsigned int n, char *str, size_t len)
{
	size_t	i;

	i = 0;
	if (n == 0)
	{
		str[i] = '0';
		i++;
	}
	else
	{
		while ((n / 10 != 0) || (n % 10 != 0))
		{
			str[len - 1 - i] = (n % 10) + 48;
			n = n / 10;
			i++;
		}
	}
	str[len] = '\0';
	return (str);
}

char	*ft_uitoa(unsigned int n)
{
	char	*str;
	size_t	len;

	len = power_of_ten(n);
	len++;
	str = (char *) malloc(len + 1);
	if (str == NULL)
		return (NULL);
	int_to_str(n, str, len);
	return (str);
}
