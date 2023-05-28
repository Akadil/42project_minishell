/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_program.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:48:10 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/28 18:52:38 by akalimol         ###   ########.fr       */
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
void    ft_execute_program(t_cmd *cmd, t_list *env, t_node *node)
{
    char    *path;
    char    **params;

    (void)node;
    path = ft_find_path(cmd->params->content, env);
    params = ft_construct_command(cmd->params);
    if (execve(path, params, NULL) == -1)
        ft_error_exit(-1);
}