# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 12:54:42 by akalimol          #+#    #+#              #
#    Updated: 2023/02/13 19:22:26 by akalimol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

SRCS		= ft_atoi.c ft_isascii.c ft_memmove.c ft_striteri.c ft_strmapi.c \
		  ft_putstr_fd.c ft_strjoin.c ft_strncmp.c ft_substr.c ft_bzero.c \
		  ft_isdigit.c ft_memset.c ft_split.c ft_strtrim.c ft_putendl_fd.c \
		  ft_strlcat.c ft_strnstr.c ft_tolower.c ft_calloc.c ft_isprint.c \
		  ft_strchr.c ft_memchr.c ft_putchar_fd.c ft_strlcpy.c ft_memcpy.c \
		  ft_strrchr.c ft_toupper.c ft_isalnum.c ft_itoa.c ft_isalpha.c \
		  ft_memcmp.c ft_putnbr_fd.c ft_strdup.c ft_strlen.c ft_strcmp.c \
		  ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
		  ft_lstiter.c ft_lstlast.c ft_lstnew.c ft_lstsize.c ft_lstmap.c \
		  ft_putchar_fd_upd.c ft_puthex.c ft_putnbr_fd_upd.c ft_putptr.c \
		  ft_putstr_fd_upd.c ft_putunbr.c ft_printf.c ft_printf_stderror.c \
		  get_next_line.c get_next_line_utils.c ft_strstr.c ft_free_array.c

SRCS_DIR	= ./srcs
BUILD_DIR	= ./.build
INCLUDES_DIR	= ./includes

OBJS            = $(addprefix $(BUILD_DIR)/, $(SRCS))
OBJS		:= $(OBJS:%.c=%.o)
SRCS		:= $(addprefix $(SRCS_DIR)/, $(SRCS))

CC		= cc
CFLAGS		= -Wall -Wextra -Werror
HFLAGS		= -I $(INCLUDES_DIR)

all:		$(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.c
	${CC} ${CFLAGS} $(HFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:		clean
	rm -f $(NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re bonus
