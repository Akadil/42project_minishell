/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:56:26 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/27 17:39:00 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_find_path.h"

char    *ft_find_path(char *cmd, t_list *env)
{
    char    *str;
    char    **paths;
    int     i;

    str = ft_find_all_paths(env);
    if (!str)
        return (NULL);
    paths = ft_split(str, ':');
    if (!paths)
        return (NULL);
    i = 0;
    while (paths[i])
    {
        str = ft_strjoin(paths[i], cmd);
        if (!str)
            return (ft_clean_darray(paths), ft_error(), NULL);
        if (access(str, X_OK) == 0)
            return (str);   // Free the string first
        if (errno != 2)
            ft_perror(cmd);
        i++;    
    }
    return (ft_clean_darray(paths), ft_perror(cmd), NULL);
}