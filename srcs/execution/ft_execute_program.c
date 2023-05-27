/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_program.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:48:10 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/27 18:36:49 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_data.h"
#include "libft.h"

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

    path = ft_find_path(env, cmd->params->content);
    if (!path)
        return ;
    params = ft_construct_params(cmd->params);
    if (!params)
        return ;
    execve(path, params, NULL);
}