/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_all_files.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:27:12 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/28 19:42:22 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_open_all_files.h"

char    *ft_open_all_files(t_list *token, t_cmd *cmd)
{
    while (token)
    {
        if (token->type == REDIRECT_IN)
            cmd->in_fd = ft_open(token, cmd->in_fd);
        else if (token->type == REDIRECT_OUT)
            cmd->out_fd = ft_open(token, cmd->out_fd);
        else if (token->type == REDIRECT_OUT2)
            cmd->out_fd = ft_open(token, cmd->out_fd);
        else
            cmd->in_fd = ft_open(token, cmd->in_fd);
        if (cmd->in_fd == -1 || cmd->out_fd == -1)
            return ((char *)token->content);
        token = token->next;
    }
    return (NULL);
}

int ft_open(t_list *token, int fd)
{
    if (token->type == REDIRECT_IN)
    {
        if (fd != 0)
            close (fd);
        fd = open((char *)token->content, O_RDONLY);
    }
    else if (token->type == REDIRECT_OUT)
    {
        if (fd != 1)
            close (fd);
        fd = open((char *)token->content, O_WRONLY | O_CREAT | O_APPEND, 0666);
    }
    else if (token->type == REDIRECT_OUT)
    {
        if (fd != 1)
            close (fd);
        fd = open((char *)token->content, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    }
    else
    {
        if (fd != 1)
            close (fd);
        fd = *((int *)token->content);
    }
    return (fd);
}