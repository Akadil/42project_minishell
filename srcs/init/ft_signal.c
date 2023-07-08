/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akadilkalimoldayev <akadilkalimoldayev@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:21:53 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/08 18:41:15 by akadilkalim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "struct_data.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdlib.h>
#include <sys/signal.h>

void	ft_signal(int signal)
{
	if (signal == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_signal = 1;
	}
}

void	ft_signal_heredoc(int signal)
{
	if (signal == SIGINT)
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_redisplay();
		close(STDIN_FILENO);
		g_signal = 1;
	}
}

void	ft_signal_fork(int num)
{
	if (num == SIGINT)
		exit(130);
	if (num == SIGQUIT)
		exit(131);
}
