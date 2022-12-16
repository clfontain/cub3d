# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/12 14:32:38 by cfontain          #+#    #+#              #
#    Updated: 2022/11/29 15:14:18 by cfontain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Cub3d

LIB_DIR		=	./libft

LIBFT		=	./libft/libft.a

MAIN		=	./srcs/main.c

CORE		=	

BUILTIN		=	

UTILITIES	= 	
				
PARSING		=	

SRCS		=	${MAIN} ${CORE} ${BUILTIN} ${UTILITIES} ${PARSING}

OBJS		=	${SRCS:.c=.o} 

RM			=	rm -f

CC			=	cc

FLAGS		=	-Wall -Wextra -Werror -g -I includes/

all			: ${NAME}

%.o: %.c
		@${CC} ${FLAGS}  -c $< -o ${<:.c=.o}

${LIBFT}	:
		@echo "\033[35m----Building libft----"
		@make -sC ${LIB_DIR}
		@echo "OK\033[0m"

${NAME}		: ${OBJS}  ${LIBFT}
		@echo "\033[34m----Compiling----"
		@${CC} ${FLAGS} ${OBJS} -L/usr/include -lreadline -ltermcap -o ${NAME} ${LIBFT}
		@echo "OK\033[0m"

clean		:
		@echo "\033[31m----Cleaning libft----"
		@make clean -sC ${LIB_DIR}
		@echo "OK"
		@echo "\033[31m----Cleaning objects----"
		@${RM} ${OBJS}
		@echo "OK\033[0m"

fclean		: clean
		@echo "\033[33m----Cleaning all----"
		@${RM} ${NAME}
		@${RM} ${LIBFT}
		@echo "OK\033[0m"

re			: fclean all

.PHONY		: all clean fclean re
