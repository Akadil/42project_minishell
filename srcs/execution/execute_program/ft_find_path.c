/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:56:26 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/30 16:38:57 by akalimol         ###   ########.fr       */
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
        return (ft_merror("bash: %s: No such file or directory", cmd), NULL);
    paths = ft_split_alt2(str, ':');
    if (!paths)
        return (ft_error(), NULL);
    i = 0;
    while (paths[i])
    {
        str = ft_strjoin(paths[i], cmd);
        if (!str)
            return (ft_clean_darray(paths), ft_error(), NULL);
        if (access(str, X_OK) == 0)
            return (ft_clean_darray(paths), str);   // Free the string first
        free (str);
        if (errno != 2)
            return (ft_perror(cmd), ft_clean_darray(paths), NULL);
        i++;    
    }
    return (ft_clean_darray(paths), ft_perror(cmd), NULL);
}