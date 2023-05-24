/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_open_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 05:14:50 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/24 05:19:17 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_list.h"
#include "libft.h"
#include <stdio.h>

int ft_open_heredocs(t_list *head);

int main(void)
{
    t_list  *head;

    head = NULL;
    ft_lstadd_back(&head, ft_lstnew("EOF", 8));
    ft_lstadd_back(&head, ft_lstnew("Finir", 8));

    ft_open_heredocs(head);

    return (0);
}