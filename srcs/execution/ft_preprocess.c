/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:43:11 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/18 20:53:19 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "libft.h"
#include <stdio.h>

void    ft_preprocess(t_node *node)
{
    t_list  *token;
    t_list  *temp;

    if (node->left)
    {
        ft_preprocess(node->left);
        ft_preprocess(node->right);
    }
    else
    {
        token = node->elems;
        while (token)
        {
            if (6 <= token->type && token->type <= 9) 
            {
                free(token->content);
                token->content = token->next->content;
                temp = token->next->next;
                free (token->next);
                token->next = temp;
                if (temp)
                    temp->prev = token;
                ft_lstadd_back(&node->redirections, temp);
            }
            token = token->next;
        }
    }
}