/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_men.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 16:40:28 by emadriga          #+#    #+#             */
/*   Updated: 2021/07/17 20:13:34 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_numlen_ull(unsigned long long u_nbr, size_t len_base)
{
	size_t	len;

	len = 0;
	if (!u_nbr)
		return (1);
	while (u_nbr > 0 && ++len)
		u_nbr /= len_base;
	return (len);
}

static void	ft_putnbr_ull(unsigned long long u_nbr, char *base, size_t len_base)
{
	if (u_nbr >= len_base)
	{
		ft_putnbr_ull(u_nbr / len_base, base, len_base);
		ft_putnbr_ull(u_nbr % len_base, base, len_base);
	}
	else
		write(1, &base[u_nbr], 1);
}

int	ft_printf_men(unsigned long long ull_nbr)
{
	size_t	len_nbr;
	size_t	len_base;

	len_base = ft_strlen(BASE16LOW);
	len_nbr = ft_numlen_ull(ull_nbr, len_base);
	write(1, "0x", 2);
	ft_putnbr_ull(ull_nbr, BASE16LOW, len_base);
	return (len_nbr + 2);
}
