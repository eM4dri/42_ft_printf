/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 19:15:07 by emadriga          #+#    #+#             */
/*   Updated: 2021/11/14 08:54:39 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include	<unistd.h>
# include	<stdarg.h>
# define BASE10 "0123456789"
# define BASE16UPP "0123456789ABCDEF"
# define BASE16LOW "0123456789abcdef"
# define CONVERSIONS "cspdiuxX%"
# define FLAGS "-0.# +"

typedef struct s_flags
{
	char	*base;
	int		dot;
	int		hash;
	int		left;
	size_t	len_prefix;
	char	plus_space;
	size_t	precision;
	int		precisionblocked;
	char	*prefix;
	int		space;
	size_t	width;
	int		zero;
}t_flags;

typedef struct s_inputs
{
	int				nbr;
	unsigned int	u_nbr;
}t_inputs;

void	ft_putchar_ntimes(char c, long ntimes);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
int		ft_printf_nbr(unsigned int u_nbr, t_flags *flags, char *base);
int		ft_printf_men(unsigned long long ull_nbr, t_flags *flags);
int		ft_process_flags(char conversion, va_list *args, t_flags *flags);
int		ft_printf(const char *input, ...);
#endif
