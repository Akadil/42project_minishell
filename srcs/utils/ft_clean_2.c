/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:15:04 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/31 19:23:56 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_data.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_clean_fds(t_cmd *cmd)
{
	if (cmd->in_fd != -1 && cmd->in_fd != 0)
		close(cmd->in_fd);
	if (cmd->out_fd != -1 && cmd->out_fd != 1)
		close(cmd->out_fd);
	if (cmd->out_pipe_fd != -1)
		close(cmd->out_pipe_fd);
}

void	ft_clean_darray(char **trash)
{
	int	i;

	i = 0;
	while (trash[i])
	{
		free(trash[i]);
		i++;
	}
	free(trash);
}
