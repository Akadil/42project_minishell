/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_preprocessing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:50:13 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/20 14:41:07 by akalimol         ###   ########.fr       */
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

t_list    *ft_tokenization(char *str);
void    print_tokens(t_list *token);
char    *ft_add_spaces(char *str);
void    ft_assign_types(t_list *node);
t_node  *ft_make_tree(t_list *token, t_node *parent);
void    ft_set_the_level(t_node *node, int level);
void    ft_print_tree(t_node *node);
void    ft_print_tree_levels(t_node *node, int level);
int    ft_preprocess_tree(t_node *node);

int main(void)
{
    char    *str;
    t_list  *head;
    t_node  *node;

    head = NULL;
    node = NULL;
    str = readline("Type the string: ");
    while (str)
    {
        printf("-----------------------------\n");
        printf("\n");
        
        str = ft_add_spaces(str);

        head = ft_tokenization(str);
        ft_assign_types(head);

        node = ft_make_tree(head, NULL);

        ft_print_tree(node);

        ft_preprocess_tree(node);

        ft_set_the_level(node, 0);
        
        printf("\n-----------------\n");

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
                    printf("%s", (char *)token->content);
                else
                    printf("%s", (char *)ft_memset(ft_strdup(token->content), ' ', strlen((char *)token->content)));
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
                    printf("%s->%d", (char *)token->content, token->type);
                else
                {
                    printf("%s", (char *)ft_memset(ft_strdup(token->content), ' ', strlen((char *)token->content)));
                    printf("   ");
                }
                if (token->next)
                    printf(" ");
                token = token->next;
            }
            if (node->level == level)
                printf("]");
            else
                printf("  ");
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
            printf(" %s ", (char *)token->content);
        else
            printf(" %s ", (char *)ft_memset(ft_strdup(token->content), ' ', strlen((char *)token->content)));
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
