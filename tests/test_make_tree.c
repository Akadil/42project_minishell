/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_make_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:20:13 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/12 16:54:55 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include "linked_list.h"
#include "data.h"

/*
    tester:    
    cc -g -I includes -Wall -Wextra -Werror tests/test_make_tree.c srcs/parsing/ft_add_spaces.c srcs/parsing/ft_tokenization.c srcs/parsing/ft_assign_types.c srcs/parsing/ft_make_tree.c -lreadline -Llibft -lft && ./a.out&& rm a.out
*/

t_list    *ft_tokenization(char *str);
void    print_tokens(t_list *token);
char    *ft_add_spaces(char *str);
void    ft_assign_types(t_list *node);
t_node  *ft_make_tree(t_list *token, t_node *parent);
void    ft_print_tree(t_node *node);

int main(void)
{
    char    *str;
    t_list  *head;
    t_node  *node;

    head = NULL;
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
        
        printf("\n\n");
        str = readline("Type the string: ");
        
    }

    return (0);
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