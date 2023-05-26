/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:07:09 by akalimol          #+#    #+#             */
/*   Updated: 2023/04/26 16:00:46 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_data.h"
#include "ft_error.h"

int ft_find_params(t_data *data, int i_cmd);
char    *ft_find_home(t_data *data);

/*
    Description:    cd command
    Test:           in progress 

    Input:  data - is data
            i_cmd - is cmd index
    output: void

    input cases:
        1. Doesn't consider bad inputs

    
*/
void    ft_buildin_cd(t_data *data, int i_cmd)
{
    int		num_param;
    char    *str;

    num_param = ft_find_params(data, i_cmd);
    if (num_param == 0)
    {
        str = ft_find_home(data);
        if (!str)
            ft_merror("Bash: cd: HOME not set", NULL);
        chdir(str);
    }
    else if (num_param > 1)
        ft_merror("Bash: cd: HOME not set", NULL);
    else
        chdir(data->cmds[i_cmd].params->str);
}

int ft_find_params(t_data *data, int i_cmd)
{
    int         count;
    t_list_alt  *temp;

    temp = data->cmds[i_cmd].params;
    count = 0;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    return (count);
}

char    *ft_find_home(t_data *data)
{
    t_env   *temp;

    temp = data->env;
    while (temp)
    {
        if (ft_strncmp(temp->str, "HOME=", 5))
            return (ft_strchar(temp->str + 5));
        temp = temp->next;
    }
    return (NULL);
}