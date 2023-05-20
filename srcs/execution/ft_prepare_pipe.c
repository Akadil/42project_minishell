/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_pipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:54:24 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/20 21:06:12 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "struct_data.h"
#include "struct_list.h"
#include "ft_error.h"

int ft_prepare_pipe(t_node *node, int i_cmd)
{
    t_list  *token;
    int     fd[2];

    if (i_cmd < node->count_cmd - 1)
    {
        if (pipe(fd) == -1)
        {
            ft_error();
            return (-1);
        }
        node->cmds[i_cmd].out_fd = fd[1];
        node->cmds[i_cmd + 1].in_fd = fd[0];
    }
    token = node->cmds[i_cmd].redir;
    while (token)
    {
        if (token->type == REDIRECT_IN)
        {
            if (node->cmds[i_cmd].in_fd != 0)
                close (node->cmds[i_cmd].in_fd);
            node->cmds[i_cmd].in_fd = open((char *)token->content, O_RDONLY);
            if (node->cmds[i_cmd].in_fd == -1)
            {
                ft_perror((char *)token->content);
                return (-1);
            }
        }
        else if (token->type == REDIRECT_OUT)
        {
            if (node->cmds[i_cmd].out_fd != 1)
                close (node->cmds[i_cmd].out_fd);
            node->cmds[i_cmd].in_fd = open((char *)token->content, O_WRONLY | O_CREAT | O_APPEND);
            if (node->cmds[i_cmd].in_fd == -1)
            {
                ft_perror((char *)token->content);
                return (-1);
            }
        }
        else if (token->type == REDIRECT_OUT)
        {
            if (node->cmds[i_cmd].out_fd != 1)
                close (node->cmds[i_cmd].out_fd);
            node->cmds[i_cmd].in_fd = open((char *)token->content, O_WRONLY | O_CREAT | O_TRUNC);
            if (node->cmds[i_cmd].in_fd == -1)
            {
                ft_perror((char *)token->content);
                return (-1);
            }
        }
        else
        {
            if (node->cmds[i_cmd].out_fd != 1)
                close (node->cmds[i_cmd].out_fd);
            node->cmds[i_cmd].in_fd = ft_atoi((char *)token->content);
        }
        token = token->next;
    }
}