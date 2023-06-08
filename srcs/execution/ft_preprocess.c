/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akadilkalimoldayev <akadilkalimoldayev@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:31:09 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/08 18:20:13 by akadilkalim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "preprocess/includes/ft_preprocess.h"

/**
 * @brief      Preprocess the command. Before, I had a node with all tokens
 *             in one place. Now they are redistributed
 * 
 *                            typedef struct s_cmd
 *                            {
 *                                t_list  *params;
 *                                t_list  *redir;
 *                                int     in_fd;
 *                                int     out_fd;
 *                            }           t_cmd;
 * 
 * @param node      head node
 * @return int      0 if everything is ok, -1  if malloc fails
 * 

	* ------------------------------------------------------------------------------
 * 
 * @def     ft_init_cmds()      - each command initialization
 * @def     ft_preprocess_cmd() - preprocess each command 
 */
int	ft_preprocess(t_node *node)
{
	if (node->left)
	{
		if (ft_preprocess(node->left) == -1)
			return (-1);
		if (ft_preprocess(node->right) == -1)
			return (-1);
	}
	else if (ft_preprocess_node(node) == -1)
		return (-1);
	return (0);
}

int	ft_preprocess_node(t_node *node)
{
	node->count_cmd = ft_count_cmds(node->elems);
	node->cmds = (t_cmd *)malloc(sizeof(t_cmd) * node->count_cmd);
	if (!node->cmds)
		return (ft_error(), -1);
	ft_init_cmds(node->cmds, node->count_cmd);
	ft_preprocess_cmd(node->cmds, node->elems);
	node->elems = NULL;
	return (0);
}
