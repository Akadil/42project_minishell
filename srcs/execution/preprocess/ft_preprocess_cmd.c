/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:36:28 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/31 17:57:15 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_preprocess_cmd.h"

void	ft_preprocess_cmd(t_cmd *cmds, t_list *token)
{
	t_list	*temp;
	int		i_cmd;

	i_cmd = 0;
	while (token)
	{
		if (token->type == PARAMETER)
			token = ft_preprocess_parameter(token, cmds, i_cmd);
		else if (6 <= token->type && token->type <= 9)
			token = ft_preprocess_redirection(token, cmds, i_cmd);
		else
		{
			i_cmd++;
			temp = token->next;
			ft_lstdelone(token, &free);
			token = temp;
			token->prev = NULL;
		}
	}
}
