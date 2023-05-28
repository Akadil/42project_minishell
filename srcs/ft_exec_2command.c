/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_2command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:18:14 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/28 20:54:22 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_exec_command.h"
#include <sys/wait.h>

int    ft_exec_command(t_node *node, t_list **env)
{
    int i_cmd;
    int i_executed;
    int pid;
    int is_success;
    int status;

    i_executed = 0;
    is_success = -1;
    i_cmd = 0;
    status = 0;
    while (i_cmd < node->count_cmd)
    {
        is_success = ft_prepare_pipe(node, i_cmd);
        if (is_success == 0 && i_executed++ >= 0)
            pid = ft_execute(&node->cmds[i_cmd], env, node);
        i_cmd++;
    }
    i_cmd = 0;
    while (i_cmd < i_executed)
    {
        if (wait(&status) == pid)
            is_success = status;
        i_cmd++;
    }
    if (is_success != 0 && is_success != -1)
        return (-1);
    return (is_success);
}

/*
    Add a moment when there can be only one command and it is builtin
*/
int ft_execute(t_cmd *cmd, t_list **env, t_node *node)
{
    int pid;

    pid = fork();
    if (pid < -1)
        printf("Error!");   // Wow, that is tricky error handling
    if (pid == 0)
    {
        if (dup2(cmd->in_fd, STDIN_FILENO) == -1)
			ft_error_exit(-1);
		if (dup2(cmd->out_fd, STDOUT_FILENO) == -1)
            ft_error_exit(-1);
        ft_clean_fds(cmd);
        if (cmd->params && ft_is_builtin(cmd->params) == 1)
            printf("I was here!"); //ft_execute_builtin(cmd, env);
        else if (cmd->params && ft_is_builtin(cmd->params) != 1)
            ft_execute_program(cmd, *env, node);
        exit(0);
    }
    else
        if (cmd->in_fd != 0)
            close(cmd->in_fd);
    return (pid);
}