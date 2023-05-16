NAME			= minishell
LIBFT			= libft.a

SRCS            = main.c

SRCS_DIR		= ./srcs
BUILD_DIR       = ./.build
INCLUDES_DIR	= ./includes
LIBFT_DIR		= ./libft

OBJS			= $(addprefix $(BUILD_DIR)/, $(SRCS))
OBJS			:= $(OBJS:%.c=%.o)
SRCS			:= $(addprefix $(SRCS_DIR)/, $(SRCS))

CC				= cc
CFLAGS          = -Wall -Werror -Wextra
HFLAGS			= -I $(INCLUDES_DIR)

all						: ${NAME}

${NAME}         		: ${OBJS}
			${CC} -g $(OBJS) -o $(NAME) -Llibft -lft  

${BUILD_DIR}/%.o		: $(SRCS_DIR)/%.c $(LIBFT_DIR)/$(LIBFT)
			${CC} $(HFLAGS) ${CFLAGS} -c $< -o $@ 

$(LIBFT_DIR)/$(LIBFT)	:
			make -C $(LIBFT_DIR)


clean					:
			make -C $(LIBFT_DIR) clean
			rm -rf ${OBJS}

fclean					: clean
			rm -rf ${NAME} $(LIBFT_DIR)/$(LIBFT)

test_add_spaces			: 
			cc -I includes -Wall -Wextra -Werror tests/test_add_spaces.c srcs/parsing/ft_add_spaces.c srcs/parsing/utils/ft_add_spaces_utils.c  -lreadline -Llibft -lft && ./a.out && rm a.out

re						: fclean all

.PHONY					: all clean fclean re