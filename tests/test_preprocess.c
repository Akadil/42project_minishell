/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_preprocess.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:50:13 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/25 15:31:50 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include "struct_list.h"
#include "libft.h"
#include "struct_data.h"
#include <string.h>

/*
    tester:    
    cc -g -I includes -Wall -Wextra -Werror tests/test_preprocessing.c srcs/parsing/ft_add_spaces.c srcs/parsing/utils/ft_add_spaces_utils.c srcs/parsing/ft_tokenization.c srcs/parsing/tokenization/ft_add_token.c srcs/parsing/tokenization/ft_is_token.c srcs/parsing/tokenization/ft_tokenization_utils.c srcs/utils/ft_clean.c srcs/utils/ft_error_1.c srcs/utils/ft_error_2.c srcs/parsing/ft_assign_types.c srcs/parsing/ft_make_tree.c srcs/execution/ft_preprocess_node.c srcs/execution/ft_preprocess_tree.c -lreadline -Llibft -lft && ./a.out&& rm a.out

*/

int max_level = 0;

void    print_tokens(t_list *token);
void    ft_set_the_level(t_node *node, int level);
void    ft_print_tree(t_node *node);
void    ft_print_tree_levels(t_node *node, int level);

int	ft_init_env(t_list **data_env, char **env);
t_node	*ft_parsing(char *command, t_list *env);
int    ft_preprocess(t_node *node);


int main(int argc, char **argv, char **env_p)
{
    (void)argc;
    (void)argv;
    char    *str;
    t_list  *env;
    t_node  *node;

    env = NULL;
    node = NULL;
    ft_init_env(&env, env_p);
    str = readline("Type the string: ");
    while (str)
    {
        printf("-----------------------------\n\n");
        node = ft_parsing(str, env);
        ft_print_tree(node);
        ft_preprocess(node);

        ft_set_the_level(node, 0);
        printf("\n-----------------\n");
        printf("e - elements, p - parameters, r - redirection\n\n");
        int i = 0;
        while (i < max_level + 1)
        {
            ft_print_tree_levels(node, i);
            printf("\n");
            i++;
        }
        printf("\n\n");
        max_level = 0;
        str = readline("Type the string: ");   
    }
    return (0);
}

void    ft_set_the_level(t_node *node, int level)
{
    if (max_level < level)
        max_level = level;
    if (!node->left)
    {
        node->level = level;
        return ;  
    }
    ft_set_the_level(node->left, level + 1);
    node->level = level;
    ft_set_the_level(node->right, level + 1);
}

void    ft_print_tree_levels(t_node *node, int level)
{
    t_list  *token;
    int i;

    if (!node->left)
    {
        i = 0;
        while (i < node->count_cmd)
        {
            token = node->cmds[i].params;
            while (token)
            {
                if (node->level == level)
                    printf("p:%s", (char *)token->content);
                else
                    printf("  %s", (char *)ft_memset(ft_strdup(token->content), ' ', strlen((char *)token->content)));
                if (token->next)
                    printf(" ");
                token = token->next;
            }
            if (node->level == level)
                printf(" [");
            else
                printf("  ");
            token = node->cmds[i].redir;
            while (token)
            {
                if (node->level == level)
                {
                    if (token->type == 8)
                        printf("r:%d->%d", *((int *)token->content), token->type);
                    else
                        printf("r:%s->%d", (char *)token->content, token->type);
                }
                else
                    printf("  %s   ", (char *)ft_memset(ft_strdup(token->content), ' ', strlen((char *)token->content)));
                if (token->next)
                    printf(" ");
                token = token->next;
            }
            if (node->level == level)
            {
                printf("]");
                if (i + 1 < node->count_cmd)
                    printf(" | ");
            }
            else
            {
                printf(" ");
                if (i + 1 < node->count_cmd)
                    printf("   ");
            }
            i++;
        }

        if (node->level == level)
            printf(" %d", node->is_micro);
        else
            printf("  ");
        return ;  
    }

    ft_print_tree_levels(node->left, level);

    token = node->elems;
    while (token)
    {
        if (node->level == level)
            printf(" e:%s ", (char *)token->content);
        else
            printf("   %s ", (char *)ft_memset(ft_strdup(token->content), ' ', strlen((char *)token->content)));
        token = token->next;
    }
    if (node->level == level)
        printf(" %d", node->is_micro);
    else
        printf("  ");

    ft_print_tree_levels(node->right, level);
}

void    ft_print_tree(t_node *node)
{
    t_list  *token;

    if (!node->left)
    {
        token = node->elems;
        while (token)
        {
            printf("%s", (char *)token->content);
            if (token->next)
                printf(" ");
            token = token->next;
        }
        return ;  
    }
    
    printf("{ ");
    ft_print_tree(node->left);
    printf(" }");

    token = node->elems;
    while (token)
    {
        printf(" %s ", (char *)token->content);
        token = token->next;
    }

    printf("{ ");
    ft_print_tree(node->right);
    printf(" }");
}
