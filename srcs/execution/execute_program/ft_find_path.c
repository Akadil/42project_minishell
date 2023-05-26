/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_program_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:56:26 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/26 12:51:29 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_list.h"
#include "struct_data.h"
#include "libft.h"
#include "ft_error.h"
#include <stdio.h>

char    *ft_find_path(char *cmd, t_list *env)
{
    char    *str;
    char    **paths;
    int     i;

    while (env)
    {
        str = (char *)env->content;
        if (ft_strncmp("PATH", str, 4) == 0 && str[4] == '=')
            break;
        env = env->next;
    }
    if (!env)
        return (NULL);
    paths = ft_split(str, ':');
    if (!paths)
        return (NULL);
    i = 0;
    while (paths[i])
    {
        str = ft_strjoin(paths[i], cmd);
        if (!str)
        {
            ft_clean_darray(paths);
            ft_error();
            return (NULL);
        }
        if (access(str, X_OK) == 0)
            return (str);   // Free the string first
        if (errno != 2)
            ft_perror(cmd);
        i++;    
    }
    if (cmd[0] == '\\')
		ft_perror(cmd);
	else
		ft_perror(cmd);
    ft_clean_darray(paths);
    return (NULL);
}