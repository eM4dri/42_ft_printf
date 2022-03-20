/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 16:44:43 by emadriga          #+#    #+#             */
/*   Updated: 2021/07/17 20:22:53 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_putchar_ntimes(char c, long ntimes)
{
	if (ntimes > 0)
		while (ntimes--)
			write(1, &c, 1);
}

int	ft_isdigit(int c)
{
	return (!(c < '0' || c > '9'));
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*mem;
	size_t	len;

	mem = (char *)s;
	len = ft_strlen(s) + 1;
	while (len-- > 0)
	{
		if (*mem++ == (char)c)
			return (--mem);
	}
	return (NULL);
}
