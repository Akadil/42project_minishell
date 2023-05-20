/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstretrieve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:17:45 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/20 14:51:50 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_list.h"
#include <stdio.h>

t_list  *ft_lstretrieve(t_list **lst, t_list *node)
{
    t_list  *i_token;

    i_token = *lst;
    while (i_token && i_token != node)
        i_token = i_token->next;
    if (i_token)
    {
        if (i_token->prev)
            i_token->prev->next = i_token->next;
        else
            *lst = i_token->next;
        if (i_token->next)
            i_token->next->prev = i_token->prev;
        i_token->next = NULL;
        i_token->prev = NULL;
        return (i_token);
    }
    return (NULL);
}