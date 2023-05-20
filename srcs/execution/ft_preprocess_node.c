/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:18:55 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/20 20:04:16 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_data.h"
#include "struct_list.h"
#include "libft.h"
#include "ft_error.h"
#include <stdio.h>
#include <stdlib.h>

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
            token = ft_lstretrieve(&token, token);
            ft_lstadd_back(&cmds[i_cmd].params, token);         // This will give me unconditional jump
        }
        else if (6 <= token->type && token->type <= 9)          // Redirections
        {
            free(token->content);
            token->content = token->next->content;
            ft_lstremove(&token, token->next, NULL);
            temp = token->next;
            token = ft_lstretrieve(&token, token);
            ft_lstadd_back(&cmds[i_cmd].redir, token);
        }
        else                                                    // Pipes
        {
            i_cmd++;
            temp = token->next;
            ft_lstdelone(token, &free);
        }
        token = temp;
    }
}

void    ft_init_cmds(t_cmd *cmds, int num_cmds)
{
    int i_cmd;

    i_cmd = 0;
    while (i_cmd < num_cmds)
    {
        cmds[i_cmd].in_fd = 0;
        cmds[i_cmd].out_fd = 1;
        i_cmd++;
    }
}

int    ft_preprocess_node(t_node *node)
{
    t_list  *token;
    int     count;

    count = 1;
    token = node->elems;
    while (token)
    {
        if (token->type == PIPE)
            count++;
        token = token->next;
    }
    node->cmds = (t_cmd *)ft_calloc(sizeof(t_cmd), count);
    if (!node->cmds)
    {
        ft_error();
        return (-1); 
    }
    ft_init_cmds(node->cmds, count);
    node->count_cmd = count;
    ft_preprocess_cmd(node->cmds, node->elems);
    node->elems = NULL;
    return (1);
}
