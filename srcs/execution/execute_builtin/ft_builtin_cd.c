/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:07:09 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/28 23:50:43 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_list.h"
#include "ft_error.h"
#include "libft.h"

char    *ft_find_home(t_list *env);

/*
    Description:    cd command
    Test:           in progress 

    Input:  data - is data
            i_cmd - is cmd index
    output: void

    input cases:
        1. Doesn't consider bad inputs

    1. add env to paraleters
    2. 
*/
int    ft_buildin_cd(t_list *params, t_list *env)
{
    int		count;
    char    *str;

    count = ft_lstsize(params);
    if (count == 0)
    {
        str = ft_find_home(env);
        if (!str)
            return (ft_merror("Bash: cd: HOME not set", NULL), -1);
        chdir(str);
    }
    else if (count > 1)
        return (ft_merror("Bash: cd: Too many arguments", NULL), -1);
    else
        chdir((char *)params->content);
    return (0);
}

char    *ft_find_home(t_list *env)
{
    while (env)
    {
        if (ft_strncmp((char *)env->content, "HOME=", 5))
            return (ft_strchar((char *)env->content + 5));
        env = env->next;
    }
    return (NULL);
}