/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_1recursion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:04:54 by akadilkalim       #+#    #+#             */
/*   Updated: 2023/06/01 20:15:31 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_exec_recursion.h"

void	ft_execution(t_data *data)
{
	if (ft_preprocess(data->node) == -1)
	{
		ft_clean_tree(data->node);
		return ;
	}
	data->exit_code = ft_exec_recursion(data->node, data, NULL);
}

int	ft_exec_recursion(t_node *node, t_data *data, t_node *parent)
{
	if (node->type == 1)
	{
		if (!parent)
			node->exit_code = ft_exec_recursion(node->left, data, NULL);
		else
		{
			node->exit_code = 0;
			if (!ft_check_operator(parent->exit_code, parent->elems->content))
				node->exit_code = ft_exec_recursion(node->left, data, NULL);
		}
		if (node->exit_code != 0)
			node->left = NULL;
		if (node->right->is_micro == node->is_micro && node->right->type == 1)
			node->exit_code = ft_exec_recursion(node->right, data, node);
		else if (!ft_check_operator(node->exit_code, node->elems->content))
			node->exit_code = ft_exec_recursion(node->right, data, node);
		if (node->exit_code != 0)
			node->right = NULL;
	}
	else
		return (ft_exec_command(node, data));
	return (node->exit_code);
}
