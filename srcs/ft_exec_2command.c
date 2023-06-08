/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_2command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akadilkalimoldayev <akadilkalimoldayev@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:18:14 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/08 18:19:58 by akadilkalim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_exec_command.h"
#include "libft.h"
#include <readline/readline.h>
#include <sys/signal.h>
#include <sys/wait.h>

void	ft_signal_fork(int num);

int	ft_exec_command(t_node *node, t_data *data)
{
	int	i_cmd;
	int	num;
	int	pid;
	int	result;

	num = 0;
	result = -1;
	i_cmd = 0;
	pid = 0;
	while (i_cmd < node->count_cmd)
	{
		result = ft_prepare_pipe(node, i_cmd);
		if (check(&(node->cmds[i_cmd]), node->count_cmd, result) && num++ >= 0)
			pid = ft_execute(&node->cmds[i_cmd], data, node);
		else if (result == 0 && node->count_cmd == 1)
			result = ft_execute_builtin(&node->cmds[i_cmd], data, node);
		i_cmd++;
	}
	ft_wait_child_processes(&result, num, pid);
	signal(SIGINT, &ft_signal);
	return (result);
}

int	check(t_cmd *cmd, int count, int result)
{
	char	*str;

	if (result == 0)
	{
		if (count != 1)
			return (1);
		if (!cmd->params)
			return (1);
		if (cmd->params && ft_is_builtin(cmd->params) != 1)
			return (1);
		else if (cmd->params && ft_is_builtin(cmd->params) == 1)
		{
			str = (char *)cmd->params->content;
			if (ft_strcmp(str, "cd") == 0 || ft_strcmp(str, "exit") == 0)
				return (0);
			else if (ft_strcmp(str, "export") == 0 || !ft_strcmp(str, "unset"))
				return (0);
			else
				return (1);
		}
	}
	return (0);
}

/*
    Add a moment when there can be only one command and it is builtin
*/
int	ft_execute(t_cmd *cmd, t_data *data, t_node *node)
{
	int	pid;
	int	exit_c;

	pid = fork();
	exit_c = 0;
	if (pid < -1)
		ft_error_exit(-1);
	if (pid == 0)
	{
		signal(SIGINT, &ft_signal_fork);
		signal(SIGQUIT, &ft_signal_fork);
		if (dup2(cmd->in_fd, STDIN_FILENO) == -1)
			ft_error_exit(-1);
		if (dup2(cmd->out_fd, STDOUT_FILENO) == -1)
			ft_error_exit(-1);
		ft_clean_fds(cmd);
		if (cmd->params && ft_is_builtin(cmd->params) == 1)
			exit_c = ft_execute_builtin(cmd, data, node);
		else if (cmd->params)
			exit_c = ft_execute_program(cmd, data->env, node);
		return (ft_clean_tree(node), ft_clean_env(data->env), exit(exit_c), 0);
	}
	else if (cmd->in_fd != 0)
		close(cmd->in_fd);
	return (signal(SIGINT, SIG_IGN), pid);
}

void	ft_wait_child_processes(int *is_success, int size, int pid)
{
	int	i;
	int	status;

	i = 0;
	while (i < size)
	{
		if (wait(&status) == pid)
		{
			if (WIFEXITED(status))
				*is_success = WEXITSTATUS(status);
			if (WIFSIGNALED(status))
			{
				*is_success = WTERMSIG(status) + 128;
				if (*is_success == 130)
					ft_merror("\n", NULL);
				if (*is_success == 131)
					ft_merror("Quit (core dumped)\n", NULL);
			}
		}
		i++;
	}
}
