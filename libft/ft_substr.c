/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/11 15:10:15 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/04/04 14:54:58 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;
	size_t			len_s;

	len_s = ft_strlen(s);
	if (len > len_s)
		len = len_s;
	substr = (char *)malloc(len + 1);
	if ((substr == NULL) || (s == NULL))
		return (NULL);
	i = 0;
	if (len_s >= start)
	{
		while ((i < len) && (s[start + i] != '\0'))
		{
			substr[i] = s[start + i];
			i++;
		}
	}
	substr[i] = '\0';
	return (substr);
}
