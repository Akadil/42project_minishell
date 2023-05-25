/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 21:41:16 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/25 18:02:50 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_data.h"
#include <unistd.h>
#include "ft_clean.h"

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
        if (ft_is_builtin(cmd) == 1)
            ft_execute_builtin(cmd, env);
        else
            ft_execute_program(cmd, env);
    }
    else
        close(cmd->in_fd);
}