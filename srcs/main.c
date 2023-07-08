/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:31:49 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/01 20:15:04 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/main.h"
#include <sys/signal.h>
#include <unistd.h>

int	main(int argc, char **argv, char **env)
{
	t_data	data;
	char	*command;
	int		exit_code;

	command = NULL;
	ft_init_data(argc, argv, env, &data);
	while (1)
	{
		command = readline("$");
		if (!command)
			break ;
		add_history(command);
		exit_code = ft_parsing(command, data.env, &data);
		if (exit_code == 0)
		{
			ft_execution(&data);
			ft_clean_tree(data.node);
		}
	}
	ft_clean_env(data.env);
	return (data.exit_code);
}
