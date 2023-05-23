NAME			= minishell
LIBFT			= libft.a

SRCS_ADD_SPACES		=	parsing/ft_add_spaces.c \
						parsing/utils/ft_add_spaces_utils.c
SRCS_TOKENIZATION	=	parsing/ft_tokenization.c \
						parsing/tokenization/ft_add_token.c \
						parsing/tokenization/ft_is_token.c \
						parsing/tokenization/ft_tokenization_utils.c
SRCS_EXPANSION		=	execution/expansion/ft_expand_string.c \
						execution/expansion/ft_expand_token.c \
						execution/expansion/utils/ft_expand_string_utils.c \
						execution/expansion/utils/ft_expand_string_utils_2.c \
						execution/expansion/utils/ft_expand_token_utils.c \
						execution/expansion/utils/ft_expand_token_utils_2.c \
						execution/expansion/utils/ft_expand_token_utils_3.c
SRCS_ASSIGN_TYPES	=	parsing/ft_check_tokens.c \
						parsing/ft_assign_types.c
SRCS_MAKE_TREE		=	parsing/ft_make_tree.c

SRCS_PARSING		=	ft_parsing.c $(SRCS_ADD_SPACES) $(SRCS_TOKENIZATION) $(SRCS_EXPANSION) $(SRCS_ASSIGN_TYPES) $(SRCS_MAKE_TREE)
SRCS_UTILS			=	utils/ft_clean.c \
						utils/ft_error_1.c \
						utils/ft_error_2.c
SRCS_INIT			=	init/ft_init_data.c \
						init/ft_init_envvar.c 

SRCS				=	main.c $(SRCS_PARSING) $(SRCS_UTILS) $(SRCS_INIT)

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
			${CC} $(OBJS) -o $(NAME) -lreadline -Llibft -lft

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
			$(CC) $(HFLAGS) $(CFLAGS) tests/test_add_spaces.c $(addprefix $(SRCS_DIR)/, $(SRCS_ADD_SPACES) $(SRCS_UTILS)) -lreadline -Llibft -lft
			./a.out
			rm a.out

test_tokenization		:
			$(CC) $(HFLAGS) $(CFLAGS) tests/test_tokenization.c $(addprefix $(SRCS_DIR)/, $(SRCS_ADD_SPACES) $(SRCS_EXPANSION) $(SRCS_TOKENIZATION) $(SRCS_UTILS)) -lreadline -Llibft -lft
			./a.out
			rm a.out

test_assign_types		:
			$(CC) $(HFLAGS) $(CFLAGS) tests/test_assgn_types.c $(addprefix $(SRCS_DIR)/, $(SRCS_ADD_SPACES) $(SRCS_EXPANSION) $(SRCS_TOKENIZATION) $(SRCS_ASSIGN_TYPES) $(SRCS_UTILS)) -lreadline -Llibft -lft
			valgrind ./a.out
			rm a.out

test_make_tree			:
			$(CC) $(HFLAGS) $(CFLAGS) tests/test_make_tree.c $(addprefix $(SRCS_DIR)/, $(SRCS_ADD_SPACES) $(SRCS_EXPANSION) $(SRCS_TOKENIZATION) $(SRCS_ASSIGN_TYPES) $(SRCS_MAKE_TREE) $(SRCS_UTILS)) -lreadline -Llibft -lft
			valgrind --leak-check=full ./a.out
			rm a.out

test_preprocessing		:
			$(CC) $(HFLAGS) $(CFLAGS) tests/test_preprocessing.c $(addprefix $(SRCS_DIR)/, $(SRCS_ADD_SPACES) $(SRCS_EXPANSION) $(SRCS_TOKENIZATION) $(SRCS_ASSIGN_TYPES) $(SRCS_MAKE_TREE) $(SRCS_UTILS)) srcs/execution/ft_preprocess_node.c srcs/execution/ft_preprocess_tree.c -lreadline -Llibft -lft
			./a.out
			rm a.out

test_exec_recursion		:
			$(CC) $(HFLAGS) $(CFLAGS) tests/test_exec_recursion.c $(addprefix $(SRCS_DIR)/, $(SRCS_ADD_SPACES) $(SRCS_EXPANSION) $(SRCS_TOKENIZATION) $(SRCS_ASSIGN_TYPES) $(SRCS_MAKE_TREE) $(SRCS_UTILS)) srcs/execution/ft_preprocess_node.c srcs/execution/ft_preprocess_tree.c srcs/ft_execution.c -lreadline -Llibft -lft
			./a.out
			rm a.out

debug_add_spaces		:
			$(CC) -g $(HFLAGS) $(CFLAGS) tests/test_add_spaces.c $(CC) $(HFLAGS) $(CFLAGS) tests/test_add_spaces.c $(addprefix $(SRCS_DIR)/, $(SRCS_ADD_SPACES) $(SRCS_UTILS)) -lreadline -Llibft -lft

debug_assign_types		:
			$(CC) -g3 $(HFLAGS) $(CFLAGS) tests/test_assgn_types.c $(addprefix $(SRCS_DIR)/, $(SRCS_ADD_SPACES) $(SRCS_EXPANSION) $(SRCS_TOKENIZATION) $(SRCS_ASSIGN_TYPES) $(SRCS_UTILS)) -lreadline -Llibft -lft

debug_make_tree			:
			$(CC) -g $(HFLAGS) $(CFLAGS) tests/test_make_tree.c srcs/parsing/ft_add_spaces.c srcs/parsing/utils/ft_add_spaces_utils.c srcs/parsing/ft_tokenization.c srcs/parsing/tokenization/ft_add_token.c srcs/parsing/tokenization/ft_is_token.c srcs/parsing/tokenization/ft_tokenization_utils.c srcs/utils/ft_clean.c srcs/utils/ft_error_1.c srcs/utils/ft_error_2.c srcs/parsing/ft_assign_types.c srcs/parsing/ft_make_tree.c -lreadline -Llibft -lft

debug_preprocessing		:
			$(CC) -g $(HFLAGS) $(CFLAGS) tests/test_preprocessing.c srcs/parsing/ft_add_spaces.c srcs/parsing/utils/ft_add_spaces_utils.c srcs/parsing/ft_tokenization.c srcs/parsing/tokenization/ft_add_token.c srcs/parsing/tokenization/ft_is_token.c srcs/parsing/tokenization/ft_tokenization_utils.c srcs/utils/ft_clean.c srcs/utils/ft_error_1.c srcs/utils/ft_error_2.c srcs/parsing/ft_assign_types.c srcs/parsing/ft_make_tree.c srcs/execution/ft_preprocess_node.c srcs/execution/ft_preprocess_tree.c -lreadline -Llibft -lft

debug_exec_recursion	:
			$(CC) -g $(HFLAGS) $(CFLAGS) tests/test_exec_recursion.c srcs/parsing/ft_add_spaces.c srcs/parsing/utils/ft_add_spaces_utils.c srcs/parsing/ft_tokenization.c srcs/parsing/tokenization/ft_add_token.c srcs/parsing/tokenization/ft_is_token.c srcs/parsing/tokenization/ft_tokenization_utils.c srcs/utils/ft_clean.c srcs/utils/ft_error_1.c srcs/utils/ft_error_2.c srcs/parsing/ft_assign_types.c srcs/parsing/ft_make_tree.c srcs/parsing/ft_check_tokens.c srcs/execution/ft_preprocess_node.c srcs/execution/ft_preprocess_tree.c srcs/ft_execution.c -lreadline -Llibft -lft


re						: fclean all

.PHONY					: all clean fclean re