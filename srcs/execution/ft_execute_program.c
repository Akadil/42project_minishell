/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_program.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:48:10 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/30 16:37:57 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_execute_program.h"
#include "ft_error.h"

/**
 * @brief       I have to think of exit and free strategy
 * 
 * @param cmd 
 * @param node 
 * @param env 
 */
int    ft_execute_program(t_cmd *cmd, t_list *env, t_node *node)
{
    char    *path;
    char    **params;

    (void)node;
    path = ft_find_path(cmd->params->content, env);
    if (!path)
        return (-1);
    params = ft_construct_command(cmd->params);
    if (!params)
        return (free (path), -1);
    execve(path, params, NULL);
    free (path);
    free (params);
    ft_error();
    return (-1);
}