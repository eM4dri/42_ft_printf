/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 16:44:43 by emadriga          #+#    #+#             */
/*   Updated: 2021/07/17 20:15:29 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
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
