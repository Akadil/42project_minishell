/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_program.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:48:10 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/26 12:57:34 by akalimol         ###   ########.fr       */
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
void    ft_execute_program(t_cmd *cmd, t_node *node, t_list *env)
{
    char    *path;
    char    **params;

    path = ft_find_path(env, cmd->params->content);
    params = ft_construct_params(cmd->params);
    execve(path, params, NULL);
}