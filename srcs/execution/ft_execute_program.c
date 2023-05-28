/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_program.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akadilkalimoldayev <akadilkalimoldayev@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:48:10 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/28 14:09:43 by akadilkalim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_execute_program.h"

/**
 * @brief       I have to think of exit and free strategy
 * 
 * @param cmd 
 * @param node 
 * @param env 
 */
void    ft_execute_program(t_cmd *cmd, t_list *env, t_node *node)
{
    char    *path;
    char    **params;

    (void)node;
    path = ft_find_path(cmd->params->content, env);
    if (!path)
        return ;
    params = ft_construct_params(cmd->params);
    if (!params)
        return ;
    execve(path, params, NULL);
}