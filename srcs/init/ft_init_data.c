/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:59:31 by akadilkalim       #+#    #+#             */
/*   Updated: 2023/06/01 19:44:04 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_data.h"
#include <stdio.h>
#include <sys/signal.h>

int	g_signal = 0;

int		ft_init_env(t_list **data_env, char **env);

void	ft_init_data(int argc, char **argv, char **env, t_data *data)
{
	(void)argv;
	(void)argc;
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, &ft_signal);
	data->env = NULL;
	ft_init_env(&data->env, env);
	data->node = NULL;
	data->exit_code = 0;
}
