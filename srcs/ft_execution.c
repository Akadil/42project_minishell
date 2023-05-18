/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:04:54 by akadilkalim       #+#    #+#             */
/*   Updated: 2023/05/18 17:30:40 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_data.h"
#include "libft.h"
#include <stdio.h>

// void    ft_line_execution(t_data *data)
// {
//     // As a first step, I have to open every heredoc

//     // ft_open_heredocs(data);
    

// }

int ft_exec_cmd(t_node *node)
{
    t_list  *token;
    int     exit;

    token = node->elems;
    if (ft_strcmp((char *)token->content, "x") == 0)
        exit = 1;
    else
        exit = 0;
    while (token)
    {
        printf("%s ", (char *)token->content);
        token = token->next;
    }
    // token = node->redirections;
    // while (token)
    // {
    //     printf("%s ", (char *)token->content);
    //     token = token->next;
    // }
    printf("\n");
    return (exit);
}

int ft_check_operator(int exit_code, char *str)
{
    if (ft_strcmp(str, "&&") == 0)
    {
        if (exit_code == 0)
            return (0);
        return (1);
    }
    if (exit_code == 0)
        return (1);
    return (0);
}

// Some conditional jjump here
int    ft_exec_recursion(t_node *node, t_node *parent)
{
    if (node->type == 1)
    {
        if (!parent)
            node->exit_code = ft_exec_recursion(node->left, NULL);
        else
        {
            node->exit_code = 0;
            if (ft_check_operator(parent->exit_code, parent->elems->content) == 0)
                node->exit_code = ft_exec_recursion(node->left, NULL);
        }
        if (node->right->is_micro == node->is_micro && node->right->type == 1)
            node->exit_code = ft_exec_recursion(node->right, node);
        else
            if (ft_check_operator(node->exit_code, node->elems->content) == 0)
                node->exit_code = ft_exec_recursion(node->right, node);
    }
    else
        return (ft_exec_cmd(node));
    return (node->exit_code);
}
