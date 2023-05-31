/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_program.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:48:10 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/31 18:34:39 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "includes/ft_execute_program.h"

/**
 * @brief       I have to think of exit and free strategy
 * 
 * @param cmd 
 * @param node 
 * @param env 
 */
int	ft_execute_program(t_cmd *cmd, t_list *env, t_node *node)
{
	char	*path;
	char	**params;
	int		code;

	(void)node;
	path = NULL;
	if (!ft_strcmp((char *)cmd->params->content, "."))
		return (ft_merror("bash: .: filename argument required\n", NULL), -1);
	code = ft_find_path(cmd->params->content, env, &path);
	if (!path)
		return (code);
	params = ft_construct_command(cmd->params);
	if (!params)
		return (free(path), 255);
	execve(path, params, ft_construct_command(env));
	free(params);
	free(path);
	path = (char *)cmd->params->content;
	if (ft_strchr(path, '/'))
		ft_merror("bash: %s: no such file or directory\n", path);
	else
		ft_merror("bash: %s: command not found\n", path);
	return (code);
}
