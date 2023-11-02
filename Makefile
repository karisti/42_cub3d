# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: karisti- <karisti-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/13 11:52:25 by karisti-          #+#    #+#              #
#    Updated: 2023/11/02 19:23:46 by karisti-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Project compilation files and directories

NAME	=	cub3D

CFILE	=	main.c				\
			init.c				\
			parse_elems.c		\
			parse_map.c			\
			parse_helpers.c		\
			files.c				\
			utils.c				\
			draw3d.c			\
			draw3d_rays.c		\
			draw3d_helpers.c	\
			draw2d_minimap.c	\
			window.c			\
			key_hook.c			\
			paint.c				\
			

SRCSFD	=	srcs/
OBJSFD	=	objs/
HDR_INC	=	-I./includes/cub3d.h

SRCS	=	$(addprefix $(SRCSFD), $(CFILE))
OBJS	=	$(addprefix $(OBJSFD), $(CFILE:.c=.o))
# # # # # # # # # # # # # # # # # # # # # # # # # # # # #

# Libraries
LIBFT	=	libft/libft.a
MLX		=	-lmlx -framework OpenGL -framework AppKit
# # # # # # # # # # # # # # # # # # # # # # # # # # # # #

# Compilation
COMP	=	gcc
CFLAGS	=	-Wall -Wextra -Werror #-fsanitize=address
# # # # # # # # # # # # # # # # # # # # # # # # # # # # #

# Colors
RED		=	\033[0;31m
GREEN	=	\033[0;32m
NONE	=	\033[0m
# # # # # # # # # # # # # # # # # # # # # # # # # # # # #

all: check_libft project $(NAME)
	@echo "... project ready"

check_libft: $(LIBFT)

project:
	@echo "Checking project ..."

projectb:
	@echo "Checking project bonus ..."

$(LIBFT):
	@make -C libft bonus

$(OBJSFD):
	@mkdir $@
	@echo "\t[ $(GREEN)✔$(NONE) ] $@ directory"

$(OBJSFD)%.o: $(SRCSFD)%.c
	@$(COMP) $(CFLAGS) $(HDR_INC) -o $@ -c $<
	@echo "\t[ $(GREEN)✔$(NONE) ] $@ object"

$(NAME): $(OBJSFD) $(OBJS)
	@$(COMP) $(CFLAGS) $(OBJS) $(MLX) $(LIBFT) -o $@
	@echo "\t[ $(GREEN)✔$(NONE) ] $@ executable"

bonus: check_libft projectb $(NAME)
	@echo "... project bonus ready"

clean:
	@echo "Cleaning project ..."
	@/bin/rm -rf $(OBJSFD)
	@echo "\t[ $(RED)✗$(NONE) ] Objects directory"
	@make -C ./libft clean

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\t[ $(RED)✗$(NONE) ] $(NAME) executable"
	@make -C ./libft fclean

re: fclean all

.PHONY: check_libft project all clean fclean re
