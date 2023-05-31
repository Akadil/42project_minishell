/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:42:02 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/31 17:52:00 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_data.h"
#include <stdio.h>

void	ft_init_cmds(t_cmd *cmds, int num_cmds)
{
	int	i_cmd;

	i_cmd = 0;
	while (i_cmd < num_cmds)
	{
		cmds[i_cmd].params = NULL;
		cmds[i_cmd].redir = NULL;
		cmds[i_cmd].in_fd = 0;
		cmds[i_cmd].out_fd = 1;
		cmds[i_cmd].out_pipe_fd = -1;
		i_cmd++;
	}
}

int	ft_count_cmds(t_list *token)
{
	t_list	*i_token;
	int		count;

	count = 1;
	i_token = token;
	while (i_token)
	{
		if (i_token->type == PIPE)
			count++;
		i_token = i_token->next;
	}
	return (count);
}
