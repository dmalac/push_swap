/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:36:41 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/04/11 16:53:03 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

/*--- ft_printf.c ---*/
int		ft_printf(const char *format, ...);
int		count_args(const char *format);
int		vprinter(const char *format, va_list arg, int num_args, int printed);
int		print_format(const char *format, int *i);
int		print_arg(const char *format, va_list arg, int i);
/*--- ft_printf_printers.c ---*/
int		print_arg_int(int a, const char *format, int i);
int		print_arg_ui(unsigned int a, const char *format, int i);
int		print_arg_ptr(const void *ptr, const char *format, int i);
int		print_int(int a, char *flags);
int		print_uns_int(unsigned int a);
/*--- ft_printf_support.c ---*/
char	*get_flags(const char *format, int i);
int		print_flags(unsigned int a, const char *format, int i);
char	*ultohex(unsigned long a, char c);
char	*uitohex(unsigned int a, char c);
/*--- ft_printf_flags.c ---*/
int		is_flag(char c);
int		contains(char *flags, char c);

#endif