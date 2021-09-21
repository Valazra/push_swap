# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vazra <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/04 12:39:15 by vazra             #+#    #+#              #
#    Updated: 2021/09/15 16:01:25 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libft.a
CC 	= gcc
CFLAGS 	= -Wall -Wextra -Werror -Iincludes
RM	= rm -f
SRCS	= ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c ft_lstlast.c
OBJS 	= $(SRCS:.c=.o)

all: 	$(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS) $(BONUS_OBJS)

fclean:	clean
		$(RM) $(NAME)

re: 	fclean $(NAME)

.PHONY:		all clean fclean re
