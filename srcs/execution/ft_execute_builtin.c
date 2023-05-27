/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_builtin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:58:20 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/26 13:03:55 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_data.h"
#include "struct_list.h"
#include "libft.h"

void    ft_execute_builtin(t_cmd *cmd, t_data *data)
{
    if (ft_strcmp((char *)cmd->params->content, "cd") == 0)
        ft_execute_cd(cmd, data);
    else if (ft_strcmp((char *)cmd->params->content, "pwd") == 0)
        ft_execute_pwd(cmd, data);
    else if (ft_strcmp((char *)cmd->params->content, "echo") == 0)
        ft_execute_echo(cmd, data);
    else if (ft_strcmp((char *)cmd->params->content, "export") == 0)
        ft_execute_export(cmd, data);
    else if (ft_strcmp((char *)cmd->params->content, "unset") == 0)
        ft_execute_unset(cmd, data);
    else if (ft_strcmp((char *)cmd->params->content, "env") == 0)
        ft_execute_env(cmd, data);
    else if (ft_strcmp((char *)cmd->params->content, "exit") == 0)
        ft_execute_exit(cmd, data);
}