/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_power.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/08 14:32:32 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/02/15 10:59:51 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

unsigned long	ft_power(unsigned long a, int exp)
{
	unsigned long	result;

	if (exp == 0)
		return (1);
	result = a;
	while (exp-- > 1)
		result *= a;
	return (result);
}
