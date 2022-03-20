/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 16:36:22 by emadriga          #+#    #+#             */
/*   Updated: 2021/07/17 20:07:15 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_printf_nbr(unsigned int u_nbr, char *base, int is_signed)
{
	size_t	len_unbr;
	size_t	len_base;

	len_base = ft_strlen(base);
	len_unbr = ft_numlen_base(u_nbr, len_base) + is_signed;
	if (is_signed)
		write(1, "-", 1);
	ft_putnbr_base(u_nbr, base, len_base);
	return (len_unbr);
}
