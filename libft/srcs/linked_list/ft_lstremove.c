/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:16:53 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/20 14:22:07 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_list.h"
#include "libft.h"

int ft_lstremove(t_list **lst, t_list *node, void (*del)(void*))
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
        ft_lstdelone(i_token, del);
        return (1);
    }
    return (0);
}