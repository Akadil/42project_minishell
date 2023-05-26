/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:52:57 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/26 11:52:03 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_data.h"
#include <unistd.h>
#include "ft_clean.h"

int ft_execute(t_cmd *cmd, t_list **env);

void    ft_exec_command(t_data *data, t_node *node)
{
    int i_cmd;
    int is_success;

    i_cmd = 0;
    is_success = 0;
    while (i_cmd < node->count_cmd)
    {
        is_success = ft_prepare_pipe(node, i_cmd);
        if (is_success == 0)
            ft_execute(data, i_cmd);
        i_cmd++;
    }
}

int ft_execute(t_cmd *cmd, t_list **env)
{
    int pid;

    pid = fork();
    if (pid < -1)
        printf("Error!");   // Wow, that is tricky error handling
    if (pid == 0)
    {
        if (dup2(cmd->in_fd, STDIN_FILENO) == -1)
			printf("Error!");   // btw, this one can use exit, because it is new process. Just I have to clean everythin
		if (dup2(cmd->out_fd, STDOUT_FILENO) == -1)
			printf("Error!");
        ft_clean_fds(cmd);
        if (cmd->params && ft_is_builtin(cmd) == 1)
            ft_execute_builtin(cmd, env);
        else if (cmd->params && ft_is_builtin(cmd) != 1)
            ft_execute_program(cmd, env);
        exit(0);
    }
    else
        close(cmd->in_fd);
}
