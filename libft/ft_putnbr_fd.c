/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/11 13:32:12 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/02/16 13:35:27 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	recursion(int n, int fd)
{	
	char	c;

	if ((n / 10 != 0) || (n % 10 != 0))
	{
		recursion(n / 10, fd);
		c = 48 - (n % 10);
		write(fd, &c, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		write(fd, "0", 1);
	else if (n < 0)
		write(fd, "-", 1);
	else
		n = n * -1;
	recursion(n, fd);
}
