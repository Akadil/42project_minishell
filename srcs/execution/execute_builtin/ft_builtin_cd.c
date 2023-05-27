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

    1. add env to paraleters
    2. 
*/
void    ft_buildin_cd(t_list *params, t_list *env)
{
    int		count;
    char    *str;

    count = ft_lstsize(params);
    if (size == 0)
    {
        str = ft_find_home(env);
        if (!str)
            ft_merror("Bash: cd: HOME not set", NULL);
        chdir(str);
    }
    else if (size > 1)
        ft_merror("Bash: cd: Too many arguments", NULL);
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