/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_flags_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 23:13:17 by emadriga          #+#    #+#             */
/*   Updated: 2021/07/17 20:09:14 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	print_str(char *str, t_flags *f)
{
	size_t	len;
	size_t	padding;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (f->dot && len > f->precision)
		len = f->precision;
	if (f->width > len)
	{
		padding = f->width - len;
		if (f->left)
		{
			write(1, str, len);
			ft_putchar_ntimes(' ', padding);
		}
		else
		{
			ft_putchar_ntimes('0', padding * f->zero);
			ft_putchar_ntimes(' ', padding * !f->zero);
			write(1, str, len);
		}
		return (f->width);
	}
	return (write(1, str, len));
}

static int	print_char(char c, t_flags *flags)
{
	size_t	padding;

	if (flags->width)
	{
		padding = flags->width - 1;
		if (flags->left)
		{
			write(1, &c, 1);
			ft_putchar_ntimes(' ', padding);
		}
		else
		{
			if (flags->zero)
				ft_putchar_ntimes('0', padding);
			else
				ft_putchar_ntimes(' ', padding);
			write(1, &c, 1);
		}
		return (flags->width);
	}
	return (write(1, &c, 1));
}

static void	ft_set_prefix_flag(int nbr, t_flags *flags, char conversion)
{
	if (conversion == 'd' || conversion == 'i')
	{
		if (flags->plus_space == '+')
			flags->prefix = "+";
		if (flags->plus_space == ' ')
			flags->prefix = " ";
		if (nbr < 0)
			flags->prefix = "-";
	}
	else if (conversion == 'x' && flags->hash && nbr)
		flags->prefix = "0x";
	else if (conversion == 'X' && flags->hash && nbr)
		flags->prefix = "0X";
	flags->len_prefix = ft_strlen(flags->prefix);
}

static char	*ft_get_base(char conversion)
{
	if (conversion == 'X')
		return (BASE16UPP);
	else if (conversion == 'x')
		return (BASE16LOW);
	else
		return (BASE10);
}

int	ft_process_flags(char conversion, va_list *args, t_flags *flags)
{
	t_inputs	i;

	if (ft_strchr(CONVERSIONS, conversion))
	{
		if (conversion == '%')
			return (print_char('%', flags));
		else if (conversion == 'c')
			return (print_char((char)va_arg(*args, int), flags));
		else if (conversion == 's')
			return (print_str((char *)va_arg(*args, const char *), flags));
		else if (conversion == 'p')
			return (ft_printf_men(va_arg(*args, unsigned long long), flags));
		else
		{
			i.nbr = va_arg(*args, int);
			if (i.nbr < 0 && (conversion == 'd' || conversion == 'i'))
				i.u_nbr = i.nbr * -1;
			else
				i.u_nbr = i.nbr;
			ft_set_prefix_flag(i.nbr, flags, conversion);
			return (ft_printf_nbr(i.u_nbr, flags, ft_get_base(conversion)));
		}
	}
	return (0);
}
