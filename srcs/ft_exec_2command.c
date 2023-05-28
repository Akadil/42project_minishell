/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_2command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:18:14 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/28 18:32:34 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_exec_command.h"

// int    ft_exec_command(t_node *node, t_list **env)
// {
//     int i_cmd;
//     int is_success;

//     i_cmd = 0;
//     is_success = 0;
//     while (i_cmd < node->count_cmd)
//     {
//         is_success = ft_prepare_pipe(node, i_cmd);
//         if (is_success == 0)
//             ft_execute(&node->cmds[i_cmd], env, node);
//         i_cmd++;
//     }
//     return (0);
// }

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
        close(cmd->in_fd);
    return (0);
}