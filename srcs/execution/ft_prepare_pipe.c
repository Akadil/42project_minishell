/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_pipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:54:24 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/28 20:08:23 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prepare_pipe/includes/ft_prepare_pipe.h"

int ft_prepare_pipe(t_node *node, int i_cmd)
{
    int     fd[2];
    char    *err;

    if (i_cmd < node->count_cmd - 1)
    {
        if (pipe(fd) == -1)
        {
            ft_error();
            return (-1);
        }
        node->cmds[i_cmd].out_fd = fd[1];
        node->cmds[i_cmd].out_pipe_fd = fd[0];
        node->cmds[i_cmd + 1].in_fd = fd[0];
    }
    err = ft_open_all_files(node->cmds[i_cmd].redir, node->cmds + i_cmd);
    if (err)
    {
        ft_perror(err);
        return (-1);
    }
    return (0);
}
