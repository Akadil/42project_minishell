/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_command_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:20:57 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/31 17:59:08 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "struct_list.h"

int	ft_is_builtin(t_list *token)
{
	if (ft_strcmp((char *)token->content, "cd") == 0)
		return (1);
	else if (ft_strcmp((char *)token->content, "pwd") == 0)
		return (1);
	else if (ft_strcmp((char *)token->content, "echo") == 0)
		return (1);
	else if (ft_strcmp((char *)token->content, "export") == 0)
		return (1);
	else if (ft_strcmp((char *)token->content, "unset") == 0)
		return (1);
	else if (ft_strcmp((char *)token->content, "env") == 0)
		return (1);
	else if (ft_strcmp((char *)token->content, "exit") == 0)
		return (1);
	return (0);
}
