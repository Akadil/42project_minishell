/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:04:54 by akadilkalim       #+#    #+#             */
/*   Updated: 2023/05/15 17:52:47 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void    ft_line_execution(t_data *data)
{
    // As a first step, I have to open every heredoc

    ft_open_heredocs(data);
    

}

/*
    Additional comments:
            1. The expansion have to be before choosing the builtin or natural
*/

int    fd_exec_recursion(t_node *node)
{
    int exit_status;

    exit_status = ft_exec_recursion(node->left);
    if (exit_status == 0)
        return (0);

    return (1);
}   