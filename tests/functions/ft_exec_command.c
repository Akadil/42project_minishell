/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:14:44 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/27 18:14:58 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_data.h"
#include "struct_list.h"

int ft_exec_command(t_data *data, t_node *node)
{
    (void)data;
    t_list  *token;
    int     exit;
    
    token = node->elems;
    while (token)
    {
        printf("%s ", (char *)token->content);
        token = token->next;
    }
    token = node->cmds->params;
    if (ft_strcmp((char *)token->content, "x") == 0)
        exit = 1;
    else
        exit = 0;
    while (token)
    {
        printf("%s ", (char *)token->content);
        token = token->next;
    }
    token = node->cmds->redir;
    while (token)
    {
        printf("%s ", (char *)token->content);
        token = token->next;
    }

    printf("\n");
    return (exit);
}