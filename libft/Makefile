# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 12:54:42 by akalimol          #+#    #+#              #
#    Updated: 2023/05/28 18:55:26 by akalimol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

SRCS	= 	other/ft_atoi.c				\
			other/ft_itoa.c				\
			other/ft_tolower.c			\
			other/ft_toupper.c			\
			other/ft_isalnum.c			\
			other/ft_isalpha.c			\
			other/ft_isascii.c			\
			other/ft_isdigit.c			\
			other/ft_isprint.c			\
			other/ft_isspace.c			\
			mem_alloc/ft_bzero.c				\
			mem_alloc/ft_calloc.c				\
			mem_alloc/ft_strdup.c				\
			mem_alloc/ft_memchr.c				\
			mem_alloc/ft_memcmp.c				\
			mem_alloc/ft_memcpy.c				\
			mem_alloc/ft_memmove.c				\
			mem_alloc/ft_memset.c				\
			print/ft_putchar_fd.c			\
			print/ft_putendl_fd.c			\
			print/ft_putnbr_fd.c			\
			print/ft_putstr_fd.c			\
			print/ft_puthex.c \
			print/ft_putptr.c \
			print/ft_putunbr.c \
			print/ft_printf.c \
			print/ft_printf2.c \
			string/ft_split.c			\
			string/ft_strchr.c			\
			string/ft_striteri.c		\
			string/ft_strjoin.c			\
			string/ft_strlcat.c			\
			string/ft_strlcpy.c			\
			string/ft_strlen.c			\
			string/ft_strmapi.c			\
			string/ft_strcmp.c			\
			string/ft_strncmp.c			\
			string/ft_strnstr.c			\
			string/ft_strrchr.c			\
			string/ft_strtrim.c			\
			string/ft_substr.c			\
			string/ft_strstr.c			\
			linked_list/ft_lstadd_back.c    	\
			linked_list/ft_lstadd_front.c		\
			linked_list/ft_lstclear.c			\
			linked_list/ft_lstclear_safe.c		\
			linked_list/ft_lstdelone.c			\
			linked_list/ft_lstiter.c			\
			linked_list/ft_lstlast.c			\
			linked_list/ft_lstmap.c				\
			linked_list/ft_lstnew.c				\
			linked_list/ft_lstsize.c			\
			linked_list/ft_lstretrieve.c		\
			linked_list/ft_lstremove.c			\
			linked_list/ft_lstfirst.c			\
		  	get_next_line/get_next_line.c 		\
			get_next_line/get_next_line_utils.c  \

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


SRCS	= 	ft_atoi.c				\
			ft_bzero.c				\
			ft_calloc.c				\
			ft_isalnum.c			\
			ft_isalpha.c			\
			ft_isascii.c			\
			ft_isdigit.c			\
			ft_isprint.c			\
			ft_itoa.c				\
			ft_memchr.c				\
			ft_memcmp.c				\
			ft_memcpy.c				\
			ft_memmove.c			\
			ft_memset.c				\
			ft_putchar_fd.c			\
			ft_putendl_fd.c			\
			ft_putnbr_fd.c			\
			ft_putstr_fd.c			\
			ft_split.c				\
			ft_strchr.c				\
			ft_strdup.c				\
			ft_striteri.c			\
			ft_strjoin.c			\
			ft_strlcat.c			\
			ft_strlcpy.c			\
			ft_strlen.c				\
			ft_strmapi.c			\
			ft_strncmp.c			\
			ft_strnstr.c			\
			ft_strrchr.c			\
			ft_strtrim.c			\
			ft_substr.c				\
			ft_tolower.c			\
			ft_toupper.c			\

BONUS_SRCS =    ft_lstadd_back.c    	\
				ft_lstadd_front.c		\
				ft_lstclear.c			\
				ft_lstdelone.c			\
				ft_lstiter.c			\
				ft_lstlast.c			\
				ft_lstmap.c				\
				ft_lstnew.c				\
				ft_lstsize.c			\

