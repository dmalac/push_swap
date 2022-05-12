/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atol.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/11 13:22:12 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/05/12 11:13:51 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>	// delete

static long long	find_number(const char *str, int neg, int i)
{
	long long	number;

	number = 0;
	while ((str[i] >= '0') && (str[i] <= '9'))
		number = number * 10 + (str[i++] - '0');
	if (neg == -1)
		number = number * -1;
	return (number);
}

long long	ft_atol(const char *str)
{
	int			neg;
	int			i;
	long long	number;

	neg = 1;
	i = 0;
	while (((str[i] >= 9) && (str[i] <= 13)) || (str[i] == 32))
		i++;
	if (str[i] == '-')
		neg = neg * -1;
	if ((str[i] == '+') || (str[i] == '-'))
		i++;
	number = find_number(str, neg, i);
	return (number);
}

// int	main(void)
// {
// 	char	s1[] = "0";
// 	char	s2[] = "2147483659";
// 	char	s3[] = "-2147483659";
// 	char	s4[] = "9223372036854775807";
// 	char	s5[] = "9223372036854775847";
// 	long long	a, b, c, d, e;
	
// 	a = ft_atol(s1);
// 	b = ft_atol(s2);
// 	c = ft_atol(s3);
// 	d = ft_atol(s4);
// 	e = ft_atol(s5);
// 	printf("zero: %lld\nint max+: %lld\nint min-: %lld\nlong long max: %lld\nlong long max++: %lld\n", a, b, c, d, e);
// 	return (0);
// }