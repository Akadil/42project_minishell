/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_expand_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:01:18 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/23 14:53:04 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include "struct_list.h"
#include "libft.h"

/*
    To check: 
    cc -g3 -I includes -Wall -Wextra -Werror tests/test_expand_token.c srcs/execution/expansion/ft_expand_string.c srcs/execution/expansion/utils/ft_expand_string_utils.c srcs/execution/expansion/utils/ft_expand_string_utils_2.c srcs/execution/expansion/ft_expand_token.c srcs/execution/expansion/utils/ft_expand_token_utils.c srcs/init/ft_init_envvar.c srcs/utils/ft_error_1.c srcs/utils/ft_error_2.c srcs/utils/ft_clean.c -lreadline -Llibft -lft

    Problem inputs:
            1. $USER$b"$HOME"$HOME      Solved 
            2. a$USER" "qwe             
*/

int	ft_init_env(t_list **data_env, char **env);
t_list  *ft_expand_token(char *str, t_list *env);
int	ft_init_env(t_list **data_env, char **env);

int main(int argc, char **argv, char **env)
{
    (void)argc;
    (void)argv;
    (void)env;

    t_list  *env_var;
    t_list  *token;
    char    *str;

    env_var = NULL;
    token = NULL;
    //ft_init_env(&env_var, env);
    
    env_var = ft_lstnew("HOME=/my_home", 0);
    ft_lstadd_back(&env_var, ft_lstnew("USER=akalimol", 0));
    ft_lstadd_back(&env_var, ft_lstnew("a=z", 0));
    ft_lstadd_back(&env_var, ft_lstnew("b= ", 0));
    ft_lstadd_back(&env_var, ft_lstnew("c= -la", 0));
    ft_lstadd_back(&env_var, ft_lstnew("d=-la ", 0));
    ft_lstadd_back(&env_var, ft_lstnew("e=main.c error.c", 0));

    str = readline("Prompt: ");
    while (str)
    {
        printf("\nBefore: %s\n", str);
        token = ft_expand_token(str, env_var);
        while (token)
        {
            printf("<%s>\n", (char *)token->content);
            token = token->next;
        }
        str = readline("Prompt: ");
    }
    return (0);
}