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

test_tokenization		:
			cc -I includes -Wall -Wextra -Werror tests/test_tokenization.c srcs/parsing/ft_add_spaces.c srcs/parsing/utils/ft_add_spaces_utils.c srcs/parsing/ft_tokenization.c srcs/parsing/tokenization/ft_add_token.c srcs/parsing/tokenization/ft_is_token.c srcs/parsing/tokenization/ft_tokenization_utils.c srcs/utils/ft_clean.c srcs/utils/ft_error_1.c srcs/utils/ft_error_2.c -lreadline -Llibft -lft && ./a.out && rm a.out

test_assign_types		:
			cc -I includes -Wall -Wextra -Werror tests/test_assgn_types.c srcs/parsing/ft_add_spaces.c srcs/parsing/utils/ft_add_spaces_utils.c srcs/parsing/ft_tokenization.c srcs/parsing/tokenization/ft_add_token.c srcs/parsing/tokenization/ft_is_token.c srcs/parsing/tokenization/ft_tokenization_utils.c srcs/utils/ft_clean.c srcs/utils/ft_error_1.c srcs/utils/ft_error_2.c srcs/parsing/ft_assign_types.c -lreadline -Llibft -lft
			valgrind ./a.out
			rm a.out

test_make_tree			:
			cc -I includes -Wall -Wextra -Werror tests/test_make_tree.c srcs/parsing/ft_add_spaces.c srcs/parsing/utils/ft_add_spaces_utils.c srcs/parsing/ft_tokenization.c srcs/parsing/tokenization/ft_add_token.c srcs/parsing/tokenization/ft_is_token.c srcs/parsing/tokenization/ft_tokenization_utils.c srcs/utils/ft_clean.c srcs/utils/ft_error_1.c srcs/utils/ft_error_2.c srcs/parsing/ft_assign_types.c srcs/parsing/ft_make_tree.c -lreadline -Llibft -lft
			valgrind --leak-check=full ./a.out
			rm a.out

test_exec_recursion		:
			cc -I includes -Wall -Wextra -Werror tests/test_exec_recursion.c srcs/parsing/ft_add_spaces.c srcs/parsing/utils/ft_add_spaces_utils.c srcs/parsing/ft_tokenization.c srcs/parsing/tokenization/ft_add_token.c srcs/parsing/tokenization/ft_is_token.c srcs/parsing/tokenization/ft_tokenization_utils.c srcs/utils/ft_clean.c srcs/utils/ft_error_1.c srcs/utils/ft_error_2.c srcs/parsing/ft_assign_types.c srcs/parsing/ft_make_tree.c srcs/parsing/ft_check_tokens.c srcs/ft_execution.c -lreadline -Llibft -lft && ./a.out && rm a.out

debug_add_spaces		:
			cc -g -I includes -Wall -Wextra -Werror tests/test_add_spaces.c srcs/parsing/ft_add_spaces.c srcs/parsing/utils/ft_add_spaces_utils.c  -lreadline -Llibft -lft

debug_make_tree			:
			cc -g -I includes -Wall -Wextra -Werror tests/test_make_tree.c srcs/parsing/ft_add_spaces.c srcs/parsing/utils/ft_add_spaces_utils.c srcs/parsing/ft_tokenization.c srcs/parsing/tokenization/ft_add_token.c srcs/parsing/tokenization/ft_is_token.c srcs/parsing/tokenization/ft_tokenization_utils.c srcs/utils/ft_clean.c srcs/utils/ft_error_1.c srcs/utils/ft_error_2.c srcs/parsing/ft_assign_types.c srcs/parsing/ft_make_tree.c -lreadline -Llibft -lft

debug_exec_recursion	:
			cc -g -I includes -Wall -Wextra -Werror tests/test_exec_recursion.c srcs/parsing/ft_add_spaces.c srcs/parsing/utils/ft_add_spaces_utils.c srcs/parsing/ft_tokenization.c srcs/parsing/tokenization/ft_add_token.c srcs/parsing/tokenization/ft_is_token.c srcs/parsing/tokenization/ft_tokenization_utils.c srcs/utils/ft_clean.c srcs/utils/ft_error_1.c srcs/utils/ft_error_2.c srcs/parsing/ft_assign_types.c srcs/parsing/ft_make_tree.c srcs/parsing/ft_check_tokens.c srcs/ft_execution.c -lreadline -Llibft -lft



re						: fclean all

.PHONY					: all clean fclean re