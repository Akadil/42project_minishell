/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_struct_comparison.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:00:20 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/17 13:10:01 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
    Can I compare for equalness two structs?

    Result:     Yes, I can 

    Checker:
        cc -I includes -Wall -Werror -Wextra tests/hypothesis/test_struct_comparison.c -Llibft -lft && ./a.out && rm a.out
*/

int main(void)
{
    t_list  *node;
    t_list  *middle;

    node = NULL;
    ft_lstadd_back(&node, ft_lstnew("1", 0));
    ft_lstadd_back(&node, ft_lstnew("2", 0));
    ft_lstadd_back(&node, ft_lstnew("3", 0));

    middle = ft_lstnew("4", 0);
    ft_lstadd_back(&node, middle);
    ft_lstadd_back(&node, ft_lstnew("5", 0));
    
    while(node)
    {
        if (ft_strcmp((char *)node->content, "4") == 0)
        {
            if (node == middle)
                printf("I was here\n");
            else
                printf("I wasn't here :(\n");
        }
        node = node->next;
    }
    return (0);
}