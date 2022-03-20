/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 16:36:22 by emadriga          #+#    #+#             */
/*   Updated: 2021/07/18 15:25:48 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static size_t	ft_numlen_base(unsigned int u_nbr, size_t len_base)
{
	size_t	len;

	len = 0;
	if (!u_nbr)
		return (1);
	while (u_nbr > 0 && ++len)
		u_nbr /= len_base;
	return (len);
}

static void	ft_putnbr_base(unsigned int u_nbr, char *base, size_t len_base)
{
	if (u_nbr >= len_base)
	{
		ft_putnbr_base(u_nbr / len_base, base, len_base);
		ft_putnbr_base(u_nbr % len_base, base, len_base);
	}
	else
		write(1, &base[u_nbr], 1);
}

static int	ft_get_len_min(unsigned int u_nbr, size_t len_nbr, t_flags *flags)
{
	if (flags->dot && !flags->precision && u_nbr == 0 && !flags->width)
		return (0);
	else if (flags->precision > len_nbr)
		return (flags->precision);
	else if (!flags->precision && flags->zero && (flags->width > len_nbr))
		return (flags->width - flags->len_prefix);
	return (len_nbr);
}

int	ft_printf_nbr(unsigned int u_nbr, t_flags *flags, char *base)
{
	size_t	len_nbr;
	size_t	len_min;
	size_t	len_base;

	len_base = ft_strlen(base);
	len_nbr = ft_numlen_base(u_nbr, len_base);
	len_min = ft_get_len_min(u_nbr, len_nbr, flags);
	if (!flags->left)
		ft_putchar_ntimes(' ', flags->width - len_min - flags->len_prefix);
	if (flags->len_prefix)
		write(1, flags->prefix, flags->len_prefix);
	ft_putchar_ntimes('0', len_min - len_nbr);
	if ((!flags->precision && flags->dot && u_nbr == 0))
		write(1, " ", (flags->width > 0));
	else
		ft_putnbr_base(u_nbr, base, len_base);
	if (flags->left)
		ft_putchar_ntimes(' ', flags->width - len_min - flags->len_prefix);
	if (flags->width > len_min + flags->len_prefix)
		return (flags->width);
	return (len_min + flags->len_prefix);
}
