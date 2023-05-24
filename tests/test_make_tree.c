/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_make_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:20:13 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/24 04:48:51 by akalimol         ###   ########.fr       */
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
    cc -g -I includes -Wall -Wextra -Werror tests/test_make_tree.c srcs/parsing/ft_add_spaces.c srcs/parsing/ft_tokenization.c srcs/parsing/ft_assign_types.c srcs/parsing/ft_make_tree.c -lreadline -Llibft -lft && ./a.out&& rm a.out
*/

int max_level = 0;

t_list    *ft_tokenization(char *str, t_list *env);
void    print_tokens(t_list *token);
char    *ft_add_spaces(char *str);
void    ft_assign_types(t_list *node);
t_node  *ft_make_tree(t_list *token, t_node *parent);
void    ft_set_the_level(t_node *node, int level);
void    ft_print_tree(t_node *node);
void    ft_print_tree_levels(t_node *node, int level);

int main(void)
{
    char    *str;
    t_list  *head;
    t_node  *node;
    t_list  *env_var;
    
    env_var = ft_lstnew("HOME=/my_home", 0);
    ft_lstadd_back(&env_var, ft_lstnew("USER=akalimol", 0));
    ft_lstadd_back(&env_var, ft_lstnew("a=z", 0));
    ft_lstadd_back(&env_var, ft_lstnew("b= ", 0));
    ft_lstadd_back(&env_var, ft_lstnew("c= -la", 0));
    ft_lstadd_back(&env_var, ft_lstnew("d=-la ", 0));
    ft_lstadd_back(&env_var, ft_lstnew("e=main.c error.c", 0));

    head = NULL;
    node = NULL;
    str = readline("Type the string: ");
    while (str)
    {
        printf("-----------------------------\n");
        printf("\n");
        
        str = ft_add_spaces(str);

        head = ft_tokenization(str, env_var);
        ft_assign_types(head);

        node = ft_make_tree(head, NULL);

        ft_set_the_level(node, 0);
        
        ft_print_tree(node);
        printf("\n-----------------\n");

        int i = 0;
        while (i < max_level + 1)
        {
            ft_print_tree_levels(node, i);
            printf("\n");
            i++;
        }
        printf("\n\n");
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

    if (!node->left)
    {
        token = node->elems;
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
