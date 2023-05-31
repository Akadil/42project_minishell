/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:21:53 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/31 19:04:57 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "struct_data.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdlib.h>
#include <sys/signal.h>

void	ft_signal_handler2(int signal)
{
	if (signal == SIGQUIT)
		exit(131);
	if (signal == SIGINT)
		exit(130);
}

void	ft_signal_handler(int signal)
{
	if (signal == SIGINT)
	{
		ft_printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}
