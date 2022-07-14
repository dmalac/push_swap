/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 11:25:07 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/07/14 16:20:24 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	count_args(const char *format)
{
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	while (format[i])
	{
		if (format[i++] == '%')
		{
			while (is_flag(format[i]) == 1)
				i++;
			if (format[i] && format[i] != '%')
				counter++;
			else
				i++;
		}	
	}
	return (counter);
}

int	print_format(const char *format, int *i)
{
	int	printed;
	int	new_printed;

	printed = 0;
	while (format[*i])
	{
		if (format[*i] == '%')
		{
			*i += 1;
			while (format[*i] && is_flag(format[*i]) == 1)
				*i += 1;
			if (format[*i] && format[*i] != '%')
				return (printed);
		}
		if (format[*i])
		{
			new_printed = ft_putchar_int(format[*i]);
			if (new_printed < 0)
				return (new_printed);
			printed += new_printed;
			*i += 1;
		}
	}
	return (printed);
}

int	print_arg(const char *format, va_list arg, int i)
{
	int	printed;

	printed = 0;
	if (format[i] == 'c' || format[i] == 'd' || format[i] == 'i')
		printed = print_arg_int(va_arg(arg, int), format, i);
	else if (format[i] == 's')
		printed = print_arg_ptr(va_arg(arg, const char *), format, i);
	else if (format[i] == 'p')
		printed = print_arg_ptr(va_arg(arg, void *), format, i);
	else if (format[i] == 'u' || format[i] == 'x' || format[i] == 'X')
		printed = print_arg_ui(va_arg(arg, unsigned int), format, i);
	return (printed);
}

int	vprinter(const char *format, va_list arg, int num_args, int printed)
{
	int	i;
	int	new_printed;

	i = 0;
	while (num_args-- > 0)
	{
		new_printed = print_format(format, &i);
		if (new_printed < 0)
			return (new_printed);
		else
			printed += new_printed;
		new_printed = print_arg(format, arg, i);
		if (new_printed < 0)
			return (new_printed);
		else
			printed += new_printed;
		if (i)
			i++;
	}
	new_printed = print_format(format, &i);
	if (new_printed < 0)
		return (new_printed);
	return (printed + new_printed);
}

int	ft_printf(const char *format, ...)
{
	int			num_args;
	int			printed;
	va_list		arg;

	printed = 0;
	num_args = count_args(format);
	va_start(arg, format);
	printed = vprinter(format, arg, num_args, printed);
	va_end(arg);
	if (printed == -1)
		ft_putstr_int("\nError during writing to stdout.\n");
	if (printed == -2)
		ft_putstr_int("\nError during allocating memory.\n");
	return (printed);
}
