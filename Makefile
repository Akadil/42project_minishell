NAME			= minishell
LIBFT			= libft.a

SRCS_ADD_SPACES		=	parsing/ft_add_spaces.c \
						parsing/utils/ft_add_spaces_utils.c \
						parsing/utils/ft_add_spaces_utils_2.c
SRCS_TOKENIZATION	=	parsing/ft_tokenization.c \
						parsing/tokenization/ft_add_token.c \
						parsing/tokenization/ft_is_token.c \
						parsing/tokenization/ft_tokenization_utils.c \
						parsing/tokenization/ft_remove_quotes.c
SRCS_EXPANSION		=	parsing/expansion/ft_expand_string.c \
						parsing/expansion/ft_expand_token.c \
						parsing/expansion/utils/ft_expand_string_utils.c \
						parsing/expansion/utils/ft_expand_string_utils_2.c \
						parsing/expansion/utils/ft_expand_token_utils.c \
						parsing/expansion/utils/ft_expand_token_utils_2.c \
						parsing/expansion/utils/ft_expand_token_utils_3.c
SRCS_ASSIGN_TYPES	=	parsing/ft_check_tokens.c \
						parsing/check_tokens/ft_check_tokens_utils.c \
						parsing/ft_assign_types.c
SRCS_HEREDOCS		=	parsing/ft_open_heredocs.c
SRCS_MAKE_TREE		=	parsing/ft_make_tree.c \
						parsing/make_tree/ft_make_tree_utils.c
SRCS_PARSING		=	ft_parsing.c $(SRCS_ADD_SPACES) $(SRCS_TOKENIZATION) $(SRCS_EXPANSION) $(SRCS_ASSIGN_TYPES) $(SRCS_HEREDOCS) $(SRCS_MAKE_TREE)

SRCS_UTILS			=	utils/ft_clean_1.c \
						utils/ft_clean_2.c \
						utils/ft_error_1.c \
						utils/ft_error_2.c
SRCS_INIT			=	init/ft_init_data.c \
						init/ft_init_envvar.c 

SRCS_PREPROCESS		=	execution/ft_preprocess.c \
						execution/preprocess/ft_preprocess_cmd.c \
						execution/preprocess/ft_preprocess_parameter.c \
						execution/preprocess/ft_preprocess_redirection.c \
						execution/preprocess/ft_preprocess_utils.c

SRCS_PREPARE_PIPE	=	execution/ft_prepare_pipe.c

SRCS_EXEC_PROGRAM	=	execution/ft_execute_program.c \
						execution/execute_program/ft_construct_command.c \
						execution/execute_program/ft_find_path.c \
						execution/execute_program/utils/ft_find_path_utils.c \
						execution/execute_program/utils/ft_split_alt2.c \
						execution/execute_program/utils/ft_exec_command_utils.c

SRCS_EXEC_BUILTIN	=	execution/ft_execute_builtin.c \
						execution/execute_builtin/ft_builtin_cd.c \
						execution/execute_builtin/ft_builtin_echo.c \
						execution/execute_builtin/ft_builtin_env.c \
						execution/execute_builtin/ft_builtin_exit.c \
						execution/execute_builtin/ft_builtin_export.c \
						execution/execute_builtin/utils/ft_builtin_export_utils.c \
						execution/execute_builtin/ft_builtin_pwd.c \
						execution/execute_builtin/ft_builtin_unset.c

SRCS_EXECUTION		=	ft_exec_1recursion.c utils/ft_exec_recursion_utils.c ft_exec_2command.c $(SRCS_PREPROCESS) $(SRCS_PREPARE_PIPE) $(SRCS_EXEC_PROGRAM) $(SRCS_EXEC_BUILTIN)

SRCS				=	main.c init/ft_signal.c $(SRCS_PARSING) $(SRCS_UTILS) $(SRCS_INIT) $(SRCS_EXECUTION)

SRCS_DIR		= ./srcs
BUILD_DIR       = ./.build
INCLUDES_DIR	= ./includes
LIBFT_DIR		= ./libft

OBJS			= $(addprefix $(BUILD_DIR)/, $(SRCS))
OBJS			:= $(OBJS:%.c=%.o)
SRCS			:= $(addprefix $(SRCS_DIR)/, $(SRCS))

CC				= cc
CFLAGS          = -Wall -Werror -Wextra
HFLAGS			= -I $(INCLUDES_DIR) -I /usr/local/opt/readline/include

all						: ${NAME}

valgrind				: ${NAME}
			valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all --suppressions=./ignore.txt ./minishell

${NAME}         		: ${OBJS}
			${CC} $(OBJS) -o $(NAME) -L /usr/local/opt/readline/lib -lreadline -Llibft -lft



${BUILD_DIR}/%.o		: $(SRCS_DIR)/%.c $(LIBFT_DIR)/$(LIBFT)
			${CC} -g3 $(HFLAGS) ${CFLAGS} -c $< -o $@ 

$(LIBFT_DIR)/$(LIBFT)	:
			make -C $(LIBFT_DIR)

clean					:
			make -C $(LIBFT_DIR) clean
			rm -rf ${OBJS}

fclean					: clean
			rm -rf ${NAME} $(LIBFT_DIR)/$(LIBFT)



test_add_spaces			:	debug_add_spaces			
			./a.out
			rm a.out

test_tokenization			:	debug_tokenization			
			./a.out
			rm a.out

test_assign_types			:	debug_assign_types			
			./a.out
			rm a.out

test_make_tree				:	debug_make_tree			
			./a.out
			rm a.out

test_preprocess				:	debug_preprocess		
			./a.out
			rm a.out

test_exec_recursion		:	debug_exec_recursion			
			./a.out
			rm a.out

test_execute			:	debug_execute
			./a.out
			rm a.out

test_exec_program			:	debug_exec_program
			./a.out
			rm a.out

debug_add_spaces			: 
			$(CC) -g3 $(HFLAGS) $(CFLAGS) tests/test_add_spaces.c $(addprefix $(SRCS_DIR)/, $(SRCS_ADD_SPACES) $(SRCS_UTILS)) -lreadline -Llibft -lft

debug_tokenization		:
			$(CC) -g3 $(HFLAGS) $(CFLAGS) tests/test_tokenization.c $(addprefix $(SRCS_DIR)/, $(SRCS_ADD_SPACES) $(SRCS_EXPANSION) $(SRCS_TOKENIZATION) $(SRCS_UTILS)) -lreadline -Llibft -lft

debug_assign_types		:
			$(CC) -g3 $(HFLAGS) $(CFLAGS) tests/test_assgn_types.c $(addprefix $(SRCS_DIR)/, $(SRCS_ADD_SPACES) $(SRCS_EXPANSION) $(SRCS_TOKENIZATION) $(SRCS_ASSIGN_TYPES) $(SRCS_UTILS)) -lreadline -Llibft -lft

debug_make_tree			:
			$(CC) -g3 $(HFLAGS) $(CFLAGS) tests/test_make_tree.c $(addprefix $(SRCS_DIR)/, $(SRCS_ADD_SPACES) $(SRCS_EXPANSION) $(SRCS_TOKENIZATION) $(SRCS_ASSIGN_TYPES) $(SRCS_MAKE_TREE) $(SRCS_UTILS)) -lreadline -Llibft -lft

debug_preprocess		:
			$(CC) -g3 $(HFLAGS) $(CFLAGS) tests/test_preprocess.c $(addprefix $(SRCS_DIR)/, $(SRCS_PARSING) $(SRCS_UTILS) $(SRCS_INIT) $(SRCS_PREPROCESS)) -lreadline -Llibft -lft

debug_exec_recursion		:
			$(CC) -g3 $(HFLAGS) $(CFLAGS) tests/test_exec_recursion.c $(addprefix $(SRCS_DIR)/, $(SRCS_ADD_SPACES) $(SRCS_EXPANSION) $(SRCS_TOKENIZATION) $(SRCS_ASSIGN_TYPES) $(SRCS_MAKE_TREE) $(SRCS_UTILS)) srcs/execution/ft_preprocess_node.c srcs/execution/ft_preprocess_tree.c srcs/ft_execution.c -lreadline -Llibft -lft	

debug_execute			:
			$(CC) -g3 $(HFLAGS) $(CFLAGS) tests/test_execute.c  $(addprefix $(SRCS_DIR)/, ft_exec_2command.c $(SRCS_UTILS) $(SRCS_EXEC_PROGRAM)) -lreadline -Llibft -lft

debug_exec_program			:
			$(CC) -g3 $(HFLAGS) $(CFLAGS) tests/test_exec_command.c  $(addprefix $(SRCS_DIR)/, ft_exec_2command.c $(SRCS_UTILS) $(SRCS_EXEC_PROGRAM) $(SRCS_PREPARE_PIPE)) -lreadline -Llibft -lft


re						: fclean all

.PHONY					: all clean fclean re