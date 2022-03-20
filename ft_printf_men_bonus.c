/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_men_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 16:40:28 by emadriga          #+#    #+#             */
/*   Updated: 2021/07/17 20:05:52 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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

int	ft_printf_men(unsigned long long ull_nbr, t_flags *flags)
{
	size_t	len_nbr;
	size_t	len_min;
	size_t	len_base;

	len_base = ft_strlen(BASE16LOW);
	len_nbr = ft_numlen_ull(ull_nbr, len_base);
	len_min = len_nbr;
	if (flags->precision > len_min)
		len_min = flags->precision;
	if (!flags->left)
		ft_putchar_ntimes(' ', flags->width - len_min - 2);
	write(1, "0x", 2);
	ft_putchar_ntimes('0', len_min - len_nbr);
	ft_putnbr_ull(ull_nbr, BASE16LOW, len_base);
	if (flags->left)
		ft_putchar_ntimes(' ', flags->width - len_min - 2);
	if (flags->width > len_min + 2)
		return (flags->width);
	return (len_min + 2);
}
