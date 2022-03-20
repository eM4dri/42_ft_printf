/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 19:15:07 by emadriga          #+#    #+#             */
/*   Updated: 2021/11/14 08:54:39 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include	<unistd.h>
# include	<stdarg.h>
# define BASE10 "0123456789"
# define BASE16UPP "0123456789ABCDEF"
# define BASE16LOW "0123456789abcdef"
# define CONVERSIONS "cspdiuxX%"
# define NOTSIGNED 0

int     ft_putchar(char c);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
int     ft_printf_nbr(unsigned int u_nbr, char *base, int is_signed);
int		ft_printf_men(unsigned long long ull_nbr);
int		ft_printf(const char *input, ...);
#endif
