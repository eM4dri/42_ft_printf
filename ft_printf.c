/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 23:10:44 by emadriga          #+#    #+#             */
/*   Updated: 2021/07/17 14:14:34 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_str(char *str)
{
	size_t	len;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	return (write(1, str, len));
}

static int	ft_printf_conversion(char conversion, va_list *args)
{
	int	nbr;

	if (ft_strchr(CONVERSIONS, conversion))
	{
		if (conversion == '%')
			return (write(1, "%", 1));
		else if (conversion == 'c')
			return (ft_putchar((char )va_arg(*args, int)));
		else if (conversion == 's')
			return (print_str((char *)va_arg(*args, const char *)));
		else if (conversion == 'p')
			return (ft_printf_men(va_arg(*args, unsigned long long)));
		else if (conversion == 'x')
			return (ft_printf_nbr(va_arg(*args, int), BASE16LOW, NOTSIGNED));
		else if (conversion == 'X')
			return (ft_printf_nbr(va_arg(*args, int), BASE16UPP, NOTSIGNED));
		else if (conversion == 'd' || conversion == 'i' || conversion == 'u')
		{
			nbr = va_arg(*args, int);
			if (nbr < 0 && conversion != 'u')
				return (ft_printf_nbr(nbr * -1, BASE10, nbr < 0));
			return (ft_printf_nbr(nbr, BASE10, NOTSIGNED));
		}
	}
	return (0);
}

/**
 * ft_printf
 * * Emulate printf@stdio.h with some conversions (cspdiuxX%) & flags (-0.# +)
* @param s_const	String to process
* @param variadic	Variable arguments to handle with flags and \
conversions alocated at input
*/
int	ft_printf(const char *s_const, ...)
{
	va_list	args;
	int		print_count;
	char	*s;

	print_count = 0;
	va_start (args, s_const);
	s = (char *)s_const;
	while (*s != '\0')
	{
		if (*s == '%' && *(s + 1))
		{
			s++;
			print_count += ft_printf_conversion(*s, &args);
		}
		else
			print_count += write(1, s, 1);
		s++;
	}
	va_end (args);
	return (print_count);
}
