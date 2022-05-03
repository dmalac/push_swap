/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_printers.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 16:36:41 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/02/10 18:39:00 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(int a, char *flags)
{
	int		printed;
	int		new_printed;
	char	*num;

	printed = 0;
	new_printed = 0;
	num = ft_itoa(a);
	if (num == NULL)
		return (-2);
	if (contains(flags, '+') == 1 && a >= 0)
		new_printed = ft_putchar_int('+');
	else if (contains(flags, ' ') == 1 && a >= 0)
		new_printed = ft_putchar_int(' ');
	if (new_printed < 0)
		return (new_printed);
	printed += new_printed;
	new_printed = ft_putstr_int(num);
	if (new_printed < 0)
		return (new_printed);
	printed += new_printed;
	free (num);
	return (printed);
}

int	print_uns_int(unsigned int a)
{
	int		printed;
	char	*num;

	printed = 0;
	num = ft_uitoa(a);
	if (num == NULL)
		return (-2);
	printed = ft_putstr_int(num);
	free (num);
	return (printed);
}

int	print_arg_int(int a, const char *format, int i)
{
	int		printed;
	char	*flags;

	printed = 0;
	if (format[i] == 'c')
		printed = ft_putchar_int(a);
	else if (format[i] == 'd' || format[i] == 'i')
	{
		flags = get_flags(format, i);
		if (flags == NULL)
			return (-2);
		printed = print_int(a, flags);
		free(flags);
	}
	return (printed);
}

int	print_arg_ui(unsigned int a, const char *format, int i)
{
	char	*hex;
	int		printed;
	int		new_printed;

	printed = 0;
	if (format[i] == 'u')
		printed = print_uns_int(a);
	else if (format[i] == 'x' || format[i] == 'X')
	{
		printed = print_flags(a, format, i);
		if (printed < 0)
			return (printed);
		hex = uitohex(a, format[i]);
		if (hex == NULL)
			return (-2);
		new_printed = ft_putstr_int(hex);
		if (new_printed < 0)
			return (new_printed);
		printed += new_printed;
		free(hex);
	}
	return (printed);
}

int	print_arg_ptr(const void *ptr, const char *format, int i)
{
	int		printed;
	int		new_printed;
	char	*str;

	printed = 0;
	if (format[i] == 's' && ptr)
		printed = ft_putstr_int(ptr);
	else if (format[i] == 's')
		printed = ft_putstr_int("(null)");
	else if (format[i] == 'p')
	{
		str = ultohex((unsigned long)ptr, 'x');
		if (str == NULL)
			return (-2);
		printed = ft_putstr_int("0x");
		if (printed < 0)
			return (printed);
		new_printed = ft_putstr_int(str);
		if (new_printed < 0)
			return (new_printed);
		printed += new_printed;
		free(str);
	}
	return (printed);
}
