/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akadilkalimoldayev <akadilkalimoldayev@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:06:58 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/27 21:11:24 by akadilkalim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_data.h"
#include <stdio.h>

typedef struct s_list
{
    char                *content;
    int                 type;
    struct s_list       *next;
}                       t_list;

typedef struct s_data2
{
    t_list  *env;
}   t_data2;

void    ft_init_data(int argc, char **argv, char **env, t_data2 *data)
{
    ft_init_env(&data->env, env);
}

void    ft_init_env(t_list **data, char **env)
{
    t_list  *node;
    t_list  *temp;
    int i;

    i = 0;
    while (env[i])
    {
        temp = (t_list *)malloc(sizeof(t_list));
        if (!temp)
            printf ("Error! free all previous env t_lists");
        temp->content = env[i];
        temp->type = 0;
        temp->next = NULL;
        if (i == 0)
        {
            *data = temp;
            node = temp;
        }
        else
        {
            node->next = temp;
            node = node->next;
        }
        i++;
    }
}