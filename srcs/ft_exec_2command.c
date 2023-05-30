/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_2command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:18:14 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/30 16:48:16 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_exec_command.h"
#include <sys/wait.h>
#include "libft.h"

int    ft_exec_command(t_node *node, t_list **env)
{
    int i_cmd;
    int count;
    int pid;
    int result;

    count = 0;
    result = -1;
    i_cmd = 0;
    pid = 0;
    while (i_cmd < node->count_cmd)
    {
        result = ft_prepare_pipe(node, i_cmd);
        if (check(&node->cmds[i_cmd], node->count_cmd, result) && count++ >= 0)
            pid = ft_execute(&node->cmds[i_cmd], env, node);
        else if (result == 0 && node->count_cmd == 1)
            result = ft_execute_builtin(&node->cmds[i_cmd], env, node);
        i_cmd++;
    }
    ft_wait_child_processes(&result, count, pid);
    return (result);
}

int check(t_cmd *cmd, int count, int result)
{
    if (result == 0)
    {
        if (count != 1)
            return (1);
        if (cmd->params && ft_is_builtin(cmd->params) != 1)
            return (1);
    }
    return (0);
}

/*
    Add a moment when there can be only one command and it is builtin
*/
int ft_execute(t_cmd *cmd, t_list **env, t_node *node)
{
    int pid;
    int exit_code;

    pid = fork();
    exit_code = 0;
    if (pid < -1)
        ft_error_exit(-1);
    if (pid == 0)
    {
        if (dup2(cmd->in_fd, STDIN_FILENO) == -1)
			ft_error_exit(-1);
		if (dup2(cmd->out_fd, STDOUT_FILENO) == -1)
            ft_error_exit(-1);
        ft_clean_fds(cmd);
        if (cmd->params && ft_is_builtin(cmd->params) == 1)
            exit_code = ft_execute_builtin(cmd, env, node);
        else if (cmd->params)
            exit_code = ft_execute_program(cmd, *env, node);
        ft_clean_tree(node);
        ft_clean_env(*env);
        exit(exit_code);
    }
    else if (cmd->in_fd != 0)
        close(cmd->in_fd);
    return (pid);
}

void    ft_wait_child_processes(int *is_success, int size, int pid)
{
    int i;
    int status;

    i = 0;
    while (i < size)
    {
        if (wait(&status) == pid)
            *is_success = status;
        i++;
    }
    if (*is_success != 0)
        *is_success = -1;
}
