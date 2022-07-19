/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/05 15:12:33 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/07/19 10:53:25 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>

int				ft_atoi(const char *str);
long long		ft_atol(const char *str);
void			ft_bzero(void *s, size_t n);
char			*ft_itoa(int n);
unsigned long	ft_power(unsigned long a, int exp);
int				ft_printf(const char *format, ...);
int				ft_putchar_int(char c);
int				ft_putstr_int(const char *s);
char			**ft_split(char const *s, char c);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_uitoa(unsigned int n);
char			*get_next_line(int fd);

#endif
