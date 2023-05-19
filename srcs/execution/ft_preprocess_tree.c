/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess_tree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:43:11 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/19 17:26:18 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_data.h"
#include "libft.h"
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
        return (i_token);
    }
    return (NULL);
}

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

t_list  *ft_lstfirst(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}



void    ft_preprocess_tree(t_node *node)
{
    if (node->left)
    {
        ft_preprocess_tree(node->left);
        ft_preprocess_tree(node->right);
    }
    else
    {
        ft_preprocess_node(node);
    }
}