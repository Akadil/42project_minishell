/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:56:26 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/28 18:54:51 by akalimol         ###   ########.fr       */
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
        ft_merror_exit("bash: %s: No such file or directory", cmd, -1);
    paths = ft_split_alt2(str, ':');
    if (!paths)
        ft_error_exit(-1);
    i = 0;
    while (paths[i])
    {
        str = ft_strjoin(paths[i], cmd);
        if (!str)
            return (ft_clean_darray(paths), ft_error_exit(-1), NULL);
        if (access(str, X_OK) == 0)
            return (str);   // Free the string first
        if (errno != 2)
            return (ft_perror_exit(cmd, -1), NULL);
        i++;    
    }
    return (ft_clean_darray(paths), ft_perror_exit(cmd, -1), NULL);
}