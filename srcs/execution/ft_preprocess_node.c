/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:18:55 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/19 17:16:08 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_data.h"
#include "struct_list.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void    ft_preprocess_node(t_node *node)
{
    t_list  *token;
    int     count;

    count = 0;
    token = node->elems;
    while (token)
    {
        if (token->type == PIPE)
            count++;
        token = token->next;
    }
    node->cmds = (t_cmd *)ft_calloc(sizeof(t_cmd), count);
    if (!node->cmds)
        printf("Do something!!!\n");
    ft_preprocess_cmd(node->cmds, node->elems);
    node->elems = NULL;
}

void    ft_preprocess_cmd(t_cmd *cmds, t_list *token)
{
    t_list  *temp;
    int     i_cmd;

    i_cmd = 0;
    while (token)
    {
        if (token->type == PARAMETER)                           // Parameters
        {
            temp = token->next;
            token->next = NULL;
            token->prev = NULL;
            ft_lstadd_back(&cmds[i_cmd].params, token);         // This will give me unconditional jump
            token = temp;
        }
        else if (6 <= token->type && token->type <= 9)          // Redirections
        {
            free(token->content);
            token->content = token->next->content;
            temp = token->next->next;
            free (token->next);
            token->next = NULL;
            ft_lstadd_back(&cmds[i_cmd].redir, token);
            token = temp;
        }
        else                                                    // Pipes
        {
            i_cmd++;
            ft_lstdelone(token, &free);
            temp = token->next;
        }
        token = temp;
    }
}