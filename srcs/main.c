/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:31:49 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/29 01:19:36 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/main.h"

int	main(int argc, char **argv, char **env)
{
	t_data	data;
	t_node	*cmd;
	char	*command;

	command = NULL;
	ft_init_data(argc, argv, env, &data);
	while (1)
	{
		command = readline("$");
		if (!command)
			break ;
		add_history(command);
		cmd = ft_parsing(command, data.env);
		if (cmd)
		{
			ft_execution(&data, cmd);
			ft_clean_tree(cmd);
		}
	}
	ft_clean_env(data.env);
	return (0);
}