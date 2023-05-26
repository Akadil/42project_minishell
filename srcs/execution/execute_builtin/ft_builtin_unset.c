/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_unset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:51:00 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/26 13:13:25 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_list.h"
#include "libft.h"
#include <stdio.h>

/*
    Description:    Buildin for unset command

    Idea:           Go through env variables. For each variabele, go through 
                    each value of token. If similarity found, delete env var
    
*/
void    ft_buildin_unset(t_list **env, char *cmd)
{
    t_list  *token;

    token = *env;
    while (token)
    {
        if (ft_strcmp((char *)token->content, cmd) == 0)
            break;
        token = token->next;
    }
    if (!token)
        return ;
    ft_lstremove(env, token, NULL);
}
