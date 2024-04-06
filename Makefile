# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkoechli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 17:33:09 by gkoechli          #+#    #+#              #
#    Updated: 2022/01/18 11:30:55 by gkoechli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = srcs/main.c\
	srcs/moves.c\
	srcs/moves_b.c\
	srcs/moves_a.c\
	srcs/quick.c\
	srcs/utils.c\
	srcs/small_ops.c\
	srcs/compare.c\
	srcs/efficiency.c\
	srcs/build.c

FLAGS = -Wall -Wextra -Werror

OBJS = ${SRCS:.c=.o}

$(NAME): ${OBJS}
	$(MAKE) -C ./libft
	gcc ${FLAGS} ${SRCS} ./libft/libft.a -o $(NAME)
.c.o:
	gcc ${FLAGS} -c $< -o ${<:.c=.o}
all: ${NAME}
clean:
	rm -f ${OBJS}
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ./libft/ fclean 

re: fclean all

.PHONY: all clean fclean re
