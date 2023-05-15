/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:42:20 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/15 16:08:05 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

/*
    What have to be checked:

        > The quotes was already checked 
        
        1. After redirection should be filename
        2. () this shouldn't be a case
        3. Parenthesis should have its pair
        4. After and before the parenthesis, there should be only &&, ||, or |
        5. 
*/

void    ft_check_tokens(t_list  *head)
{
    while (head)
    {
        head = head->next;
    }
}