/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess_tree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:43:11 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/20 17:08:37 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_data.h"
#include "libft.h"
#include <stdio.h>

int    ft_preprocess_node(t_node *node);

int    ft_preprocess_tree(t_node *node)
{
    int res;

    res = 1;
    if (node->left)
    {
        if (ft_preprocess_tree(node->left) == -1)
            return (-1);
        if (ft_preprocess_tree(node->right) == -1)
            return (-1);
    }
    else
        if (ft_preprocess_node(node) == 0)
            return (-1);
    return (0);
}