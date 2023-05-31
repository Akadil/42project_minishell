/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_2command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:18:14 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/31 21:06:22 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_exec_command.h"
#include "libft.h"
#include <readline/readline.h>
#include <sys/signal.h>
#include <sys/wait.h>

int	ft_exec_command(t_node *node, t_data *data)
{
	int	i_cmd;
	int	count;
	int	pid;
	int	result;

	count = 0;
	result = -1;
	i_cmd = 0;
	pid = 0;
	while (i_cmd < node->count_cmd)
	{
		result = ft_prepare_pipe(node, i_cmd);
		if (check(&(node->cmds[i_cmd]), node->count_cmd, result) && count++ >= 0)
			pid = ft_execute(&node->cmds[i_cmd], data, node);
		else if (result == 0 && node->count_cmd == 1)
			result = ft_execute_builtin(&node->cmds[i_cmd], data, node);
		i_cmd++;
	}
	ft_wait_child_processes(&result, count, pid);
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

void	ft_signal_handler5(int num)
{
	if (num == SIGINT)
		exit(130);
	if (num == SIGQUIT)
		exit(131);
}

void	ft_signal_handler6(int num)
{
	if (num == SIGINT)
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

/*
    Add a moment when there can be only one command and it is builtin
*/
int	ft_execute(t_cmd *cmd, t_data *data, t_node *node)
{
	int	pid;
	int	exit_code;

	signal(SIGINT, &ft_signal_handler6);
	pid = fork();
	exit_code = 0;
	if (pid < -1)
		ft_error_exit(-1);
	if (pid == 0)
	{
		signal(SIGINT, &ft_signal_handler5);
		signal(SIGQUIT, &ft_signal_handler5);
		if (dup2(cmd->in_fd, STDIN_FILENO) == -1)
			ft_error_exit(-1);
		if (dup2(cmd->out_fd, STDOUT_FILENO) == -1)
			ft_error_exit(-1);
		ft_clean_fds(cmd);
		if (cmd->params && ft_is_builtin(cmd->params) == 1)
			exit_code = ft_execute_builtin(cmd, data, node);
		else if (cmd->params)
			exit_code = ft_execute_program(cmd, data->env, node);
		ft_clean_tree(node);
		ft_clean_env(data->env);
		exit(exit_code);
	}
	else if (cmd->in_fd != 0)
		close(cmd->in_fd);
	return (pid);
}


void	ft_wait_child_processes(int *is_success, int size, int pid)
{
	int	i;
	int	status;

	i = 0;
	while (i < size)
	{
		if (wait(&status) == pid)
			*is_success = WEXITSTATUS(status);
		i++;
	}
}
