# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: karisti- <karisti-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/13 11:52:25 by karisti-          #+#    #+#              #
#    Updated: 2021/11/26 17:37:28 by karisti-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Project compilation files and directories

NAME	=	libft.a

CFILE	=	ft_memset.c				\
			ft_bzero.c				\
			ft_memcpy.c				\
			ft_memccpy.c			\
			ft_memmove.c			\
			ft_memchr.c				\
			ft_memcmp.c				\
			ft_strlen.c				\
			ft_strlcpy.c			\
			ft_strlcat.c			\
			ft_strchr.c				\
			ft_strrchr.c			\
			ft_strnstr.c			\
			ft_strncmp.c			\
			ft_atoi.c				\
			ft_atol.c				\
			ft_isalpha.c			\
			ft_isdigit.c			\
			ft_isalnum.c			\
			ft_isascii.c			\
			ft_isprint.c			\
			ft_strisnum.c			\
			ft_toupper.c			\
			ft_tolower.c			\
			ft_calloc.c				\
			ft_strdup.c				\
			ft_substr.c				\
			ft_strjoin.c			\
			ft_strtrim.c			\
			ft_split.c				\
			ft_itoa.c				\
			ft_strmapi.c			\
			ft_putchar_fd.c			\
			ft_putchar.c			\
			ft_putstr_fd.c			\
			ft_putstr.c				\
			ft_putendl_fd.c			\
			ft_putnbr_fd.c			\
			ft_putnbr.c				\
			ft_strtoupper.c			\
			ft_memalloc.c			\
			ft_itoabase.c			\
			ft_ltoa.c				\
			ft_strfromchar.c		\
			ft_strjoinchar.c		\
			ft_get_next_line.c		\
			
CFILEB	=	ft_lstnew_bonus.c		\
			ft_lstadd_front_bonus.c	\
			ft_lstsize_bonus.c		\
			ft_lstlast_bonus.c		\
			ft_lstadd_back_bonus.c	\
			ft_lstdelone_bonus.c	\
			ft_lstclear_bonus.c		\
			ft_lstiter_bonus.c		\
			ft_lstmap_bonus.c		\
			ft_lstprint_bonus.c		\
			ft_lstrem_bonus.c		\

SRCSFD	=	srcs/
SRCSFDB	=	srcs/bonus/
OBJSFD	=	objs/
OBJSFDB	=	objs/
HDR_INC	=	-I./includes

SRCS	=	$(addprefix $(SRCSFD), $(CFILE))
SRCS_B	=	$(addprefix $(SRCSFDB), $(CFILEB))
OBJS	=	$(addprefix $(OBJSFD), $(CFILE:.c=.o))
OBJS_B	=	$(addprefix $(OBJSFDB), $(CFILEB:.c=.o))
# # # # # # # # # # # # # # # # # # # # # # # # # # # # #

# Compilation
COMP	=	gcc
CFLAGS	=	-Wall -Wextra -Werror
# # # # # # # # # # # # # # # # # # # # # # # # # # # # #

# Colors
RED		=	\033[0;31m
GREEN	=	\033[0;32m
NONE	=	\033[0m
# # # # # # # # # # # # # # # # # # # # # # # # # # # # #

all: project $(NAME)
	@echo "... libft ready"

project:
	@echo "Checking libft ..."

projectb:
	@echo "Checking libft with bonus ..."

$(OBJSFD):
	@mkdir $@
	@echo "\t[ $(GREEN)✔$(NONE) ] $@ directory"

$(OBJSFD)%.o: $(SRCSFD)%.c
	@$(COMP) $(CFLAGS) $(HDR_INC) -o $@ -c $<
	@echo "\t[ $(GREEN)✔$(NONE) ] $@ object"

$(OBJSFDB)%.o: $(SRCSFDB)%.c
	@$(COMP) $(CFLAGS) $(HDR_INC) -o $@ -c $<
	@echo "\t[ $(GREEN)✔$(NONE) ] $@ object"

$(NAME): $(OBJSFD) $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\t[ $(GREEN)✔$(NONE) ] $@ library"

bonus: projectb $(OBJSFD) $(OBJS) $(OBJS_B)
	@ar rc $(NAME) $(OBJS) $(OBJS_B)
	@ranlib $(NAME)
	@echo "\t[ $(GREEN)✔$(NONE) ] $(NAME) bonus library"
	@echo "... libft ready"

clean:
	@/bin/rm -rf $(OBJSFD)
	@echo "\t[ $(RED)✗$(NONE) ] libft Objects directory"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\t[ $(RED)✗$(NONE) ] libft library"

re: fclean all

.PHONY: project projectb all clean fclean re
