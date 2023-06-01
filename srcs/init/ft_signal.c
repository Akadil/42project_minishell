/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:21:53 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/01 15:07:20 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "struct_data.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdlib.h>
#include <sys/signal.h>

void	ft_signal_main(int signal)
{
	if (signal == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void    ft_signal_heredoc(int signal)
{
	if (signal == SIGINT)
	{
		write(1, "\n", 1);
        rl_replace_line("", 0);
        rl_redisplay();
        close (STDIN_FILENO);
        my_signal = 1;
	}
}

void	ft_signal_fork(int num)
{
	if (num == SIGINT)
		exit(130);
	if (num == SIGQUIT)
		exit(131);
}
