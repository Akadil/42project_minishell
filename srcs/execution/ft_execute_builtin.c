/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_builtin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:58:20 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/29 00:04:43 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_execute_builtin.h"

int    ft_execute_builtin(t_cmd *cmd, t_list **env, t_node *node)
{
    int result;

    result = 0;
    if (ft_strcmp((char *)cmd->params->content, "cd") == 0)
        result = ft_execute_cd(cmd->params, *env);
    else if (ft_strcmp((char *)cmd->params->content, "pwd") == 0)
        ft_execute_pwd();
    else if (ft_strcmp((char *)cmd->params->content, "echo") == 0)
        ft_execute_echo(cmd->params->next);
    else if (ft_strcmp((char *)cmd->params->content, "export") == 0)
        result = ft_execute_export((char *)cmd->params->next->content, env);
    else if (ft_strcmp((char *)cmd->params->content, "unset") == 0)
        ft_execute_unset(env, (char *)cmd->params->next->content);
    else if (ft_strcmp((char *)cmd->params->content, "env") == 0)
        ft_execute_env(*env);
    else if (ft_strcmp((char *)cmd->params->content, "exit") == 0)
        result = ft_execute_exit(env, node, (char *)cmd->params->next->content);
    return (result);
}