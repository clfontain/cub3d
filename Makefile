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

DEPS		=	${OBJS:.o=.d}

LIBFT		=	./libft/libft.a

MAIN		=	./srcs/main.c

CORE		=	./srcs/core/mlx_init.c ./srcs/core/raycast.c ./srcs/core/linecrossed.c ./srcs/core/texture.c ./srcs/core/hooks.c ./srcs/core/tools.c


PARSING		=	./srcs/parsing/parsing.c\
				./srcs/parsing/copy_map.c\
				./srcs/parsing/parse_elem.c\
				./srcs/parsing/parsing_path.c\
				./srcs/parsing/parsing_map.c\
				./srcs/parsing/parsing_map_elem.c\
				./srcs/parsing/check_size_map.c\
				./srcs/parsing/check_color.c\
				./srcs/parsing/convert_color.c\
				./srcs/parsing/parse_elem2.c\

SRCS		=	${MAIN} ${CORE} ${PARSING}

OBJS		=	${SRCS:.c=.o}

RM			=	rm -f

CC			=	gcc

FLAGS		=	-MMD -Wall -Wextra -Werror -I includes/

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
		@${RM} ${OBJS} ${DEPS}
		@echo "OK\033[0m"

fclean		: clean
		@echo "\033[33m----Cleaning all----"
		@${RM} ${NAME}
		@${RM} ${LIBFT}
		@${RM} ${MLX}
		@echo "OK\033[0m"

re			: fclean all

.PHONY		: all clean fclean re

-include $(DEPS)