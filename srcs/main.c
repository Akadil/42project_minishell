/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:31:49 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/08 19:32:59 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/main.h"
#include <sys/signal.h>
#include <unistd.h>

int	main(int argc, char **argv, char **env)
{
	t_data	data;
	char	*command;

	command = NULL;
	ft_init_data(argc, argv, env, &data);
	while (1)
	{
		command = readline("$");
		if (!command)
			break ;
		if (g_signal == 1)
		{
			g_signal = 0;
			data.exit_code = 130;
			continue;
		}
		add_history(command);
		data.exit_code = ft_parsing(command, data.env, &data);
		if (data.exit_code == 0)
			ft_execution(&data);
		ft_clean_tree(data.node);
	}
	ft_clean_env(data.env);
	return (data.exit_code);
}
