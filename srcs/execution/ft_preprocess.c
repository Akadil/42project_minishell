/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:43:11 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/15 17:46:42 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "libft.h"
#include <stdio.h>

void    ft_preprocess(t_node *node)
{
    t_list  *token;
    t_list  *prev;
    t_list  *temp;

    if (node->left)
    {
        // Operator node
        node->type = 1;
        ft_preprocess(node->left);
        ft_preprocess(node->right);
    }
    else
    {
        // Leaf node
        node->type = 0;
        token = node->elems;
        prev = NULL;
        while (token)
        {
            if (token->type == 6 || token->type == 7 || token->type == 8 || token->type == 9) 
            {
                temp = token;
                token = prev;
                token->next = temp->next;
                temp->next = NULL;
                ft_lstadd_back(&node->redirections, temp);
            }
            prev = token;
            token = token->next;
        }
    }
}