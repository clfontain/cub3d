# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 15:35:01 by cfontain          #+#    #+#              #
#    Updated: 2022/12/16 15:35:01 by cfontain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d

LIB_DIR		=	./libft

MLX_DIR		=	./minilibx-linux

MLX 		= ./minilibx-linux/libmlx.a


LIBFT		=	./libft/libft.a

MAIN		=	./srcs/main.c

CORE		=	

BUILTIN		=	

UTILITIES	= 	
				
PARSING		=	./srcs/parsing/parsing.c\
				./srcs/parsing/parse_elem.c\

SRCS		=	${MAIN} ${CORE} ${BUILTIN} ${UTILITIES} ${PARSING}

OBJS		=	${SRCS:.c=.o} 

RM			=	rm -f

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror -g3 -I includes/

FLAGS_LIB	= -lXext -lX11

all			: ${NAME}

%.o: %.c
		@${CC} ${FLAGS}  -c $< -o ${<:.c=.o}

${LIBFT}	:
		@echo "\033[35m----Building libft----"
		@make -sC ${LIB_DIR}
		@echo "OK\033[0m"

${MLX}		:
		  @echo "\033[35m----Building MLX----"
		  @make -sC ${MLX_DIR}
		  @echo "OK\033[0m"

${NAME}		: ${OBJS} ${LIBFT} ${MLX}
		@echo "\033[34m----Compiling----"
		@${CC} ${FLAGS} ${OBJS} -L ${MLX_DIR} -lmlx -lm ${FLAGS_LIB} -o ${NAME} ${LIBFT}
		@echo "OK\033[0m"

clean		:
		@echo "\033[31m----Cleaning libft----"
		@make clean -sC ${LIB_DIR}
		@echo "OK"
		@echo "\033[31m----Cleaning MLX----"
		@make clean -sC ${MLX_DIR}
		@echo "OK"
		@echo "\033[31m----Cleaning objects----"
		@${RM} ${OBJS}
		@echo "OK\033[0m"

fclean		: clean
		@echo "\033[33m----Cleaning all----"
		@${RM} ${NAME}
		@${RM} ${LIBFT}
		@${RM} ${MLX}
		@echo "OK\033[0m"

re			: fclean all

.PHONY		: all clean fclean re
