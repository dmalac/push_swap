/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/05 15:12:33 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/05/04 18:38:36 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>

// changed the file to see what makefile does

size_t			ft_strlen(const char *str);
int				ft_atoi(const char *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_itoa(int n);
int				ft_putchar_int(char c);
int				ft_putstr_int(const char *s);
unsigned long	ft_power(unsigned long a, int exp);
int				ft_printf(const char *format, ...);
char			*ft_uitoa(unsigned int n);
void			ft_bzero(void *s, size_t n);

#endif
