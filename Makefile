# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/17 19:44:26 by emadriga          #+#    #+#              #
#    Updated: 2021/07/17 19:44:27 by emadriga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= ft_printf.c	\
		ft_printf_men.c \
		ft_printf_nbr.c \
		ft_utils.c

SRC_BONUS 	= ft_printf_bonus.c \
			ft_printf_men_bonus.c \
			ft_printf_nbr_bonus.c \
			ft_process_flags_bonus.c \
			ft_utils_bonus.c

NAME	= libftprintf.a

CC 		= gcc
RM 		= rm -f

FLAGS	= -Wall -Wextra -Werror

OBJS	= $(SRC:.c=.o)

OBJS_BONUS	= $(SRC_BONUS:.c=.o)

all:		$(NAME)

$(OBJS):	$(SRC)
			$(CC) $(FLAGS) -c $(SRC)

$(NAME):	$(OBJS) 
			ar rcs $(NAME) $(OBJS)

bonus:		fclean $(OBJS_BONUS)
			ar rcs $(NAME) $(OBJS_BONUS)
			

$(OBJS_BONUS):	$(SRC_BONUS)
				$(CC) $(FLAGS) -c $(SRC_BONUS)

clean:
		$(RM) $(OBJS) $(OBJS_BONUS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all bonus

.PHONY:	all bonus clean fclean re
