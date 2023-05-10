/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_envvar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akadilkalimoldayev <akadilkalimoldayev@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:05:34 by akadilkalim       #+#    #+#             */
/*   Updated: 2023/05/09 18:48:47 by akadilkalim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void    ft_free(void *content)
{
    (void)content;
    return ;
}

void    ft_error(t_list  **data)
{
    ft_lstclear(data, &ft_free);
}

/*
    Initializee the environment variables
        list->content   - full string (ex. "USER=akalimol")
        list->type      - default or not
*/
void    ft_init_env(t_list **data, char **env)
{
    t_list  *node;
    int i;

    i = 0;
    while (env[i])
    {
        node = ft_lstnew(env[i], 0);
        if (!node)
            printf ("Error! free all previous env t_lists");
        ft_lstadd_back(data, node);
        i++;
    }
}

