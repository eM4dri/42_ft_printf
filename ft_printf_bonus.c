/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 23:10:44 by emadriga          #+#    #+#             */
/*   Updated: 2021/07/18 15:29:02 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_init_flags(t_flags *f)
{
	f->base = "";
	f->dot = 0;
	f->hash = 0;
	f->left = 0;
	f->len_prefix = 0;
	f->plus_space = 0;
	f->precision = 0;
	f->precisionblocked = 0;
	f->prefix = "";
	f->width = 0;
	f->zero = 0;
}

static char	*ft_set_flag_after_number(char *s, t_flags *flags)
{
	if (!flags->dot || flags->precisionblocked)
		flags->width = 0;
	else
		flags->precision = 0;
	while (1)
	{
		if (!ft_isdigit(*s))
			break ;
		if (!flags->dot || flags->precisionblocked)
			flags->width = flags->width * 10 + (int)(*s - '0');
		else
			flags->precision = flags->precision * 10 + (int)(*s - '0');
		s++;
	}
	return (--s);
}

static void	ft_set_flag_dot_left(char c, t_flags *flags)
{
	if (c == '-')
	{
		flags->zero = 0;
		flags->left = 1;
	}
	else if (c == '.')
	{
		flags->dot = 1;
		flags->precisionblocked = 0;
	}
}

static void	ft_set_flags(char **s, t_flags *flags)
{
	*s += 1;
	while (1)
	{
		if (!ft_strchr(FLAGS, **s) && !ft_isdigit(**s))
			break ;
		else if (**s == '0' && !flags->left && !flags->width)
			flags->zero = 1;
		else if (**s == '-')
			ft_set_flag_dot_left(**s, flags);
		else if (**s == '+' || **s == ' ')
			flags->plus_space = **s;
		else if (**s == '.')
			ft_set_flag_dot_left(**s, flags);
		else if (**s == '#')
			flags->hash = 1;
		else if (**s != ' ')
			*s = ft_set_flag_after_number(*s, flags);
		if (**s != '.' && !ft_isdigit(**s) && flags->dot)
			flags->precisionblocked = 1 ;
		*s += 1;
	}
}

/**
 * ft_printf
 * * Emulate printf@stdio.h with some conversions (cspdiuxX%) & flags (-0.*# +)
* @param s_const	String to process
* @param variadic	Variable arguments to handle with flags and \
conversions alocated at input
*/
int	ft_printf(const char *s_const, ...)
{
	va_list	args;
	int		print_count;
	t_flags	flags;
	char	*s;

	print_count = 0;
	va_start (args, s_const);
	s = (char *)s_const;
	ft_init_flags(&flags);
	while (*s != '\0')
	{
		if (*s == '%' && *(s + 1))
		{
			ft_set_flags(&s, &flags);
			print_count += ft_process_flags(*s, &args, &flags);
			ft_init_flags(&flags);
		}
		else
			print_count += write(1, s, 1);
		s++;
	}
	va_end (args);
	return (print_count);
}
