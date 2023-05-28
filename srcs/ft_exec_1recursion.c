/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_1recursion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:04:54 by akadilkalim       #+#    #+#             */
/*   Updated: 2023/05/28 21:54:52 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_exec_recursion.h"

void    ft_execution(t_data *data, t_node *node)
{
    if (ft_preprocess(node) == -1)
    {
        ft_clean_tree(data->node);
        return ;
    }
    data->exit_code = ft_exec_recursion(node, &data->env, NULL);
}

int    ft_exec_recursion(t_node *node, t_list **env, t_node *parent)
{
    if (node->type == 1)
    {
        if (!parent)
            node->exit_code = ft_exec_recursion(node->left, env, NULL);
        else
        {
            node->exit_code = 0;
            if (!ft_check_operator(parent->exit_code, parent->elems->content))
                node->exit_code = ft_exec_recursion(node->left, env, NULL);
        }
        if (node->right->is_micro == node->is_micro && node->right->type == 1)
            node->exit_code = ft_exec_recursion(node->right, env, node);
        else
            if (!ft_check_operator(node->exit_code, node->elems->content))
                node->exit_code = ft_exec_recursion(node->right, env, node);
    }
    else
        return (ft_exec_command(node, env));
    return (node->exit_code);
}
