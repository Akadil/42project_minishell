/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akadilkalimoldayev <akadilkalimoldayev@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:32:52 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/28 14:10:57 by akadilkalim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_list.h"
#include "libft.h"
#include <stdio.h>

char    *ft_find_all_paths(t_list *env)
{
    char    *str;

    while (env)
    {
        str = (char *)env->content;
        if (ft_strncmp("PATH", str, 4) == 0 && str[4] == '=')
            break;
        env = env->next;
    }
    if (!env)
        return (NULL);
    return (str + 5);
}