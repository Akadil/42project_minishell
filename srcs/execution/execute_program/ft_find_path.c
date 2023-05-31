/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:56:26 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/31 21:54:47 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_find_path.h"

int	ft_find_path2(char *cmd, char **place);
int	ft_free_find_path(char **paths, char *cmd, int exit_code);

int	ft_find_path(char *cmd, t_list *env, char **place)
{
	char	*str;
	char	**paths;
	int		i;

	if (cmd && ft_strchr(cmd, '/'))
		return (ft_find_path2(cmd, place));
	str = ft_find_all_paths(env);
	if (!str)
		return (ft_merror("bash: %s: command not found\n", cmd), 127);
	paths = ft_split_alt2(str, ':');
	if (!paths)
		return (ft_merror("bash: %s: command not found\n", cmd), 255);
	i = -1;
	while (paths[++i])
	{
		str = ft_strjoin(paths[i], cmd);
		if (!str)
			return (ft_free_find_path(paths, cmd, 255));
		if (access(str, X_OK) == 0)
			return (ft_clean_darray(paths), (*place = str), 0);
		free(str);
		if (errno != 2)
			return (ft_perror(cmd), ft_clean_darray(paths), 126);
	}
	return (ft_free_find_path(paths, cmd, 127));
}

int	ft_free_find_path(char **paths, char *cmd, int exit_code)
{
	ft_clean_darray(paths);
	ft_merror("bash: %s: command not found\n", cmd);
	return (exit_code);
}

int	ft_find_path2(char *cmd, char **place)
{
	if (access(cmd, X_OK) == 0)
		return ((*place = cmd), 0);
	ft_perror(cmd);
	if (errno == 2)
		return (127);
	else
		return (126);
}
