/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:31:49 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/31 23:28:29 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/main.h"
#include <sys/signal.h>
#include <unistd.h>

void	ft_signal_handler4(int sig)
{
	if (sig == SIGINT)
	{
		my_signal = 1;
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_redisplay();
		write(1, "$", 1);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;
	char	*command;
	int		exit_code;

	command = NULL;
	ft_init_data(argc, argv, env, &data);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, &ft_signal_handler4);
	while (1)
	{
		command = readline("$");
		if (!command || my_signal == 2)
			break ;
		add_history(command);
		exit_code = ft_parsing(command, data.env, &data);
		if (exit_code == 0)
		{
			ft_execution(&data, data.node);
			ft_clean_tree(data.node);
		}
	}
	ft_clean_env(data.env);
	return (data.exit_code);
}
